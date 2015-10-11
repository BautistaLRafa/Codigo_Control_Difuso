#include <TimerOne.h>
float Ena, Enb, Enc, End, Emp, Ep, Ez, En, Emn, vol, Error;
int sensor;

void setup(void)
   {    
    pinMode(13,OUTPUT);
    Timer1.initialize(10000);                 // Dispara cada 10 ms
    Timer1.attachInterrupt(ISR_Interrupcion); // Activa la interrupcion y la asocia a ISR_Interrupcion
    Serial.begin(38400);
   }
void loop() {
  
} 
//--------------Interrupcion Timer_1------------
void ISR_Interrupcion(){
 sensor = analogRead(A0);
 vol = sensor * (5.0 / 1023.0);
 Serial.println(vol);
 float ref = 2.63;
 //if (Serial.available()>0){
 // ref = Serial.read();}
 Error=ref-vol;
  if(Error<=4.7 && Error>=2){ 
     Ena=2; Enb=3.5; Enc=4; End=4.7;
     if(Error<=Ena || Error>=End)
     { Emp=0;}
     else
     if(Error>=Enb && Error<=Enc)
     { Emp=1;}
     else
     if(Error<Enb || Error>Enc)
     {Emp=(Error-Ena)/(Enb-Ena);}
     else{
     Emp=0;}
     }
  if(Error<=3 && Error>=0){
     Ena=0; Enb=1; Enc=2; End=3;
     if(Error<=Ena || Error>=End)
     { Ep=0;}
     else
     if(Error>=Enb && Error<=Enc)
     { Ep=1;}
     else
     if(Error<Enb || Error>Enc)
     {Ep=(Error-Ena)/(Enb-Ena);}
     else{
     Ep=0;}
     }
  if(Error<=0.5 && Error>=-0.5){
     Ena=-0.5; Enb=0; Enc=0; End=0.5;
     if(Error<=Ena || Error>=End)
     { Ez=0;}
     else
     if(Error>=Enb && Error<=Enc)
     { Ez=1;}
     else
     if(Error<Enb || Error>Enc)
     {Ez=(Error-Ena)/(Enb-Ena);}
     else{
     Ez=0;}
     }
  if(Error<=0 && Error>=-3){
     Ena=-3; Enb=-2; Enc=-1; End=0;
     if(Error<=Ena || Error>=End)
     { En=0;}
     else
     if(Error>=Enb && Error<=Enc)
     { En=1;}
     else
     if(Error<Enb || Error>Enc)
     {En=(Error-Ena)/(Enb-Ena);}
     else{
     En=0;}
     }
  if(Error<=-2 && Error>=-4.7){
     Ena=-4.7; Enb=-4; Enc=-3.5; End=-2;
     if(Error<=Ena || Error>=End)
     { Emn=0;}
     else
     if(Error>=Enb && Error<=Enc)
     { Emn=1;}
     else
     if(Error<Enb || Error>Enc)
     {Emn=(Error-Ena)/(Enb-Ena);}
     else{
     Emn=0;}
     }
}
//----------------Fuzzificacion--------------------
//float Fuzzy(float E, float Ena, float Enb, float Enc, float End)
//{
//  float P;
//  if(E<=Ena || E>=End)
//    { P=0;}
//    else
//  if(E>=Enb && E<=Enc)
//    { P=1;}
//    else
//  if(E<Enb || E>Enc)
//    {P=(E-Ena)/(Enb-Ena);}
//  return P;}
//------------------------------------------------------




