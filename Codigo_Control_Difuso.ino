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
#define Enb5 8.0
#define Enc5 10.5
#define End5 14.5

#define Ena6 0.0
#define Enb6 2.0
#define Enc6 5.5
#define End6 7.9

#define Ena7 -2.0
#define Enb7 0.0
#define Enc7 0.0
#define End7 2.0
#define Ena8 -7.9
#define Enb8 -5.5
#define Enc8 -2.0
#define End8 0.0

#define Ena9 -14.5
#define Enb9 -10.5
#define Enc9 -8.0
#define End9 5.5

#define Ena10 932.0
#define Enb10 1176.0
#define Enc10 1237.0
#define End10 1481.0

#define Ena11 623.0
#define Enb11 888.0
#define Enc11 888.0
#define End11 1110.0

#define Ena12 278.0
#define Enb12 578.0
#define Enc12 578.0
#define End12 830.0

#define Ena13 16.0
#define Enb13 275.0
#define Enc13 275.0
#define End13 478.0

#define Ena14 -291.0
#define Enb14 0.0
#define Enc14 45.0
#define End14 187.0


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

//float ref = 4.0;
// Serial.print("ref: ");
// Serial.println(ref);
//if (Serial.available()>0){
// ref = Serial.read();}
// Error=ref-vol;                     //Determina el valor de Error(referencia-valor del sensor)

 Error=2.5;
 Eprima=5.0;
 Serial.print(" Error: ");
 Serial.println(Error);
 Serial.print(" Error Prima: ");
 Serial.println(Eprima);
 //-----------Fuzzificacion-Conjunto-de-Entrada-Error----------
// Ena 2.0 Enb 3.5 Enc 5.0 End 5.7
if(Error<=Ena || Error>=End) { Emp=0;}
     else if(Error>=Enb && Error<=Enc) { Emp=1;}
     else if(Error<Enb) {Emp=(Error-Ena)/(Enb-Ena);}
     else {Emp=(End-Error)/(End-Enc);}
     
//Ena1 0.0 Enb1 1.0 Enc1 2.0 End1 3.7     
if(Error<=Ena1 || Error>=End1) { Emp=0;}
     else if(Error>=Enb1 && Error<=Enc1) { Emp=1;}
     else if(Error<Enb1) {Emp=(Error-Ena1)/(Enb1-Ena1);}
     else {Emp=(End1-Error)/(End1-Enc1);}

// Ena2 -0.5 Enb2 0.0 Enc2 0.0 End2 0.5
if(Error<=Ena2 || Error>=End2) { Emp=0;}
     else if(Error>=Enb2 && Error<=Enc2) { Emp=1;}
     else if(Error<Enb2) {Emp=(Error-Ena2)/(Enb2-Ena2);}
     else {Emp=(End2-Error)/(End2-Enc2);}

// Ena3 -3.0 Enb3 -2.0 Enc3 -1.0 End3 0.0
if(Error<=Ena3 || Error>=End3) { Emp=0;}
     else if(Error>=Enb3 && Error<=Enc3) { Emp=1;}
     else if(Error<Enb3) {Emp=(Error-Ena3)/(Enb3-Ena3);}
     else {Emp=(End3-Error)/(End3-Enc3);}

// Ena4 -5.7 Enb4 -4.0 Enc4 -3.5 End4 2.0
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
  
    if(i<=Ena10 || i>=End10) { PWM[0]=0;}
     else if(i>=Enb10 && i<=Enc10) { PWM[0]=MaxOmp;}
     else if(i<Enb10) {PWM[0]=(i-Ena10)/(Enb10-Ena10);}
     else {PWM[0]=(End10-i)/(End10-Enc10);}

    if(i<=Ena11 || i>=End11) { PWM[1]=0;}
     else if(i>=Enb11 && i<=Enc11) { PWM[1]=MaxOp;}
     else if(i<Enb11) {PWM[1]=(i-Ena11)/(Enb11-Ena11);}
     else {PWM[1]=(End11-i)/(End11-Enc11);}
     
    if(i<=Ena12 || i>=End12) { PWM[2]=0;}
     else if(i>=Enb12 && i<=Enc12) { PWM[2]=MaxOz;}
     else if(i<Enb12) {PWM[2]=(i-Ena12)/(Enb12-Ena12);}
     else {PWM[2]=(End12-i)/(End12-Enc12);}
     
   if(i<=Ena13 || i>=End13) { PWM[3]=0;}
     else if(i>=Enb13 && i<=Enc13) { PWM[3]=MaxOn;}
     else if(i<Enb13) {PWM[3]=(i-Ena13)/(Enb13-Ena13);}
     else {PWM[3]=(End13-i)/(End13-Enc13);}
     
    if(Error<=Ena14 || Error>=End14) { PWM[4]=0;}
     else if(i>=Enb14 && i<=Enc14) { PWM[4]=MaxOmn;}
     else if(i<Enb14) {PWM[4]=(i-Ena14)/(Enb14-Ena14);}
     else {PWM[4]=(End14-i)/(End14-Enc14);}
     
for (int i=1; i<5; i++)
    {if(PWM[0]<PWM[i]){PWM[0]=PWM[i];}} //Selecciona el maximo PWM}
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
Serial.print("PWM_2");
Serial.println(CU);

//analogWrite(CU);

}

//    if (Emp > MaxOmn){Emp=MaxOmp;} Presente para la defusificación.. implicacion
