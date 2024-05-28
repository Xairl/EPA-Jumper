function [intake, outtake,inside_deadzone_1] = Solenoid(control, inside_deadzone, deadzone_in, deadzone_out,PAMs_on,System_on,depressurize)

inside_deadzone_1 = inside_deadzone;
if PAMs_on == 1 &&  System_on == 1 && depressurize == 0
  if inside_deadzone_1 == 0 
      
    if control > deadzone_in
        outtake = 0;
        intake = 1;
               
    elseif control < -deadzone_in
        outtake = 1;
        intake = 0;
        
    else
        outtake = 0;
        intake = 0;
        inside_deadzone_1 = 1;
      
    end
      
  else 
    if control > deadzone_out
        outtake = 0;
        intake = 1;
        inside_deadzone_1 = 0;
      
    elseif control < -deadzone_out
        outtake = 1;
        intake = 0;
        inside_deadzone_1 = 0;
        
    else 
        outtake = 0;
        intake = 0;
    end
  end
  
elseif depressurize == 1
    outtake = 1;
    intake = 0;
else 
    outtake = 0;
    intake = 0;
end
    
    
  
end
