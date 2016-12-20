
const int a_m = 0, b_m = 0, c_m = 0, A_m = 0, B_m = 0, C_m = 0; //ports for mosfet
const int a_h = 0, b_h = 0,c_h = 0; //ports for hallsensor inputs
int a, b, c, A, B, C;
int hall = 0;     // holds hall sensor inputs
void setup() {
  // put your setup code here, to run once:
  pinMode(a_m, OUTPUT);  //mosfet output ports
  pinMode(b_m, OUTPUT);
  pinMode(c_m, OUTPUT);
  pinMode(A_m, OUTPUT);
  pinMode(B_m, OUTPUT);
  pinMode(C_m, OUTPUT);

  pinMode(a_h, INPUT);  //hallsensor input ports
  pinMode(b_h, INPUT);
  pinMode(c_h, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

hall=digitalRead(a_h);           // hall sensor value is stored
hall=10*hall+digitalRead(b_h);   // in form of abc
hall=10*hall+digitalRead(c_h);

// switching

if(hall==101)  //step1
 {
   a=1;A=0;b=0;B=1;c=0;C=0;
 }
if(hall==100)  //step2
 {
   a=1;A=0;b=0;B=0;c=0;C=1;
 }
if(hall==110)  //step3
 {
   a=0;A=0;b=1;B=0;c=0;C=1;
 }
if(hall==010)  //step4
 {
   a=0;A=1;b=1;B=0;c=0;C=0;
 }
if(hall==011)  //step5
 {
   a=0;A=1;b=0;B=0;c=1;C=0;
 }
if(hall==001)  //step6
 {
   a=0;A=0;b=0;B=1;c=1;C=0;
 }

digitalWrite(a_m, a);
digitalWrite(b_m, b);
digitalWrite(c_m, c);
digitalWrite(A_m, A);
digitalWrite(B_m, B);
digitalWrite(C_m, C);
}
