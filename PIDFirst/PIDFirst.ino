#include <PID_v1.h>
//#include <PID_AutoTune_v0.h>

double Setpoint, Input = 0, Output = 0, counter = 0, flag = 0;

PID myPID(&Input, &Output, &Setpoint, 0.5, 1, .01, DIRECT);

//PID_ATune aTune(&Input, &Output);

void setup()
{
  
  Setpoint = 0;

  myPID.SetMode(AUTOMATIC);

  Serial.begin(9600);
}

void loop()
{ 
  Serial.println("Hello!");

   counter += 1;
   if (counter == 100){
    
    Setpoint = 100;
    counter = 0;
    flag = 1;
    }  

  delay(50);
  
  Input = Output;
  
  if (myPID.Compute()){
    //Serial.println(Setpoint);
    Serial.println(Output);
  }

}
