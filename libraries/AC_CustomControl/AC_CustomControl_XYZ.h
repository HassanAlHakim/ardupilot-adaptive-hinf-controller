#pragma once

#include "AC_CustomControl_config.h"

/* #if AP_CUSTOMCONTROL_XYZ_ENABLED */
#if defined(AP_CUSTOMCONTROL_XYZ_ENABLED) && AP_CUSTOMCONTROL_XYZ_ENABLED


#include "AC_CustomControl_Backend.h"
#include <AC_Simulink/octocopter_model_Hinf_RLS_combined.h>

#include <AP_Logger/AP_Logger.h>

#include <AP_Logger/LogStructure.h>



class AC_CustomControl_XYZ : public AC_CustomControl_Backend {
public:
    AC_CustomControl_XYZ(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control, AP_MotorsMulticopter*& motors,AC_PosControl*& pos_control,Thrust_Linearization *& thrust_lin, float dt);


    Vector3f update(void) override;
    void reset(void) override;

    octocopter_model_Hinf_RLS_combined simulink_controller;

    // user settable parameters
    static const struct AP_Param::GroupInfo var_info[];

    // PWM(us) -> per-motor angular velocity omega (rad/s), via the fitted
    // electro-mechanical model of Gauthier et al. (arXiv:2312.09981). Public
    // and static so it can be unit tested directly (see tests/).
    static float pwm_to_omega(float pwm_us, float v_batt);

    // Quad-X (Holybro X500 V2) mixer: 4 per-motor PWMs (us) + battery voltage
    // (V) + thrust coefficient (N/(rad/s)^2) -> total thrust (N) and body
    // torques (N.m). Public and static so it can be unit tested directly
    // without constructing a full AC_CustomControl_XYZ (which needs live
    // AHRS/motors/attitude-control pointers). pwm_us[0..3] = motor1..motor4,
    // ArduPilot's own 1-based numbering (see AP_MotorsMatrix::setup_quad_matrix(),
    // MOTOR_FRAME_TYPE_X).
    static void mix_quad_x(const float pwm_us[4], float v_batt, float k_t,
                            float &F_total, float &tau_x, float &tau_y, float &tau_z);

protected:
    // declare parameters here
    // motor thrust coefficient, N / (rad/s)^2 -- identified from real flight-log
    // hover data on the Gazebo Iris model, see CC_XYZ_KT description. Set via this
    // param rather than editing pwm_to_omega()/mix_quad_x().
    AP_Float k_t;
    AP_Float param2;
    AP_Float param3;

    double _prev_tau_x{0.0};
    double _prev_tau_y{0.0};
    double _prev_tau_z{0.0};

    // true while the vehicle is shut down or at ground idle, used to send a
    // one-shot GCS notice when the custom controller starts actually running
    bool _was_grounded{true};

    // last PWM actually written to each ESC output, read back from SRV_Channels.
    // Named to match ArduPilot's own 1-based motor numbering (AP_MOTORS_MOT_1..8 /
    // SERVOn_FUNCTION "MotorN"), so motorN here is array index N-1 in AP_MotorsMatrix.
    // Quadcopter-X frames only populate motor1..motor4; octocopter-X frames populate
    // motor1..motor8. Motors not fitted for the current frame are left at 0.
    float _pwm_motor1{0.0f};
    float _pwm_motor2{0.0f};
    float _pwm_motor3{0.0f};
    float _pwm_motor4{0.0f};
    float _pwm_motor5{0.0f};
    float _pwm_motor6{0.0f};
    float _pwm_motor7{0.0f};
    float _pwm_motor8{0.0f};

    // read back the last commanded PWM for each fitted motor output
    void update_motor_pwms(void);

    // reconstructed real motor output, from _pwm_motor1.._pwm_motor8
    float _tau_x{0.0f};   // roll torque, N.m
    float _tau_y{0.0f};   // pitch torque, N.m
    float _tau_z{0.0f};   // yaw torque, N.m
    float _F_total{0.0f}; // total collective thrust, N

    // convert this cycle's _pwm_motor1.._pwm_motor4 into _tau_x/_tau_y/_tau_z/_F_total
    void compute_real_torques(void);

};

#endif  // AP_CUSTOMCONTROL_XYZ_ENABLED
