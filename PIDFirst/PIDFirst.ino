#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input = 0, Output = 0, counter = 0, flag = 0;
//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, 1, 0, 0, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Serial.begin(9600);
  
  Setpoint = 0;
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{ 

   counter += 1;
   if (counter == 100){
    
    Setpoint = 100;
    counter = 0;
    flag = 1;
    }  

  delay(100);

  /*else{

      Serial.print("There is no delay!");
    }*/
  
  Input = Output;
  
  if (myPID.Compute()){
    //Serial.println(Setpoint);
    Serial.println(Output);
  }

}
