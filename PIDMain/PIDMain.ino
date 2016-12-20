#include <PID_v1.h>

double Setpoint = 0, Input = 0, Output = 0, kp = .5, ki = 1, kd = 0; //PID variables and constants

double angSpeed = 0; //angSpeed is angular speed of the motor, 
double V = 0, I = 0; //V and I are avg of qualtities supplied to the motor
double e = 100; //e is instantanious efficiency of motor from efficiency table
double torquePedal = 0; //torquePedal is the torque supplied by the pedlar (from torque sensor)

double dutyCycle = 0, PWMDutyCycle = 0; //PWM constants (used in convertVandSend function)

PID myPID(&Input, &Output, &Setpoint, kp, ki, kd, DIRECT);


void setup()
{
  //take angSpeed, V, torquePedal and I as input from appropriate pins
  
  e = e/100;

  myPID.SetMode(AUTOMATIC); // for using PID library's Compute function

  Serial.begin(9600); // just for printing Output (DEBUG only)
}

/* Converts Output (voltage calculated by PID) into duty cycle for PWM and sends output from appropriate pin */
void convertVandSend(double V)
{
  //let selected pin be called pinNo
  //assuming battery voltage to be 48VDC
  
  //function code follows:
  
  /*
  dutyCycle = V/48;
  PWMDutyCycle = 255*dutyCycle;
  
  analogWrite(pinNo, PWMDutyCycle);
  */
  
  return;
}

void loop()
{
  
  //take angSpeed, V, torquePedal and I as input from appropriate pins and corresponding e from efficiency chart

  e = e/100;

  Input = (V*I*e)/(angSpeed);
  
  Setpoint = torquePedal;

  if (myPID.Compute()){ 

     Output = (Output*angSpeed)/(I*e); //extracting V from output
     
     convertVandSend(Output);

     Serial.println(Output); //printing Output (DEBUG only)
    }
}
