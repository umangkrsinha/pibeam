#include <PID_v1.h>

double Setpoint = 0, Input = 0, Output = 0, kp = .5, ki = 1, kd = 0; //PID variables and constants

float angSpeed = 0; //angSpeed is angular speed of the motor, 
float V = 0, I = 0; //V and I are avg of qualtities supplied to the motor
float e = 100; //e is instantanious efficiency of motor from efficiency table
float torquePedal = 0; //torquePedal is the torque supplied by the pedlar (from torque sensor)

float  dutyCycle = 0, PWMDutyCycle = 0; //PWM constants (used in convertVandSend function)

int counter = 0, R = 0;

int graphTable[256] = 
{32,33,34,34,35,36,37,37,38,39,40,41,41,42,43,44,44,45,46,46,47,48,49,49,50,50,51,52,52,53,54,54,
55,55,56,56,57,57,58,58,59,59,60,60,60,61,61,61,62,62,62,62,63,63,63,63,63,64,64,64,64,64,64,64,
64,64,64,64,64,64,64,63,63,63,63,63,63,62,62,62,61,61,61,60,60,60,59,59,58,58,58,57,57,56,56,55,
54,54,53,53,52,51,51,50,50,49,48,47,47,46,45,45,44,43,42,42,41,40,39,39,38,37,36,36,35,34,33,32,
32,31,30,29,28,28,27,26,25,25,24,23,22,22,21,20,19,19,18,17,17,16,15,14,14,13,13,12,11,11,10,10,
9,8,8,7,7,6,6,6,5,5,4,4,4,3,3,3,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,2,2,
3,3,3,4,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,12,12,13,14,14,15,15,16,17,18,18,19,20,20,21,22,23,23,
24,25,26,27,27,28,29,30,30,31,32};

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

  angSpeed = 1;

  V = Output;

  if(V == 0) V = 1;
  
  e = 100/100;

  I = R*V;

  if(I == 0) I = 1;

  Input = ((V*I*e)/(angSpeed));

  delay(10);
  
  Setpoint = graphTable[counter];

  Output = (Output*angSpeed)/(I*e); //extracting V from output
  
  if (myPID.Compute()){ 
     
     //convertVandSend(Output);

     Serial.println(Input); //printing Output (DEBUG only)
    }
    
  if(counter == 255) counter = 0;
  counter ++;
}
