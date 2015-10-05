#include <TimerOne.h>
float Ea, Eb, Ec, Ed, En, vol, F[4], Error;
int sensor;

void setup(void)
   {    
    pinMode(13,OUTPUT);
    Timer1.initialize(10000);                 // Dispara cada 10 ms
    Timer1.attachInterrupt(ISR_Interrupcion); // Activa la interrupcion y la asocia a ISR_Interrupcion
    Serial.begin(9600);
   }
void loop() {
  
} 
//--------------Interrupcion Timer_1------------
void ISR_Interrupcion(){
 sensor = analogRead(A0);
 vol = sensor * (5.0 / 1023.0);
 Serial.println(vol);
 float ref=4,63;
 Error=ref-vol;
  if(Error<6 && Error>2){
     Ea=2; Eb=3.5; Ec=4.5; Ed=6;
     F[0] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[0]=0;
     }
  if(Error<3 && Error>-1){
     Ea=-1; Eb=0.5; Ec=1.5; Ed=3;
     F[1] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[1]=0;
     }
  if(Error<0 && Error>-4){
     Ea=-4; Eb=-3; Ec=-1; Ed=0;
     F[2] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[2]=0;
     }
  if(Error<-3 && Error>-6){
     Ea=-6; Eb=-5; Ec=-4; Ed=-3;
     F[3] = Fuzzy(Error, Ea, Eb, Ec, Ed);}
     else{
     F[3]=0;
     }
}
//----------------Fuzzificacion--------------------
float Fuzzy(float E, float Ena, float Enb, float Enc, float End)
{
  float P;
  if(E<Ena || E>End)
    { En=0;}
    else
  if(E>Enb && E<Enc)
    { En=1;}
    else
  if(E<=Enb || E>=Enc)
    {En=(E-Ena)/(Enb-Ena);}
  return P;
}
