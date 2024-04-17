  #include "EasyCAT.h"                // EasyCAT library to interface the LAN9252
  #include <SPI.h>                    // SPI library
  
  
  //Ethercat 
  EasyCAT EASYCAT(9);  //EasyCAT SPI chip select. Standard is pin 9. The Jumper in the EasyCAT Shield should be the same.
  
  
    //Force Sensors z axis
     int Force_sensor_z_1_pin = A2; //Connection PIN
     int Force_sensor_z_2_pin = A3; //Connection PIN
     int Force_sensor_z_3_pin = A4; //Connection PIN
     int Force_sensor_z_4_pin = A5; //Connection PIN
     int Force_z_1 = 0; //Value initialization
     int Force_z_2 = 0; //Value initialization
     int Force_z_3 = 0; //Value initialization
     int Force_z_4 = 0; //Value initialization
    //Force Sensors y axis
     int Force_sensor_y_14_pin = A6;  //Connection PIN
     int Force_sensor_y_23_pin = A7;  //Connection PIN
     int Force_y_14 = 0;  //Value initialization
     int Force_y_23 = 0;  //Value initialization
    //Force Sensors x axis
     int Force_sensor_x_12_pin = A8;
     int Force_sensor_x_34_pin = A9;
     int Force_x_12 = 0;  //Value initialization
     int Force_x_34 = 0;  //Value initialization
  
     //Range z axis
     int A_z = 5;   //Connection PIN
     int B_z = 6;   //Connection PIN
     //Range x,y axis
     int A_xy = 3;  //Connection PIN
     int B_xy = 4;  //Connection PIN
  
     //Control Pins
    int Operate = 2;  //Connection PIN
  
    // Emergency Switch
    int Emergency_Switch = A1;  //Connection PIN
  
    
  //Initialization  
  void setup(){
    Serial.begin(115200); //Begin Serial port
    
    //Pin Configurations
    //---------------------------------------------------------------------------------------------------------------------------//
    //Operating Pin
    pinMode(Operate, OUTPUT); 
  
    //Range Pins 
    pinMode(A_z, OUTPUT); 
    pinMode(B_z, OUTPUT); 
    pinMode(A_xy, OUTPUT);  
    pinMode(B_xy, OUTPUT);  

    //Range Setting
    digitalWrite(A_z,LOW);  
    digitalWrite(B_z,HIGH);
    digitalWrite(A_xy,LOW);
    digitalWrite(B_xy,HIGH);
    delay(100);
    //Operational Mode of GRF plate Activation
    digitalWrite(Operate,HIGH);
  
    //Ethercat Inialization
      if (EASYCAT.Init() == true)                                     // initialization
    {                                                               // succesfully completed
    
    }                                                   
    
                                        //
    
    else                                                            // initialization failed   
    {                                                               // the EasyCAT board was not recognized
                                                                    // The most common reason is that the SPI 
                                                                    // chip select choosen on the board doesn't 
                                                           // match the one choosen by the firmware
                                                                    
      pinMode(13, OUTPUT);                                          // stay in loop for ever
                                                                    // with the Arduino led blinking
      while(1)                                                      //
      {                                                             //   
        digitalWrite (13, LOW);                                     // 
        delay(500);                                                 //   
        digitalWrite (13, HIGH);                                    //  
        delay(500);                                                 // 
      }                                                             // 
     
    }   
  }
  
  // Main Loop
  void loop(){
    EASYCAT.MainTask();       // execute the EasyCAT task Always necessary if not no Ethercat communication exists
  

   Communication();
      
      
  }
  void Communication () 
  {
  
    // Taring of GRF plate, done in the simulink and signal sent. Stay taring until the value is changed again in the simulink
     if (EASYCAT.BufferOut.Byte[0] != 1)
    {
        digitalWrite(Operate,LOW); 
        delay(10);
        digitalWrite(Operate,HIGH);
      }
      
    // Analog data reading  
    Force_z_1 = analogRead(Force_sensor_z_1_pin);
    Force_z_2 = analogRead(Force_sensor_z_2_pin);
    Force_z_3 = analogRead(Force_sensor_z_3_pin);
    Force_z_4 = analogRead(Force_sensor_z_4_pin);
  
    Force_y_23 = analogRead(Force_sensor_y_23_pin);
    Force_y_14 = analogRead(Force_sensor_y_14_pin);
    Force_x_12 = analogRead(Force_sensor_x_12_pin);
    Force_x_34 = analogRead(Force_sensor_x_34_pin);

    // DATA processed to sent in a bytes, and sent in the desired Ethercat bytes. Those should match with the Simulink byte description. if not wrong data will be read.
    //Force z
    //Force 1
     EASYCAT.BufferIn.Byte[0] = (Force_z_1 >> 8);    
     
     EASYCAT.BufferIn.Byte[1] = (Force_z_1 & 255);
  
    //Force 2
     EASYCAT.BufferIn.Byte[2] = (Force_z_2 >> 8);    
     
     EASYCAT.BufferIn.Byte[3] = (Force_z_2 & 255);
  
    //Force 3
     EASYCAT.BufferIn.Byte[4] = (Force_z_3 >> 8);    
     
     EASYCAT.BufferIn.Byte[5] = (Force_z_3 & 255);
  
    //Force 4
     EASYCAT.BufferIn.Byte[6] = (Force_z_4 >> 8);    
     
     EASYCAT.BufferIn.Byte[7] = (Force_z_4 & 255);

    //Force y
    //Force 14
     EASYCAT.BufferIn.Byte[8] = (Force_y_14 >> 8);    
     
     EASYCAT.BufferIn.Byte[9] = (Force_y_14 & 255);
  
    //Force 23
     EASYCAT.BufferIn.Byte[10] = (Force_y_23 >> 8);    
     
     EASYCAT.BufferIn.Byte[11] = (Force_y_23 & 255);
  
    //Force x
    //Force 3
     EASYCAT.BufferIn.Byte[12] = (Force_x_12 >> 8);    
     
     EASYCAT.BufferIn.Byte[13] = (Force_x_12 & 255);
  
    //Force 4
     EASYCAT.BufferIn.Byte[14] = (Force_x_34 >> 8);    
     
     EASYCAT.BufferIn.Byte[15] = (Force_x_34 & 255);
  
     //Emergency Switch reading and sending
    EASYCAT.BufferIn.Byte[16] = analogRead(Emergency_Switch);    
  
    }
