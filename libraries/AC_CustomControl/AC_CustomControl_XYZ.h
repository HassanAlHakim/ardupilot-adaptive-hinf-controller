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

protected:
    // declare parameters here
    AP_Float param1;
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

    // convert this cycle's _pwm_motor1.._pwm_motor8 into _tau_x/_tau_y/_tau_z/_F_total
    void compute_real_torques(void);

    // bench-fit PWM(us) -> thrust(N) model for a single motor
    static float pwm_to_thrust(float pwm_us);

};

#endif  // AP_CUSTOMCONTROL_XYZ_ENABLED
