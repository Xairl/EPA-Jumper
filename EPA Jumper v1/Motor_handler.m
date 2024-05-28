function [Hip_Mode_out, Hip_position_des_out, Hip_velocity_des_out, Hip_Kp_out, Hip_Kd_out, Hip_Curret_des_out] = Motor_handler(Hip_Mode, Hip_position_des, Hip_velocity_des, Hip_Kp, Hip_Kd, Hip_Curret_des)

switch Hip_Mode
    case 0  %Motor Off
        Hip_Mode_out = Hip_Mode;
        Hip_position_des_out = 0;
        Hip_velocity_des_out = 0;
        Hip_Kp_out = 0;
        Hip_Kd_out = 0;
        Hip_Curret_des_out = 0;
    case 1  %Position Control
        Hip_Mode_out = Hip_Mode;
        Hip_position_des_out = Hip_position_des;
        Hip_velocity_des_out = Hip_velocity_des;
        Hip_Kp_out = Hip_Kp;
        Hip_Kd_out = Hip_Kd;
        Hip_Curret_des_out = 0;
    case 2  %Current Control
        Hip_Mode_out = Hip_Mode;
        Hip_position_des_out = 0;
        Hip_velocity_des_out = 0;
        Hip_Kp_out = 0;
        Hip_Kd_out = 0;
        Hip_Curret_des_out = Hip_Curret_des;
    case 3  %Set Zero
        Hip_Mode_out = Hip_Mode;
        Hip_position_des_out = 0;
        Hip_velocity_des_out = 0;
        Hip_Kp_out = 0;
        Hip_Kd_out = 0;
        Hip_Curret_des_out = 0;
    otherwise
        Hip_Mode_out = 0;
        Hip_position_des_out = 0;
        Hip_velocity_des_out = 0;
        Hip_Kp_out = 0;
        Hip_Kd_out = 0;
        Hip_Curret_des_out = 0;
end
end