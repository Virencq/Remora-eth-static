#ifndef BOARDCONFIG_H
#define BOARDCONFIG_H

#include "pin.h"


struct StepgenConfig {
    const char* Comment;
    const int JointNumber;
    const char* StepPin;
    const char* DirectionPin;
  
}; 

struct EncoderConfig {
    const char* Comment;
    const char* PinA;
    const char* PinB;
    const int Modifier; // OPENDRAIN, PULLUP, PULLDOWN, PULLNONE, NONE


};

struct DigitalPinConfig {
    const char* Comment;
    const char* Pin;
    const int Modifier; // OPENDRAIN, PULLUP, PULLDOWN, PULLNONE, NONE
    const bool Invert;
    const int DataBit;
};

struct PWMPinConfig {
    const char* Comment;
    const char* Pin;
    const int Peroid_sp;

};

struct BlinkPinConfig {
    const char* Comment;
    const char* Pin;
    const int Freq;
};

//Module config

#define BOARD "NUCLEO446ze"

//Base thread objects - Stepgens, encoders, and RC servos supported here
//Comment, joint number, step pin, dir pin, 
 
 //446
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_5", "PA_6"},
                                    {"Z-Axis", 1, "PA_7", "PD_14"}};
                                    
/*

StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4"}, 
                                    {"Y-Axis", 1, "PB_3", "PB_10"},
                                    {"Z-Axis", 2, "PB_5", "PA_8"},
                                    {"A-Axis", 3, "PA_6", "PA_5"}};
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PA_10", "PB_4","PA_9" }, 
                                    {"Y-Axis", 1, "PB_3", "PB_10","PA_9" },
                                    {"Z-Axis", 2, "PB_5", "PA_8","PA_9" },
                                    {"A-Axis", 3, "PA_6", "PA_5","PA_9"  }};

 401
StepgenConfig StepgenConfigs[] =   {{"X-Axis", 0, "PB_4", "PC_10","PA_9" }, 
                                    {"Y-Axis", 1, "PB_10", "PB_12","PA_9" },
                                    {"Z-Axis", 2, "PA_8", "PD_13","PA_9" },
                                    {"A-Axis", 3, "PA_6", "PA_5","PA_9" }};
*/


//EncoderConfig EncoderConfigs[] = {{"X-axis", 0, "PA_13", "PA_14", PULLNONE}};
EncoderConfig EncoderConfigs[] = {};
//EncoderConfig EncoderConfigs[] = {};

//Servo thread objects - eStop, Reset Pin, Blink, Digital Pin, PWM, Temperature, Switch, QEI

DigitalPinConfig DOConfigs[] = {{"COOLANT", "PF_12", PULLNONE, false, 0}}; //Comment, pin, modifier, invert, data bit
                                //{"AUX1", "PB_3", PULLNONE, false, }};

DigitalPinConfig DIConfigs[] = {{"ALL_HOME", "PF_13", PULLUP, false, 0},
                                {"RUN", "PE_9", PULLUP, false, 1},
                                {"ESTOP", "PE_11", PULLUP, false, 2},
                                {"RESUME", "PF_14", PULLUP, false, 3},
                                {"MCON", "PE_13", PULLUP, false, 4}};  //Comment, pin, modifier, invert, data bit
/*
                                {"ChA", "PD_0", PULLUP, false, 6},
                                {"Ch_Index", "PD_1", PULLUP, false, 7}};  //Comment, pin, modifier, invert, data bit

*/


//PWMPinConfig PWMConfigs[] = {};        
PWMPinConfig PWMConfigs[] = {{"Spindle PWM", "PD_15"}};

BlinkPinConfig BlinkConfigs[] = {};    


const char* PRU_Reset_Pin = "PB_2";


 

//On Load objects - MCP4451, Motor Power, TMC2208, TMC2209. None currently implemented here.



#endif
