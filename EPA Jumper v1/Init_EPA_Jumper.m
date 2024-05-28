%% Initialization code
close all
clear all
clc

%% Uint to float convertion
P_MIN = -95.5;
P_MAX = 95.5; 
V_MIN = -45.0;
V_MAX = 45.0;
KP_MIN = 0.0; 
KP_MAX = 500.0;
KD_MIN = 0.0;
KD_MAX = 5.0;
T_MIN = -18.0;
T_MAX = 18.0;

%% Bits data for Motors
bits_position = 16;
bits_velocity= 12;
bits_current= 12;
bits_Kp = 12;
bits_Kd = 12;

%% GRF
GRF_MAX = 3.3;
GRF_MIN = 0;
bits_GRF = 12;
%% PAM Pressure Sensors
ReadingVoltage = 5;
VoltageResolution = 1024.0;
voltageMultiplier_TIB = 2.4915;
voltageBias_TIB = -2.3721;
voltageMultiplier_SOL = 2.4915;
voltageBias_SOL = -2.3721;
voltageMultiplier_GAS = 2.4915;
voltageBias_GAS = -2.3721;
voltageMultiplier_VAS = 2.4915;
voltageBias_VAS = -2.3721;
voltageMultiplier_POP = 2.4915;
voltageBias_POP = -2.3721;
voltageMultiplier_RF = 2.4915;
voltageBias_RF = -2.3721;
voltageMultiplier_HAM = 2.4915;
voltageBias_HAM = -2.3721;
voltageMultiplier_IL = 2.4915;
voltageBias_IL = -2.3721;
voltageMultiplier_GL = 2.5259;
voltageBias_GL = -2.2892;

PressureFilter_Gain = 1;
PressureFilter_CutOffFreq = 50;
    
%% Valves Control
% TIB
    deadzone_in_TIB = 0.45;
    deadzone_out_TIB = 0.48;
    k_p_TIB = 1;
    k_d_TIB = 0.0075;
    
    
%% Hip Motor Calibration
% % Sensor to Actual Current
% % y = p1*x^3 + p2*x^2 +
% %       p3*x + p4 
%   hip_actual_p1 = 0.013386;
%   hip_actual_p2 = -0.0054898;
%   hip_actual_p3 = 0.11292;
%   hip_actual_p4 = 0.11366;
% 
% % Actual To sensor

