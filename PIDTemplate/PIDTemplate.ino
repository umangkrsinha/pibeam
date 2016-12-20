#include <PID_v1.h>

double Setpoint = 0, Input = 0, Output = 0, counter = 0;

PID myPID(&Input, &Output, &Setpoint, 0.5, 1, .01, DIRECT);


void setup()
{

  myPID.SetMode(AUTOMATIC);

  Serial.begin(9600);
}

void loop()
{ 
  Serial.println("Hello!");

   counter += 1;
   if (counter == 10){
    
    Setpoint += 10;
    counter = 0;
    }  

  delay(50);
  
  Input = Output;
  
  if (myPID.Compute()){
    
       Serial.println(Output);
  }
}
