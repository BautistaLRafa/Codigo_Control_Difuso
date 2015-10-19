#include <TimerOne.h>
float Emp, Ep, Ez, En, Emn, vol, Error, Eprima;
float Epmp, Epp, Epz, Epn, Epmn;
float MaxOmn=0, MaxOn=0, MaxOz=0, MaxOp=0, MaxOmp=0;
int sensor;

#define Ena 2.0
#define Enb 3.5
#define Enc 5.0
#define End 5.7

#define Ena1 0.0
#define Enb1 1.0
#define Enc1 2.0
#define End1 3.7

#define Ena2 -0.5
#define Enb2 0.0
#define Enc2 0.0
#define End2 0.5

#define Ena3 -3.0
#define Enb3 -2.0
#define Enc3 -1.0
#define End3 0.0

#define Ena4 -5.7
#define Enb4 -4.0
#define Enc4 -3.5
#define End4 2.0

#define Ena5 5.5
#define Enb5 8
#define Enc5 10.5
#define End5 14.5

#define Ena6 0
#define Enb6 2
#define Enc6 5.5
#define End6 7.9

#define Ena7 -2
#define Enb7 0
#define Enc7 0
#define End7 2
#define Ena8 -7.9
#define Enb8 -5.5
#define Enc8 -2
#define End8 0

#define Ena9 -14.5
#define Enb9 -10.5
#define Enc9 -8
#define End9 5.5

#define Ena10 932
#define Enb10 1176
#define Enc10 1237
#define End10 1481

#define Ena11 623
#define Enb11 888
#define Enc11 888
#define End11 1110

#define Ena12 278
#define Enb12 578
#define Enc12 578
#define End12 830

#define Ena13 16
#define Enb13 275
#define Enc13 275
#define End13 478

#define Ena14 -291 
#define Enb14 0
#define Enc14 45
#define End14 187


void setup(void)
   {    
    pinMode(13,OUTPUT);
//  Timer1.initialize(10000);                 // Dispara cada 10 ms
//    Timer1.attachInterrupt(ISR_Interrupcion); // Activa la interrupcion y la asocia a ISR_Interrupcion
    Serial.begin(9600);
   }
void loop() {
  

//--------------Interrupcion Timer_1------------
//void ISR_Interrupcion(){
// sensor = analogRead(A0);        //Toma los valores tegistrados por el sensor.
// vol = sensor * (5.0 / 1023.0);  //ADC para una resolucion de 10bits

Serial.print("Eprima: ");
 Serial.println(Eprima);
 float ref = 4.0;
 Serial.print("ref: ");
 Serial.println(ref);
  //if (Serial.available()>0){
 // ref = Serial.read();}
 Error=ref-vol;                     //Determina el valor de Error(referencia-valor del sensor)
 Serial.print(" error: ");
 Serial.println(Error);

 Error=2.5;
 Eprima=5.0;
 //-----------Fuzzificacion-Conjunto-de-Entrada-Error----------

     if(Error<=Ena || Error>=End) { Emp=0;}
     else if(Error>=Enb && Error<=Enc) { Emp=1;}
     else if(Error<Enb) {Emp=(Error-Ena)/(Enb-Ena);}
     else {Emp=(End-Error)/(End-Enc);}
     
     if(Error<=Ena1 || Error>=End1) { Emp=0;}
     else if(Error>=Enb1 && Error<=Enc1) { Emp=1;}
     else if(Error<Enb1) {Emp=(Error-Ena1)/(Enb1-Ena1);}
     else {Emp=(End1-Error)/(End1-Enc1);}
  
     if(Error<=Ena2 || Error>=End2) { Emp=0;}
     else if(Error>=Enb2 && Error<=Enc2) { Emp=1;}
     else if(Error<Enb2) {Emp=(Error-Ena2)/(Enb2-Ena2);}
     else {Emp=(End2-Error)/(End2-Enc2);}
     
     if(Error<=Ena3 || Error>=End3) { Emp=0;}
     else if(Error>=Enb3 && Error<=Enc3) { Emp=1;}
     else if(Error<Enb3) {Emp=(Error-Ena3)/(Enb3-Ena3);}
     else {Emp=(End3-Error)/(End3-Enc3);}
     
  if(Error<=Ena4 || Error>=End4) { Emp=0;}
     else if(Error>=Enb4 && Error<=Enc4) { Emp=1;}
     else if(Error<Enb4) {Emp=(Error-Ena4)/(Enb4-Ena4);}
     else {Emp=(End3-Error)/(End3-Enc3);}
     
     Serial.print("Emp: ");
     Serial.println(Emp);
     Serial.print("En: ");
     Serial.println(En);
     Serial.print("Ez: ");
     Serial.println(Ez);
     Serial.print("En: ");
     Serial.println(En);
     Serial.print("Emn: ");
     Serial.println(Emn);
//------------------Fuzzificacion-Conjunto-de-Entrada-Error-Prima----------------
     
      if(Error<=Ena5 || Error>=End5) { Epmp=0;}
     else if(Error>=Enb5 && Error<=Enc5) { Epmp=1;}
     else if(Error<Enb5) {Epmp=(Error-Ena5)/(Enb5-Ena5);}
     else {Epmp=(End5-Error)/(End5-Enc5);}

      if(Error<=Ena6 || Error>=End6) { Epp=0;}
     else if(Error>=Enb6 && Error<=Enc6) { Epp=1;}
     else if(Error<Enb6) {Epp=(Error-Ena6)/(Enb6-Ena6);}
     else {Epp=(End6-Error)/(End6-Enc6);}

if(Error<=Ena7 || Error>=End7) { Epz=0;}
     else if(Error>=Enb7 && Error<=Enc7) { Epz=1;}
     else if(Error<Enb7) {Epz=(Error-Ena7)/(Enb7-Ena7);}
     else {Epz=(End7-Error)/(End7-Enc7);}

 if(Error<=Ena8 || Error>=End8) { Epn=0;}
     else if(Error>=Enb8 && Error<=Enc8) { Epn=1;}
     else if(Error<Enb8) {Epn=(Error-Ena8)/(Enb8-Ena8);}
     else {Epn=(End8-Error)/(End8-Enc8);}

 if(Error<=Ena9 || Error>=End9) { Epmn=0;}
     else if(Error>=Enb9 && Error<=Enc9) { Epmn=1;}
     else if(Error<Enb9) {Epmn=(Error-Ena9)/(Enb9-Ena9);}
     else {Epmn=(End9-Error)/(End9-Enc9);}

     Serial.print("Epmp: ");
     Serial.println(Epmp);
     Serial.print("Epp: ");
     Serial.println(Epp);
     Serial.print("Epz: ");
     Serial.println(Epz);
     Serial.print("Epn: ");
     Serial.println(Epn);
     Serial.print("Epmn: ");
     Serial.println(Epmn);
//---------------------Reglas-Difusas---------------

float Omn[5], On[6], Oz[3], Op[6], Omp[5];
Omn[0]=min(Emn,Epmn);
Omn[1]=min(Emn,Epn);
Omn[2]=min(Emn,Epz);
Omn[3]=min(Emn,Epp);
Omn[4]=min(Emn,Epmp);

for (int i=1; i<5; i++){
     if(Omn[0]<Omn[i]){
        Omn[0]=Omn[i];} //Selecciona el maximo Omn
}
MaxOmn=Omn[0];


On[0]=min(En,Epmn);
On[1]=min(En,Epn);
On[2]=min(En,Epz);
On[3]=min(En,Epp);
On[4]=min(En,Epmp);
On[5]=min(Ez,Epmp);
for (int i=1; i<5; i++){
     if(On[0]<On[i]){
        On[0]=On[i];} //Selecciona el maximo On
}
MaxOn=Omn[0];

Oz[0]=min(Ez,Epn);
Oz[1]=min(Ez,Epz);
Oz[2]=min(Ez,Epp);
for (int i=1; i<5; i++){
     if(Oz[0]<Oz[i]){
        Oz[0]=Oz[i];} //Selecciona el maximo Oz
}
MaxOz=Oz[0];

Op[0]=min(Ep,Epmn);
Op[1]=min(Ep,Epn);
Op[2]=min(Ep,Epz);
Op[3]=min(Ep,Epp);
Op[4]=min(Ep,Epmp);
Op[5]=min(Ez,Epmn);
MaxOp=Op[0];
for (int i=0; i<6; i++){
     if(Op[0]<Op[i]){
        Op[0]=Op[i];}     //Selecciona el maximo Op
}
MaxOp=Op[0];

Omp[0]=min(Emp,Epmn);
Omp[1]=min(Emp,Epn);
Omp[2]=min(Emp,Epz);
Omp[3]=min(Emp,Epp);
Omp[4]=min(Emp,Epmp);
for (int i=1; i<5; i++){
     if(Omp[0]<Omp[i]){
        Omp[0]=Omp[i];} //Selecciona el maximo Omp
}
MaxOmp=Omp[0];

Serial.print("MaxOmn: ");
Serial.println(MaxOmn);
Serial.print("MaxOn: ");
Serial.println(MaxOn);
Serial.print("MaxOz: ");
Serial.println(MaxOz);
Serial.print("MaxOp: ");
Serial.println(MaxOp);
Serial.print("MaxOmp: ");
Serial.println(MaxOmp);
//------Fuzzificacion-e-Implicacion-de-Conjuntos-de-Salida-PWM--
float sump=0, sum=0, PWM[5], MaxPWM=0;
for (int i=0; i<1023; i=i+10){
  Serial.println(i);
  
    if(Error<=Ena10 || Error>=End10) { PWM[0]=0;}
     else if(Error>=Enb10 && Error<=Enc10) { PWM[0]=MaxOmp;}
     else if(Error<Enb10) {PWM[0]=(Error-Ena10)/(Enb10-Ena10);}
     else {PWM[0]=(End10-Error)/(End10-Enc10);}

     if(Error<=Ena11 || Error>=End11) { PWM[1]=0;}
     else if(Error>=Enb11 && Error<=Enc11) { PWM[1]=MaxOp;}
     else if(Error<Enb11) {PWM[1]=(Error-Ena11)/(Enb11-Ena11);}
     else {PWM[1]=(End11-Error)/(End11-Enc11);}
     
    if(Error<=Ena12 || Error>=End12) { PWM[2]=0;}
     else if(Error>=Enb12 && Error<=Enc12) { PWM[2]=MaxOz;}
     else if(Error<Enb12) {PWM[2]=(Error-Ena12)/(Enb12-Ena12);}
     else {PWM[2]=(End12-Error)/(End12-Enc12);}
     
   if(Error<=Ena13 || Error>=End13) { PWM[3]=0;}
     else if(Error>=Enb13 && Error<=Enc13) { PWM[3]=MaxOn;}
     else if(Error<Enb13) {PWM[3]=(Error-Ena13)/(Enb13-Ena13);}
     else {PWM[3]=(End13-Error)/(End13-Enc13);}
     
     if(Error<=Ena14 || Error>=End14) { PWM[4]=0;}
     else if(Error>=Enb14 && Error<=Enc14) { PWM[4]=MaxOmn;}
     else if(Error<Enb14) {PWM[4]=(Error-Ena14)/(Enb14-Ena14);}
     else {PWM[4]=(End14-Error)/(End14-Enc14);}
     
     for (int i=1; i<5; i++){
     if(PWM[0]<PWM[i]){
        PWM[0]=PWM[i];} //Selecciona el maximo PWM
}
MaxPWM=PWM[0];

    sum=sum+MaxPWM;
    sump=sump+(MaxPWM*i);
 }
//---------------------PWM----------------------
float c, f, CU;
sum=sum/1023;
c=sump/sum;
f=255/1023;
CU=c*f;
Serial.print("Error");
Serial.println(Error);
Serial.print("Error Prima");
Serial.println(Eprima);
Serial.print("Suma Ponderada");
Serial.println(sump);
Serial.print("Suma");
Serial.println(sum);
Serial.print("PWM");
Serial.println(c);

//analogWrite(CU);

}

//    if (Emp > MaxOmn){Emp=MaxOmp;} Presente para la defusificación.. implicacion
