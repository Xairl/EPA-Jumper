function pressure   = PressureSensor(sensorValue,voltageMultiplier, voltageBias,ReadingVoltage,VoltageResolution)
  voltage = sensorValue * (ReadingVoltage / VoltageResolution); % Convert the analog value to voltage (assuming a 5V reference voltage, and 10 bits resolution)
  % Transformation from Voltage to Pressure
  pressure = voltage*voltageMultiplier+voltageBias;
