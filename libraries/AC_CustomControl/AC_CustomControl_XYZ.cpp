#include "AC_CustomControl_config.h"

// original
/* #if AP_CUSTOMCONTROL_XYZ_ENABLED */
#if defined(AP_CUSTOMCONTROL_XYZ_ENABLED) && AP_CUSTOMCONTROL_XYZ_ENABLED

// WSL_EDIT_MARKER
#include <cmath>

#include "AC_CustomControl_XYZ.h"

#include <GCS_MAVLink/GCS.h>
#include <AP_Logger/LogStructure.h>


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

// initialize in the constructor
AC_CustomControl_XYZ::AC_CustomControl_XYZ(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control,
     AP_MotorsMulticopter*& motors,AC_PosControl*& pos_control,Thrust_Linearization*& thrust_lin, float dt) :
    AC_CustomControl_Backend(frontend, ahrs, att_control, motors,pos_control,thrust_lin, dt)
{
    AP_Param::setup_object_defaults(this, var_info);

    simulink_controller.initialize();
}

// update controller
// return roll, pitch, yaw controller output
Vector3f AC_CustomControl_XYZ::update(void)
{   
    // reset controller based on spool state
    switch (_motors->get_spool_state()) {
        case AP_Motors::SpoolState::SHUT_DOWN:
        case AP_Motors::SpoolState::GROUND_IDLE:
            // We are still at the ground. Reset custom controller to avoid
            // build up, ex: integrator
            reset();
            break;

        case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        case AP_Motors::SpoolState::SPOOLING_UP:
        case AP_Motors::SpoolState::SPOOLING_DOWN:
            // we are off the ground
            break;
    }

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

    float torque_limits_roll = 63;

    float torque_limits_pitch = 63;

    float torque_limits_yaw = 10;

    float u_roll;

    float u_pitch;

    float u_yaw;

    float arg_inverse_Ix_hat = 0.0f;

    float arg_inverse_Iy_hat = 0.0f;

    float arg_inverse_Iz_hat = 0.0f;



    // create a quaternion object NED
    Quaternion q_b2ned;
    // get current quaternions orientation in NED
    _ahrs->get_quat_body_to_ned(q_b2ned);

    // quaternion object NWU
    Quaternion q_ned2nwu;
    
    q_ned2nwu.from_axis_angle(Vector3f(1,0,0), M_PI);

    Quaternion q_b2nwu = q_ned2nwu * q_b2ned; // quaternion orientation in NWU

    q_b2nwu.to_euler(arg_phi, arg_theta, arg_psi); // Convert Quaternion into Euler

    Quaternion q_tgt_b2ned = _att_control->get_attitude_target_quat();

    Quaternion q_tgt_b2nwu = q_ned2nwu * q_tgt_b2ned;

    q_tgt_b2nwu.to_euler(arg_phi_des, arg_theta_des, arg_psi_des);

    Vector3f gyro = _ahrs->get_gyro_latest();


    // TEMPORARY DIAGNOSTIC LOGGING
    static int log_counter = 0;

    float test_roll  = _ahrs->roll;
    float test_pitch = _ahrs->pitch;
    float test_yaw   = _ahrs->yaw;

    if (++log_counter >= 400) {
        log_counter = 0;
        GCS_SEND_TEXT(MAV_SEVERITY_INFO, 
            "AHRS: R=%.3f P=%.3f Y=%.3f",
            test_roll, test_pitch, test_yaw);
        GCS_SEND_TEXT(MAV_SEVERITY_INFO,
            "Quat: R=%.3f P=%.3f Y=%.3f",
            arg_phi, arg_theta, arg_psi);
    }
    // END DIAGNOSTIC

    arg_p = gyro.x;
    arg_q = -gyro.y;
    arg_r = -gyro.z;




    // // basic normalization
    // torque_limits_roll  = 63.0f;
    // torque_limits_pitch = 63.0f;

    torque_limits_roll  = 250;
    torque_limits_pitch = 250;

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
    &arg_inverse_Iz_hat);

    u_roll = arg_tau_x/torque_limits_roll;

    u_pitch = arg_tau_y/torque_limits_pitch;

    u_yaw = arg_tau_z/torque_limits_yaw;

    float e_phi = arg_phi_des - arg_phi;
    float e_theta = arg_theta_des - arg_theta;
    float e_psi = arg_psi_des - arg_psi;

    u_roll = 1*u_roll;    
    u_pitch = -1*u_pitch;
    u_yaw = -1*u_yaw;
    
    u_roll  = constrain_float(u_roll,  -1.0f, 1.0f);
    u_pitch = constrain_float(u_pitch, -1.0f, 1.0f);
    u_yaw   = constrain_float(u_yaw,   -1.0f, 1.0f);

    #if HAL_LOGGING_ENABLED
    AP::logger().Write_HRLS(e_phi,e_theta,e_psi,arg_p,arg_q,arg_r,arg_tau_x,arg_tau_y,arg_tau_z);
    AP::logger().Write_ORLS(arg_inverse_Ix_hat, arg_inverse_Iy_hat, arg_inverse_Iz_hat);
    
    #endif

   
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "XYZ custom controller working");




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
    GCS_SEND_TEXT(MAV_SEVERITY_INFO, "CC: backend reset on enable");
}

#endif  // AP_CUSTOMCONTROL_XYZ_ENABLED

