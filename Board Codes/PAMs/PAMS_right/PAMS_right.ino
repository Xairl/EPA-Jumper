#include "EasyCAT.h"                // EasyCAT library to interface the LAN9252


//Ethercat 
EasyCAT EASYCAT(9);  //EasyCAT SPI chip select. Standard is pin 9

int TIB_in = 25;
int TIB_out = 10; 
int SOL_in = 41;
int SOL_out = 35;
int GAS_in = 40;
int GAS_out = 26;
int VAS_in = 24;
int VAS_out = 12;
int POP_in = 33;
int POP_out = 27;
int RF_in = 23;
int RF_out = 13;
int HAM_in = 29;
int HAM_out = 31;
int IL_in = 30;
int IL_out = 22;
int GL_in = 32;
int GL_out = 28;

//Pressure Sensors
int TIB_pin = A3;
int SOL_pin = A4;
int GAS_pin = A5;
int VAS_pin = A2;
int POP_pin = A8;
int RF_pin = A1;
int HAM_pin = A10;
int IL_pin = A0;
int GL_pin = A9;

  
void setup(){

  //Pin Configurations
  //---------------------------------------------------------------------------------------------------------------------------//
  pinMode(TIB_in, OUTPUT);
  pinMode(TIB_out, OUTPUT);
  pinMode(SOL_in, OUTPUT);
  pinMode(SOL_out, OUTPUT);
  pinMode(GAS_in, OUTPUT);
  pinMode(GAS_out, OUTPUT);
  pinMode(VAS_in, OUTPUT);
  pinMode(VAS_out, OUTPUT);
  pinMode(POP_in, OUTPUT);
  pinMode(POP_out, OUTPUT);
  pinMode(RF_in, OUTPUT);
  pinMode(RF_out, OUTPUT);
  pinMode(HAM_in, OUTPUT);
  pinMode(HAM_out, OUTPUT);
  pinMode(IL_in, OUTPUT);
  pinMode(IL_out, OUTPUT);
  pinMode(GL_in, OUTPUT);
  pinMode(GL_out, OUTPUT);

  
  //Ethercat
    if (EASYCAT.Init() == true)                                     // initialization
  {                                                               // succesfully completed
  }                                                                                         //
  
  else                                                            // initialization failed   
  {                                                              // the EasyCAT board was not recognized
                                                                  // The most common reason is that the SPI 
                                                                  // chip select choosen on the board doesn't 
                                                         // match the one choosen by the firmware
                                                                                                                           // 
   
  }
 
}

void loop(){
  EASYCAT.MainTask();       // execute the EasyCAT task


 Pressure_sensors();
 
 Valves();
    
    
}

void Pressure_sensors () 
{
//Reading
uint16_t Pressure_TIB = analogRead(TIB_pin);
uint16_t Pressure_SOL = analogRead(SOL_pin);
uint16_t Pressure_GAS = analogRead(GAS_pin);
uint16_t Pressure_VAS = analogRead(VAS_pin);
uint16_t Pressure_POP = analogRead(POP_pin);
uint16_t Pressure_RF = analogRead(RF_pin);
uint16_t Pressure_HAM = analogRead(HAM_pin);
uint16_t Pressure_IL = analogRead(IL_pin);
uint16_t Pressure_GL = analogRead(GL_pin);


//Sending
  //Pressure_TIB
   EASYCAT.BufferIn.Byte[0] = (Pressure_TIB >> 8);    
   
   EASYCAT.BufferIn.Byte[1] = (Pressure_TIB & 255);

  //Pressure_SOL
   EASYCAT.BufferIn.Byte[2] = (Pressure_SOL >> 8);    
   
   EASYCAT.BufferIn.Byte[3] = (Pressure_SOL & 255);
   
   //Pressure_GAS
   EASYCAT.BufferIn.Byte[4] = (Pressure_GAS >> 8);    
   
   EASYCAT.BufferIn.Byte[5] = (Pressure_GAS & 255);

   //Pressure_VAS
   EASYCAT.BufferIn.Byte[6] = (Pressure_VAS >> 8);    
   
   EASYCAT.BufferIn.Byte[7] = (Pressure_VAS & 255);

   //Pressure_POP
   EASYCAT.BufferIn.Byte[8] = (Pressure_POP >> 8);    
   
   EASYCAT.BufferIn.Byte[9] = (Pressure_POP & 255);

   //Pressure_RF
   EASYCAT.BufferIn.Byte[10] = (Pressure_RF >> 8);    
   
   EASYCAT.BufferIn.Byte[11] = (Pressure_RF & 255);

   //Pressure_HAM
   EASYCAT.BufferIn.Byte[12] = (Pressure_HAM >> 8);    
   
   EASYCAT.BufferIn.Byte[13] = (Pressure_HAM & 255);

   //Pressure_IL
   EASYCAT.BufferIn.Byte[14] = (Pressure_IL >> 8);    
   
   EASYCAT.BufferIn.Byte[15] = (Pressure_IL & 255);

  //Pressure_GL
   EASYCAT.BufferIn.Byte[16] = (Pressure_GL >> 8);    
   
   EASYCAT.BufferIn.Byte[17] = (Pressure_GL & 255);
  }

  void Valves () 
{
  //Turning on/off Solenoids
  digitalWrite(TIB_in,EASYCAT.BufferOut.Byte[0]);
  digitalWrite(TIB_out,EASYCAT.BufferOut.Byte[1]);
  digitalWrite(SOL_in,EASYCAT.BufferOut.Byte[2]);
  digitalWrite(SOL_out,EASYCAT.BufferOut.Byte[3]);
  digitalWrite(GAS_in,EASYCAT.BufferOut.Byte[4]);
  digitalWrite(GAS_out,EASYCAT.BufferOut.Byte[5]);
  digitalWrite(VAS_in,EASYCAT.BufferOut.Byte[6]);
  digitalWrite(VAS_out,EASYCAT.BufferOut.Byte[7]);
  digitalWrite(POP_in,EASYCAT.BufferOut.Byte[8]);
  digitalWrite(POP_out,EASYCAT.BufferOut.Byte[9]);
  digitalWrite(RF_in,EASYCAT.BufferOut.Byte[10]);
  digitalWrite(RF_out,EASYCAT.BufferOut.Byte[11]);
  digitalWrite(HAM_in,EASYCAT.BufferOut.Byte[12]);
  digitalWrite(HAM_out,EASYCAT.BufferOut.Byte[13]);
  digitalWrite(IL_in,EASYCAT.BufferOut.Byte[14]);
  digitalWrite(IL_out,EASYCAT.BufferOut.Byte[15]);
  digitalWrite(GL_in,EASYCAT.BufferOut.Byte[16]);
  digitalWrite(GL_out,EASYCAT.BufferOut.Byte[17]);
  }
