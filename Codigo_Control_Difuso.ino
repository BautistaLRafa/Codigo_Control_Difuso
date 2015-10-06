#include <TimerOne.h>
float Ea, Eb, Ec, Ed, En, vol, F[5], Error;
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
 // ref = Serial.read();
 Error=ref-vol;
  if(Error<=4.7 && Error>=2){ 
     Ea=2; Eb=3.5; Ec=4; Ed=4.7;
     F[0] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[0]=0;
     }
  if(Error<=3 && Error>=0){
     Ea=0; Eb=1; Ec=2; Ed=3;
     F[1] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[1]=0;
     }
  if(Error<=0.5 && Error>=-0.5){
     Ea=-0.5; Eb=0; Ec=0; Ed=0.5;
     F[2] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[2]=0;
     }
  if(Error<=0 && Error>=-3){
     Ea=-3; Eb=-2; Ec=-1; Ed=0;
     F[3] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[3]=0;
     }
  if(Error<=-2 && Error>=-4.7){
     Ea=-4.7; Eb=-4; Ec=-3.5; Ed=-2;
     F[4] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[4]=0;
     }
}
//----------------Fuzzificacion--------------------
float Fuzzy(float E, float Ena, float Enb, float Enc, float End)
{
  float P;
  if(E<=Ena || E>=End)
    { P=0;}
    else
  if(E>=Enb && E<=Enc)
    { P=1;}
    else
  if(E<Enb || E>Enc)
    {P=(E-Ena)/(Enb-Ena);}
  return P;
}
//------------------------------------------------------
