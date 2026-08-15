#include "AC_CustomControl_config.h"

// original
/* #if AP_CUSTOMCONTROL_XYZ_ENABLED */
#if defined(AP_CUSTOMCONTROL_XYZ_ENABLED) && AP_CUSTOMCONTROL_XYZ_ENABLED

// WSL_EDIT_MARKER
#include <cmath>

#include "AC_CustomControl_XYZ.h"

#include <GCS_MAVLink/GCS.h>
#include <AP_Logger/LogStructure.h>
#include <SRV_Channel/SRV_Channel.h>



// table of user settable parameters
const AP_Param::GroupInfo AC_CustomControl_XYZ::var_info[] = {
    // @Param: PARAM1
    // @DisplayName: XYZ param1
    // @Description: Dummy parameter for XYZ custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM1", 1, AC_CustomControl_XYZ, param1, 0.0f),

    // @Param: PARAM2
    // @DisplayName: XYZ param2
    // @Description: Dummy parameter for XYZ custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM2", 2, AC_CustomControl_XYZ, param2, 0.0f),

    // @Param: PARAM3
    // @DisplayName: XYZ param3
    // @Description: Dummy parameter for XYZ custom controller backend
    // @User: Advanced
    AP_GROUPINFO("PARAM3", 3, AC_CustomControl_XYZ, param3, 0.0f),

    AP_GROUPEND
};

// Octo-X motor geometry, from libraries/AP_Motors/AP_MotorsMatrix.cpp, setup_octa_matrix(),
// case MOTOR_FRAME_TYPE_X. These are the raw per-motor direction cosines
// (cos(angle+90) for roll, cos(angle) for pitch, +-1 for yaw) used for physical torque
// reconstruction - NOT the same as AP_MotorsMatrix::get_roll_factor()/get_pitch_factor(),
// which return those same values renormalized to +-0.5 for use in the internal PWM mixer.
// Index 0 = MOT_1 (_pwm_motor1) ... index 7 = MOT_8 (_pwm_motor8).
static constexpr float ROLL_FACTOR[8]  = { -0.3827f, +0.3827f, -0.9239f, -0.3827f,
                                            +0.3827f, +0.9239f, +0.9239f, -0.9239f };
static constexpr float PITCH_FACTOR[8] = { +0.9239f, -0.9239f, +0.3827f, -0.9239f,
                                            +0.9239f, -0.3827f, +0.3827f, -0.3827f };
static constexpr float YAW_FACTOR[8]   = { -1.0f, -1.0f, +1.0f, +1.0f,
                                            +1.0f, +1.0f, -1.0f, -1.0f };

// Bench-fit motor model (U7 V2 490KV, 16x5.5 prop, 6S battery)
static constexpr float OMEGA_A =  -991.705f;
static constexpr float OMEGA_B =  2044.823f;
static constexpr float OMEGA_C =  -209.029f;
static constexpr float K_T     = 5.80660e-5f;   // N / (rad/s)^2
static constexpr float C_Q     = 0.019544f;     // Q/T ratio, m
static constexpr float ARM_L   = 0.6f;          // m, CG to motor

// initialize in the constructor
AC_CustomControl_XYZ::AC_CustomControl_XYZ(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control,
     AP_MotorsMulticopter*& motors,AC_PosControl*& pos_control,Thrust_Linearization*& thrust_lin, float dt) :
    AC_CustomControl_Backend(frontend, ahrs, att_control, motors,pos_control,thrust_lin, dt)
{
    AP_Param::setup_object_defaults(this, var_info);

    simulink_controller.initialize();
}

// read back the last PWM actually written to each ESC output.
// covers quadcopter-X (motor1..motor4) and octocopter-X (motor1..motor8) frames;
// motors not fitted for the current frame class are left at 0.
void AC_CustomControl_XYZ::update_motor_pwms(void)
{
    const uint32_t motor_mask = _motors->get_motor_mask();

    float *const pwm_motor[8] = {
        &_pwm_motor1, &_pwm_motor2, &_pwm_motor3, &_pwm_motor4,
        &_pwm_motor5, &_pwm_motor6, &_pwm_motor7, &_pwm_motor8,
    };

    for (uint8_t i = AP_MOTORS_MOT_1; i <= AP_MOTORS_MOT_8; i++) {
        if (!((motor_mask >> i) & 1U)) {
            *pwm_motor[i] = 0.0f;
            continue;
        }
        const SRV_Channel::Function function = SRV_Channels::get_motor_function(i);
        uint16_t pwm;
        if (SRV_Channels::get_output_pwm(function, pwm)) {
            *pwm_motor[i] = static_cast<float>(pwm);
        }
    }
}

// convert a single motor's commanded PWM into thrust, N, via the bench-fit
// quadratic PWM->omega map and the K_T thrust coefficient.
float AC_CustomControl_XYZ::pwm_to_thrust(float pwm_us)
{
    float delta = (pwm_us - 1000.0f) / 1000.0f;
    delta = constrain_float(delta, 0.0f, 1.0f);
    float omega = OMEGA_A*delta*delta + OMEGA_B*delta + OMEGA_C;
    if (omega < 0.0f) {
        omega = 0.0f;
    }
    return K_T * omega * omega;
}

// reconstruct the real per-axis torque and total thrust the motors just produced,
// from this cycle's _pwm_motor1.._pwm_motor8 (see update_motor_pwms()).
void AC_CustomControl_XYZ::compute_real_torques(void)
{
    const float pwm[8] = { _pwm_motor1, _pwm_motor2, _pwm_motor3, _pwm_motor4,
                            _pwm_motor5, _pwm_motor6, _pwm_motor7, _pwm_motor8 };
    float F_total = 0.0f, tau_x = 0.0f, tau_y = 0.0f, tau_z = 0.0f;

    for (uint8_t i = 0; i < 8; i++) {
        if (pwm[i] < 1000.0f) {
            // motor not fitted for this frame (quad-X leaves motor5..8 at 0)
            continue;
        }
        const float T_i = pwm_to_thrust(pwm[i]);
        const float Q_i = C_Q * T_i;
        F_total += T_i;
        tau_x   += ARM_L * T_i * ROLL_FACTOR[i];
        tau_y   += ARM_L * T_i * PITCH_FACTOR[i];
        tau_z   += Q_i * YAW_FACTOR[i];
    }
    _F_total = F_total;
    _tau_x = tau_x;
    _tau_y = tau_y;
    _tau_z = tau_z;
}

// update controller
// return roll, pitch, yaw controller output
Vector3f AC_CustomControl_XYZ::update(void)
{
    // read back the last PWM commanded to each ESC before doing anything else
    update_motor_pwms();
    compute_real_torques();

    _prev_tau_x = _tau_x;
    _prev_tau_y = -_tau_y;
    _prev_tau_z = -_tau_z;

    // reset controller based on spool state
    bool grounded = true;
    switch (_motors->get_spool_state()) {
        case AP_Motors::SpoolState::SHUT_DOWN:
        case AP_Motors::SpoolState::GROUND_IDLE:
            // We are still at the ground. Reset custom controller to avoid
            // build up, ex: integrator. Only do this once on the rising
            // edge into grounded state - reset() also clears the RLS
            // estimator state (inverse_Ix/y/z_hat), so calling it every
            // loop while grounded would continuously wipe the estimator
            // instead of just resetting on activation.
            if (!_was_grounded) {
                reset();
            }
            break;

        case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        case AP_Motors::SpoolState::SPOOLING_UP:
        case AP_Motors::SpoolState::SPOOLING_DOWN:
            // we are off the ground
            grounded = false;
            if (_was_grounded) {
                // one-shot notice: custom controller just started actually
                // driving the vehicle, rather than sitting reset on the ground
                GCS_SEND_TEXT(MAV_SEVERITY_INFO, "XYZ custom controller active");
            }
            break;
    }
    _was_grounded = grounded;

    // '<Root>/phi'
    float arg_phi = 0.0f;

    // '<Root>/theta'
    float arg_theta = 0.0f;

    // '<Root>/psi'
    float arg_psi = 0.0f;

    // '<Root>/q'
    float arg_q = 0.0f;

    // '<Root>/phi_des'
    float arg_phi_des = 0.0f;

    // '<Root>/r'
    float arg_r = 0.0f;

    // '<Root>/theta_des'
    float arg_theta_des = 0.0f;

    // '<Root>/psi_des'
    float arg_psi_des = 0.0f;

    // '<Root>/p'
    float arg_p = 0.0f;

    // '<Root>/tau_y'
    float arg_tau_y = 0.0f;

    // '<Root>/tau_x'
    float arg_tau_x = 0.0f;

    // '<Root>/tau_z'
    float arg_tau_z = 0.0f;

    float torque_limits_roll = 63.9f;

    float torque_limits_pitch = 63.9f;

    float torque_limits_yaw = 3.19f;

    float u_roll;

    float u_pitch;

    float u_yaw;

    float arg_inverse_Ix_hat = 0.0f;

    float arg_inverse_Iy_hat = 0.0f;

    float arg_inverse_Iz_hat = 0.0f;



    // // create a quaternion object NED
    // Quaternion q_b2ned;
    // // get current quaternions orientation in NED
    // _ahrs->get_quat_body_to_ned(q_b2ned);

    // // quaternion object NWU
    // Quaternion q_ned2nwu;
    
    // q_ned2nwu.from_axis_angle(Vector3f(1,0,0), M_PI);

    // Quaternion q_b2nwu = q_ned2nwu * q_b2ned; // quaternion orientation in NWU

    // q_b2nwu.to_euler(arg_phi, arg_theta, arg_psi); // Convert Quaternion into Euler

    // Quaternion q_tgt_b2ned = _att_control->get_attitude_target_quat();

    // Quaternion q_tgt_b2nwu = q_ned2nwu * q_tgt_b2ned;

    // q_tgt_b2nwu.to_euler(arg_phi_des, arg_theta_des, arg_psi_des);

    // Get Euler angles directly from AHRS (in radians, NED convention)
    arg_phi   =  _ahrs->roll;
    arg_theta = -_ahrs->pitch;
    arg_psi   = -_ahrs->yaw;

    // Get desired Euler angles from attitude controller (NED convention)
    float tgt_roll, tgt_pitch, tgt_yaw;
    _att_control->get_attitude_target_quat().to_euler(tgt_roll, tgt_pitch, tgt_yaw);
    arg_phi_des   =  tgt_roll;
    arg_theta_des = -tgt_pitch;
    arg_psi_des   = -tgt_yaw;

    Vector3f gyro = _ahrs->get_gyro_latest();




    arg_p = gyro.x;
    arg_q = -gyro.y;
    arg_r = -gyro.z;




    // // basic normalization
    // torque_limits_roll  = 63.0f;
    // torque_limits_pitch = 63.0f;

    torque_limits_roll  = 63.9f;
    torque_limits_pitch = 63.9f;

    // // --- normalization (SAFE) ---
    // bool use_norm = true;
    // float arm_length = 0.6;
  

    // const float mg = 12.175f * 9.81f;

    // float thrust_commanded = _pos_control->get_thrust_commanded();
    // float u_hover = _motors->get_throttle_hover();

    
    // // validate FIRST (before any division / pointer calls)
    // if (!isfinite(thrust_commanded)) {
    //     use_norm = false;
    // }
    // if (!isfinite(u_hover) || u_hover < 0.05f) {
    //     use_norm = false;
    // }

    // if (use_norm) {
    //     // if this thrust is meant to be normalized, clamp it
    //     thrust_commanded = constrain_float(thrust_commanded, 0.0f, 1.0f);

    //     const float T_cmd_N = (thrust_commanded / u_hover) * mg;

    //     const float T_max_norm = _motors->thr_lin.actuator_to_thrust(0.95f);

        

    //     if (!isfinite(T_max_norm)) {
    //         use_norm = false;
    //     } else {
    //         const float T_max_N = (T_max_norm / u_hover) * mg;
    //         const float margin_N = T_max_N - T_cmd_N;

    //         if (!isfinite(margin_N) || margin_N <= 0.0f) {
    //             use_norm = false;
    //         } else {
    //             const float per_motor = margin_N / 8.0f;

    //             const float geom =
    //                 2.0f * arm_length * sinf(22.5f * (M_PI / 180.0f)) +
    //                 2.0f * arm_length * sinf(67.5f * (M_PI / 180.0f));

    //             torque_limits_roll  = MAX(per_motor * geom,  0.01f);
    //             torque_limits_pitch = MAX(per_motor * geom, 0.01f);

    //         }
    //     }
    // }

    // if (!use_norm) {
    //     torque_limits_roll  = 63.0f;
    //     torque_limits_pitch = 63.0f;
    // }
    // GCS_SEND_TEXT(MAV_SEVERITY_INFO, "use_norm %d",use_norm);

    // // --- end normalization ---





// // Conversion factor
//     const float DEG2RAD = M_PI / 180.0f;

//     // Convert actual angles
//     arg_phi   *= DEG2RAD;
//     arg_theta *= DEG2RAD;
//     arg_psi   *= DEG2RAD;

//     // Convert desired angles
//     arg_phi_des   *= DEG2RAD;
//     arg_theta_des *= DEG2RAD;
//     arg_psi_des   *= DEG2RAD;

    // Now wrap (in radians)
    arg_phi   = wrap_PI(arg_phi);
    arg_theta = wrap_PI(arg_theta);
    arg_psi   = wrap_PI(arg_psi);

    arg_phi_des   = wrap_PI(arg_phi_des);
    arg_theta_des = wrap_PI(arg_theta_des);
    arg_psi_des   = wrap_PI(arg_psi_des);




    simulink_controller.step(&arg_tau_y, &arg_tau_x, &arg_tau_z,
    &arg_r, &arg_psi_des, &arg_theta, &arg_q, &arg_theta_des, &arg_p, &arg_phi,
    &arg_psi, &arg_phi_des, &arg_inverse_Ix_hat, &arg_inverse_Iy_hat,
    &arg_inverse_Iz_hat, &_prev_tau_x, &_prev_tau_y, &_prev_tau_z);

    // don't let a non-finite output on any single axis reach the motors
    if (!isfinite(arg_tau_x)) {
        arg_tau_x = 0.0f;
        GCS_SEND_TEXT(MAV_SEVERITY_CRITICAL, "CC: XYZ tau_x invalid, zeroing");
    }
    if (!isfinite(arg_tau_y)) {
        arg_tau_y = 0.0f;
        GCS_SEND_TEXT(MAV_SEVERITY_CRITICAL, "CC: XYZ tau_y invalid, zeroing");
    }
    if (!isfinite(arg_tau_z)) {
        arg_tau_z = 0.0f;
        GCS_SEND_TEXT(MAV_SEVERITY_CRITICAL, "CC: XYZ tau_z invalid, zeroing");
    }

    // _prev_tau_x/y/z are no longer overwritten here: they are fed to the RLS
    // estimator as "real tau" this cycle (see top of update()), reconstructed
    // from the PWM actually sent to the ESCs last cycle, not the controller's
    // own commanded output.

    u_roll = arg_tau_x/torque_limits_roll;

    u_pitch = arg_tau_y/torque_limits_pitch;

    u_yaw = arg_tau_z/torque_limits_yaw;

    float e_phi = arg_phi_des - arg_phi;
    float e_theta = arg_theta_des - arg_theta;
    float e_psi = arg_psi_des - arg_psi;

    u_roll = u_roll;    
    u_pitch = -1*u_pitch;
    u_yaw = -1*u_yaw;
    
    u_roll  = constrain_float(u_roll,  -1.0f, 1.0f);
    u_pitch = constrain_float(u_pitch, -1.0f, 1.0f);
    u_yaw   = constrain_float(u_yaw,   -1.0f, 1.0f);


    #if HAL_LOGGING_ENABLED
    AP::logger().Write_HRLS(e_phi,e_theta,e_psi,arg_p,arg_q,arg_r,arg_tau_x,arg_tau_y,arg_tau_z);
    AP::logger().Write_ORLS(arg_inverse_Ix_hat, arg_inverse_Iy_hat, arg_inverse_Iz_hat);
    AP::logger().Write_RTAU(_tau_x, -_tau_y, -_tau_z, _F_total);
    
    #endif

    // GCS_SEND_TEXT(
    // MAV_SEVERITY_INFO,
    // "XYZ u: R=%.4f P=%.4f Y=%.4f",
    // u_roll,
    // u_pitch,
    // u_yaw
    // );

    // GCS_SEND_TEXT(
    // MAV_SEVERITY_INFO,
    // "Thrust  T=%.4f Max Thrust Tmax = %.4f and uhover = %.4f",
    // thrust_commanded,
    // T_max_norm,
    // u_hover
    // );





  


    // return what arducopter main controller outputted
    return Vector3f(u_roll,u_pitch, u_yaw);
}

// reset controller to avoid build up on the ground
// or to provide bumpless transfer from arducopter main controller
void AC_CustomControl_XYZ::reset(void)
{
    simulink_controller.initialize();
    _prev_tau_x = 0.0;
    _prev_tau_y = 0.0;
    _prev_tau_z = 0.0;
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "CC: backend reset on enable");
}

#endif  // AP_CUSTOMCONTROL_XYZ_ENABLED

