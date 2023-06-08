//#include <DueTimer.h>


float pres = 0;
int intake_pin = 22;
int outtake_pin = 23;
int pressure_sensor_pin = A0;
float pressure = 0;
float pt = 0;
float k_p = 0.15;
float k_i = 0.02*k_p;
float k_d = 0.55*k_p;
float c_p = 0;
float prec_p = 0;
float c_i = 0;
float c_d = 0;
float control = 0;
int N = 5;
float buffer_pre[] = {};
float T = 10/10; //loop cycle, ms
unsigned long start_time = 0;
unsigned long current_time = 0;
int count = 0;
int valve_count = 0; //microseconds
int total_count_ofvalve = 0;
int integer_count = 0;
int integer_clean = 100;
 
void setup() {
  Serial.begin(115200); //Begin Serial port
  pinMode(intake_pin,OUTPUT);
  pinMode(outtake_pin,OUTPUT);
  digitalWrite(outtake_pin,LOW);
  digitalWrite(intake_pin,LOW);

//
//  // Initialize Timer1 to run every 0.5 seconds (twice per second)
//  Timer1.initialize(1000);
//  // Execute for each interruption the function parpadearLED()
//  Timer1.attachInterrupt(Control);

//  Timer3.attachInterrupt(Control).setFrequency(100).start(); //outputs regulator controler at 50 Hz

}

void loop() {
  start_time = micros();
  if (Serial.available() > 0) {
    String input_string = Serial.readStringUntil('\n');
    pres = input_string.toFloat();
  }
  pressure = 8.0152E-04 * analogRead(pressure_sensor_pin)- 2.4560E-01;
//    y = 8.0152E-04x - 2.4560E-01

//  int volatile x = 0;
//  float volatile press_add = 0;
//  while (x<=N-2) {
//    buffer_pre[x] = buffer_pre[x+1];
//    press_add += buffer_pre[x];
//    x +=1;
//    }
//  buffer_pre[N-1] = pressure;
//  float filtered_pres = (press_add + pressure)/N;

if (valve_count==total_count_ofvalve) {
  c_p = pres-pressure;
  if (abs(c_p) < 0.01){
    c_p = 0;
  }
  if (integer_count == integer_clean) {
  c_i = 0;
  integer_count = 0;
  }
  else {
      c_i += c_p*T;
      integer_count+=1;
    }
  c_d = (c_p - prec_p) / T;
  prec_p = c_p;
  control = k_p*c_p + k_i*c_i + k_d*c_d;
  
 total_count_ofvalve = abs((control/0.09)*10);
 valve_count = 0;
}
else      {
  valve_count +=1;

}

  if (control > 0.01)  {
      digitalWrite(outtake_pin,LOW);
      digitalWrite(intake_pin,HIGH);


  }
  else if (control < -0.01) {
      digitalWrite(intake_pin,LOW);
      digitalWrite(outtake_pin,HIGH);
  }
  else {
      digitalWrite(outtake_pin,LOW);
      digitalWrite(intake_pin,LOW);
  }


  
  
    //  char msgString2[128];  // Array to store serial string
    //  sprintf(msgString2,"´Pressure: %d, Desired Pressure: %d ", pressure, pres);
    //  Serial.println(msgString2);
  if(count > 10.0/T){
    Serial.print("Pressure:  ");
    Serial.print(pressure,3);
//    Serial.print(filtered_pres,4);
    Serial.print("     Control:  ");
    Serial.print(control,3);
    Serial.print("    Desired Pressure: ");
    Serial.println(pres);
//    Serial.print("original Pressure: ");
//    Serial.print(",");
//    Serial.println(pressure,4);
    Serial.print("    Count: ");
    Serial.println(valve_count);
    count = 0;
  }
  count += 1;
    //Read pressure from the serial
//    if (Serial.available() > 0) {
//      String input_string = Serial.readStringUntil('\n');
//      pres = input_string.toFloat();
//    }
  current_time = micros();
//  Serial.println(T);
//  Serial.print("Time : ");
//  Serial.println(current_time - start_time, 5);
  while((current_time - start_time)/1000 < T){
    current_time = micros();
//    Serial.println(T - (current_time - start_time)/1000, 5);
//    Serial.print("Time loop : ");
//    Serial.println(current_time - start_time, 5);
  }
}


//void Control () 
//{
////  pt = analogRead(pressure_sensor_pin);
//  pressure = 8.0152E-04 * analogRead(pressure_sensor_pin)- 2.4560E-01;
////  pressure = 1.4202e-10f*powf(pt,4) - 2.5058e-7f*powf(pt,3) + 1.6244e-4*powf(pt,2) - 4.5046e-2*pt +4.5104;
////  y = 1.4202E-10x4 - 2.5058E-07x3 + 1.6244E-04x2 - 4.5046E-02x + 4.5104E+00
////y = 8.0152E-04x - 2.4560E-01
//
//
//
//  int volatile x = 0;
//  float volatile press_add = 0;
//  while (x<=N-2) {
//    buffer_pre[x] = buffer_pre[x+1];
//    press_add += buffer_pre[x];
//    x +=1;
//    }
//  buffer_pre[N-1] = pressure;
//
//  float filtered_pres = (press_add + pressure)/5;
//  
////  control = k_p*(pres-filtered_pres);
////
////  if (control > 0.01)  {
////      digitalWrite(outtake_pin,LOW);
////      digitalWrite(intake_pin,HIGH);
////    }
////  else if (control < -0.01) {
////      digitalWrite(intake_pin,LOW);
////      digitalWrite(outtake_pin,HIGH);
////    }
////  else {
////      digitalWrite(outtake_pin,LOW);
////      digitalWrite(intake_pin,LOW);
////    }
////  char msgString2[128];  // Array to store serial string
////  sprintf(msgString2,"´Pressure: %d, Desired Pressure: %d ", pressure, pres);
////  Serial.println(msgString2);
//
//
//  Serial.print("Pressure:  ");
//  Serial.print(filtered_pres,4);
////  Serial.print("     Control:  ");
////  Serial.println(control);
////  Serial.print("    Desired Pressure: ");
////  Serial.println(pres);
//  Serial.print("    original Pressure: ");
//  Serial.println(pressure,4);
//  }
