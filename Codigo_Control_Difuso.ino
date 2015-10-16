#include <TimerOne.h>
float Ena, Enb, Enc, End, Emp, Ep, Ez, En, Emn, vol, Error, Eprima;
float Epmp, Epp, Epz, Epn, Epmn;
float MaxOmn=0, MaxOn=0, MaxOz=0, MaxOp=0, MaxOmp=0;
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
     if(Error<Enb || Error>Ena)
     {Emp=(Error-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {Emp=(Error+Ena)/(End-Enc);}
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
     if(Error<Enb || Error>Ena)
     {Ep=(Error-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {Ep=(Error+Ena)/(End-Enc);}
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
     if(Error<Enb || Error>Ena)
     {Ez=(Error-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {Ez=(Error+Ena)/(End-Enc);}
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
     if(Error<Enb || Error>Ena)
     {En=(Error-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {En=(Error+Ena)/(End-Enc);}
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
     if(Error<Enb || Error>Ena)
     {Emn=(Error-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {Emn=(Error+Ena)/(End-Enc);}
     else{
     Emn=0;}
     }
//-------------------------------------------------
if(Eprima<=4.7 && Eprima>=2){           // Falta definir conjuntos para E'(Error Prima)
     Ena=2; Enb=3.5; Enc=4; End=4.7;
     if(Eprima<=Ena || Eprima>=End)
     { Epmp=0;}
     else
     if(Eprima>=Enb && Eprima<=Enc)
     { Epmp=1;}
     else
     if(Eprima<Enb || Eprima>Ena)
     {Epmp=(Eprima-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {Epmp=(Error+Ena)/(End-Enc);}
     else{
     Epmp=0;}
     }
//---------------------Reglas-Difusas---------------
float Omn[5], On[6], Oz[3], Op[6], Omp[5];
if(Emn<Epmn){
  Omn[0]=Emn;}
  else {Omn[0]=Epmn;}
if(Emn<Epn){
  Omn[1]=Emn;}
  else {Omn[1]=Epn;}
if(Emn<Epz){
  Omn[2]=Emn;}
  else {Omn[2]=Epz;}
if(Emn<Epp){
  Omn[3]=Emn;}
  else {Omn[3]=Epp;}
if(Emn<Epmp){
  Omn[4]=Emn;}
  else {Omn[4]=Epmp;}
MaxOmn=Omn[0];
for (int i=0; i<5; i++){
     if(MaxOmn<Omn[i]){
        MaxOmn=Omn[i];}
}
if(En<Epmn){
  On[0]=En;}
  else {On[0]=Epmn;}
if(En<Epn){
  On[1]=En;}
  else {On[1]=Epn;}
if(En<Epz){
  On[2]=En;}
  else {On[2]=Epz;}
if(En<Epp){
  On[3]=En;}
  else {On[3]=Epp;}
if(En<Epmp){
  On[4]=En;}
  else {On[4]=Epmp;}
if(Ez<Epmp){
  On[5]=Ez;}
  else {On[5]=Epmp;}
MaxOn=On[0];
for (int i=0; i<6; i++){
     if(MaxOn<On[i]){
        MaxOn=On[i];}
}
if(Ez<Epn){
  Oz[0]=Ez;}
  else {Oz[0]=Epn;}
if(Ez<Epz){
  Oz[1]=Ez;}
  else {Oz[1]=Epz;}
if(Ez<Epp){
  Oz[2]=Ez;}
  else {Oz[2]=Epp;}
MaxOz=Oz[0];
for (int i=0; i<3; i++){
     if(MaxOz<Oz[i]){
        MaxOz=Oz[i];}
}
if(Ep<Epmn){
  Op[0]=Ep;}
  else {Op[0]=Epmn;}
if(Ep<Epn){
  Op[1]=Ep;}
  else {Op[1]=Epn;}
if(Ep<Epz){
  Op[2]=Ep;}
  else {Op[2]=Epz;}
if(Ep<Epp){
  Op[3]=Ep;}
  else {Op[3]=Epp;}
if(Ep<Epmp){
  Op[4]=Ep;}
  else {Op[4]=Epmp;}
if(Ez<Epmn){
  Op[5]=Ez;}
  else {Op[5]=Epmn;}
MaxOp=Op[0];
for (int i=0; i<6; i++){
     if(MaxOp<Op[i]){
        MaxOp=Op[i];}
}
if(Emp<Epmn){
  Omp[0]=Emp;}
  else {Omp[0]=Epmn;}
if(Emp<Epn){
  Omp[1]=Emp;}
  else {Omp[1]=Epn;}
if(Emp<Epz){
  Omp[2]=Emp;}
  else {Omp[2]=Epz;}
if(Emp<Epp){
  Omp[3]=Emp;}
  else {Omp[3]=Epp;}
if(Emp<Epmp){
  Omp[4]=Emp;}
  else {Omp[4]=Epmp;}
MaxOmp=Omp[0];
for (int i=0; i<5; i++){
     if(MaxOmp<Omp[i]){
        MaxOmp=Omp[i];}
}

float SumP=0, Sum=0, Omp, Op, Oz, On, Omn;
for (int i=0; i<101; 101/1023){
    if(i<=1481 && i>=932){           
     Ena=932; Enb=1176; Enc=1237; End=1481;
     if(i<=Ena || i>=End)
     { Omp=0;}
     else
     if(i>=Enb && i<=Enc)
     { Omp=MaxOmp;}
     else
     if(i<Enb || i>Ena)
     {Omp=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Omp=(i+Ena)/(End-Enc);}
     else{
     Omp=0;}
     }
    sum=sum+Omp;
    sump=sump+(Omp*i);
    
     if(i<=1110 && i>=623){           
     Ena=623; Enb=888; Enc=888; End=1110;
     if(i<=Ena || i>=End)
     { Op=0;}
     else
     if(i>=Enb && i<=Enc)
     { Op=MaxOp;}
     else
     if(i<Enb || i>Enc)
     {Op=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Op=(i+Ena)/(End-Enc);}
     else{
     Op=0;}
     }
    sum=sum+Op;
    sump=sump+(Op*i);
     
     if(i<=830 && i>=278){           
     Ena=278; Enb=578; Enc=578; End=830;
     if(i<=Ena || i>=End)
     { Oz=0;}
     else
     if(i>=Enb && i<=Enc)
     { Oz=MaxOz;}
     else
     if(i<Enb || i>Enc)
     {Oz=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Oz=(i+Ena)/(End-Enc);}
     else{
     Oz=0;}
     }
    sum=sum+Oz;
    sump=sump+(Oz*i);
     
     if(i<=478 && i>=16){           
     Ena=16; Enb=275; Enc=275; End=478;
     if(i<=Ena || i>=End)
     { On=0;}
     else
     if(i>=Enb && i<=Enc)
     { On=MaxOn;}
     else
     if(i<Enb || i>Enc)
     {On=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {On=(i+Ena)/(End-Enc);}
     else{
     On=0;}
     }
    sum=sum+On;
    sump=sump+(On*i);
     
     if(i<=187 && i>=-291){           
     Ena=-291; Enb=0; Enc=45; End=187;
     if(i<=Ena || i>=End)
     { Omn=0;}
     else
     if(i>=Enb && i<=Enc)
     { Omn=MaxOmn;}
     else
     if(i<Enb || i>Enc)
     {Omn=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Omn=(i+Ena)/(End-Enc);}
     else{
     Omn=0;}
     }
    sum=sum+Omn;
    sump=sump+(Omn*i);
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




