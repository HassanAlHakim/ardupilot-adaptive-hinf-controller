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
};

#endif  // AP_CUSTOMCONTROL_XYZ_ENABLED
