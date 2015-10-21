#include <TimerOne.h>
float Emp, Ep, Ez, En, Emn, vol, Error, Eprima;
float Epmp, Epp, Epz, Epn, Epmn, ValorActual=0.0, ValorAnterior=0.0;
float MaxOmn=0, MaxOn=0, MaxOz=0, MaxOp=0, MaxOmp=0;
int sensor;
//--------------Conjuntos-Error------------------
#define Ena_mp 2.0
#define Enb_mp 3.5
#define Enc_mp 5.0
#define End_mp 5.7

#define Ena_p 0.0
#define Enb_p 1.0
#define Enc_p 2.0
#define End_p 3.7

#define Ena_z -0.5
#define Enb_z 0.0
#define Enc_z 0.0
#define End_z 0.5

#define Ena_n -3.0
#define Enb_n -2.0
#define Enc_n -1.0
#define End_n 0.0

#define Ena_mn -5.7
#define Enb_mn -4.0
#define Enc_mn -3.5
#define End_mn 2.0
//--------------Conjuntos-Error-Prima-----------
#define Epna_mp 5.5
#define Epnb_mp 8.0
#define Epnc_mp 10.5
#define Epnd_mp 14.5

#define Epna_p 0.0
#define Epnb_p 2.0
#define Epnc_p 5.5
#define Epnd_p 7.9

#define Epna_z -2.0
#define Epnb_z 0.0
#define Epnc_z 0.0
#define Epnd_z 2.0

#define Epna_n -7.9
#define Epnb_n -5.5
#define Epnc_n -2.0
#define Epnd_n 0.0

#define Epna_mn -14.5
#define Epnb_mn -10.5
#define Epnc_mn -8.0
#define Epnd_mn 5.5
//--------------Conjuntos-Salida-PWM---------------
#define Ona_mp 932.0
#define Onb_mp 1176.0
#define Onc_mp 1237.0
#define Ond_mp 1481.0

#define Ona_p 623.0
#define Onb_p 888.0
#define Onc_p 888.0
#define Ond_p 1110.0

#define Ona_z 278.0
#define Onb_z 578.0
#define Onc_z 578.0
#define Ond_z 830.0

#define Ona_n 16.0
#define Onb_n 275.0
#define Onc_n 275.0
#define Ond_n 478.0

#define Ona_mn -291.0 
#define Onb_mn 0.0
#define Onc_mn 45.0
#define Ond_mn 187.0


void setup(void)
   {    
    pinMode(13,OUTPUT);
//    Timer1.initialize(10000);                 // Dispara cada 10 ms
//    Timer1.attachInterrupt(ISR_Interrupcion); // Activa la interrupcion y la asocia a ISR_Interrupcion
    Serial.begin(9600);
   }
void loop() {
  

//--------------Interrupcion Timer_1------------
//   void ISR_Interrupcion(){
// sensor = analogRead(A0);        //Toma los valores tegistrados por el sensor.
// vol = sensor * (5.0 / 1023.0);  //ADC para una resolucion de 10bits
 Eprima=5.0;
 ValorActual=vol;
 Eprima=ValorActual-ValorAnterior;
Serial.println("  ");
Serial.println("-----------");
Serial.println("CODIGO POR: RAFAEL BAUTISTA LOPEZ ");
Serial.println("UNIVERSIDAD COOPERATIVA DE COLOMBIA");
Serial.println("CONTROL III - CONTROL DIFUSO");
Serial.println("-----------");
Serial.print("Eprima: ");
 Serial.println(Eprima);
 //float ref = 4.0;
 //(Serial.print("ref: ");
//Serial.println(ref);
//if (Serial.available()>0){
// ref = Serial.read();}
// Error=ref-vol;                     //Determina el valor de Error(referencia-valor del sensor)
 Error=2.5;
 Serial.print(" error: ");
 Serial.println(Error);
Serial.println("-----------");


 //-----------Fuzzificacion-Conjunto-de-Entrada-Error----------
//Ena=2.0; Enb=3.5; Enc=5.0; End=5.7;
if(Error<=Ena_mp || Error>=End_mp) { Emp=0;}
     else if(Error>=Enb_mp && Error<=Enc_mp) { Emp=1;}
     else if(Error<Enb_mp) {Emp=(Error-Ena_mp)/(Enb_mp-Ena_mp);}
     else {Emp=(End_mp-Error)/(End_mp-Enc_mp);}
    
//Ena1=0; Enb=1; Enc=2; End=3.7; 
if(Error<=Ena_p || Error>=End_p) { Ep=0;}
     else if(Error>=Enb_p && Error<=Enc_p) { Ep=1;}
     else if(Error<Enb_p) {Ep=(Error-Ena_p)/(Enb_p-Ena_p);}
     else {Ep=(End_p-Error)/(End_p-Enc_p);}
    
//Ena2=-0.5; Enb=0; Enc=0; End=0.5;  
if(Error<=Ena_z || Error>=End_z) { Ez=0;}
     else if(Error>=Enb_z && Error<=Enc_z) { Ez=1;}
     else if(Error<Enb_z) {Ez=(Error-Ena_z)/(Enb_z-Ena_z);}
     else {Ez=(End_z-Error)/(End_z-Enc_z);}
    
//Ena3=-3.0; Enb=-2.0; Enc=-1; End=0;     
if(Error<=Ena_n || Error>=End_n) { En=0;}
     else if(Error>=Enb_n && Error<=Enc_n) { En=1;}
     else if(Error<Enb_n) {En=(Error-Ena_n)/(Enb_n-Ena_n);}
     else {En=(End_n-Error)/(End_n-Enc_n);}
     
//Ena4=-5.7; Enb=-4.0; Enc=-3.5; End=2.0;     
if(Error<=Ena_mn || Error>=End_mn) { Emn=0;}
     else if(Error>=Enb_mn && Error<=Enc_mn) { Emn=1;}
     else if(Error<Enb_mn) {Emn=(Error-Ena_mn)/(Enb_mn-Ena_mn);}
     else {Emn=(End_mn-Error)/(End_mn-Enc_mn);}
     
     Serial.print("Emp: ");
     Serial.println(Emp);
     Serial.print("Ep: ");
     Serial.println(Ep);
     Serial.print("Ez: ");
     Serial.println(Ez);
     Serial.print("En: ");
     Serial.println(En);
     Serial.print("Emn: ");
     Serial.println(Emn);
     Serial.println("-----------");
//------------------Fuzzificacion-Conjunto-de-Entrada-Error-Prima----------------
//Ena5=5.5; Enb=8; Enc=10.5; End=14.5;     
if(Eprima<=Epna_mp || Eprima>=Epnd_mp) { Epmp=0;}
     else if(Eprima>=Epnb_mp && Eprima<=Epnc_mp) { Epmp=1;}
     else if(Eprima<Epnb_mp) {Epmp=(Eprima-Epna_mp)/(Epnb_mp-Epna_mp);}
     else {Epmp=(Epnd_mp-Eprima)/(Epnd_mp-Epnc_mp);}
//Ena6=0; Enb=2; Enc=5.5; End=7.9;
if(Eprima<=Epna_p || Eprima>=Epnd_p) { Epp=0;}
     else if(Eprima>=Epnb_p && Eprima<=Epnc_p) { Epp=1;}
     else if(Eprima<Epnb_p) {Epp=(Eprima-Epna_p)/(Epnb_p-Epna_p);}
     else {Epp=(Epnd_p-Eprima)/(Epnd_p-Epnc_p);}
//Ena7=-2; Enb=0; Enc=0; End=2;
if(Eprima<=Epna_z || Eprima>=Epnd_z) { Epz=0;}
     else if(Eprima>=Epnb_z && Eprima<=Epnc_z) { Epz=1;}
     else if(Eprima<Epnb_z) {Epz=(Eprima-Epna_z)/(Epnb_z-Epna_z);}
     else {Epz=(Epnd_z-Eprima)/(Epnd_z-Epnc_z);}
//Ena8=-7.9; Enb=-5.5; Enc=-2; End=0;
 if(Eprima<=Epna_n || Eprima>=Epnd_n) { Epn=0;}
     else if(Eprima>=Epnb_n && Eprima<=Epnc_n) { Epn=1;}
     else if(Eprima<Epnb_n) {Epn=(Eprima-Epna_n)/(Epnb_n-Epna_n);}
     else {Epn=(Epnd_n-Eprima)/(Epnd_n-Epnc_n);}
//Ena9=-14.5; Enb=-10.5; Enc=-8; End=5.5;
 if(Eprima<=Epna_mn || Eprima>=Epnd_mn) { Epmn=0;}
     else if(Eprima>=Epnb_mn && Eprima<=Epnc_mn) { Epmn=1;}
     else if(Eprima<Epnb_mn) {Epmn=(Eprima-Epna_mn)/(Epnb_mn-Epna_mn);}
     else {Epmn=(Epnd_mn-Eprima)/(Epnd_mn-Epnc_mn);}

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
     Serial.println("-----------");
//---------------------Reglas-Difusas---------------

float Omn[5], On[6], Oz[3], Op[6], Omp[5];
Omn[0]=min(Emn,Epmn);
Omn[1]=min(Emn,Epn);
Omn[2]=min(Emn,Epz);
Omn[3]=min(Emn,Epp);
Omn[4]=min(Emn,Epmp);

for (int i=0; i<5; i++){
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
for (int i=0; i<6; i++){
     if(On[0]<On[i]){
        On[0]=On[i];} //Selecciona el maximo On
}
MaxOn=Omn[0];

Oz[0]=min(Ez,Epn);
Oz[1]=min(Ez,Epz);
Oz[2]=min(Ez,Epp);
for (int i=0; i<3; i++){
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
for (int i=0; i<5; i++){
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
Serial.println("-----------");
//------Fuzzificacion-e-Implicacion-de-Conjuntos-de-Salida-PWM--
float sump=0.0, sum=0.0, PWM[5];
for (int i=0; i<1023; i=i+10){
  Serial.println(i);
  //Ena10=932; Enb=1176; Enc=1237; End=1481;
  if(i<=Ona_mp || i>=Ond_mp) { PWM[0]=0;Serial.println("Entra 1er if ");}
     else if(i>=Onb_mp && i<=Onc_mp) { PWM[0]=1;Serial.println("Entra 2do if ");}
     else if(i<Onb_mp) {PWM[0]=(i-Ona_mp)/(Onb_mp-Ona_mp);Serial.println("Entra 3er if ");}
     else {PWM[0]=(Ond_mp-i)/(Ond_mp-Onc_mp);Serial.println("Entra 4to if ");}
     PWM[0]=max(PWM[0],MaxOmp);
     Serial.print("PWM[0]: ");
      Serial.println(PWM[0]);
//Ena11=623.0; Enb=888; Enc=888; End=1110;
 if(i<=Ona_p || i>=Ond_p) { PWM[1]=0;}
     else if(i>=Onb_p && i<=Onc_p) { PWM[1]=1;}
     else if(i<Onb_p) {PWM[1]=(i-Ona_p)/(Onb_p-Ona_p);}
     else {PWM[1]=(Ond_p-i)/(Ond_p-Onc_p);}
     PWM[1]=max(PWM[1],MaxOp);
     Serial.print("PWM[1]: ");
      Serial.println(PWM[1]);
//Ena12=278; Enb=578; Enc=578; End=830;     
if(i<=Ona_z || i>=Ond_z) { PWM[2]=0;}
     else if(i>=Onb_z && i<=Onc_z) { PWM[2]=1;}
     else if(i<Onb_z) {PWM[2]=(i-Ona_z)/(Onb_z-Ona_z);}
     else {PWM[2]=(Ond_z-i)/(Ond_z-Onc_z);}
     PWM[2]=max(PWM[2],MaxOz);
     Serial.print("PWM[2]: ");
      Serial.println(PWM[2]);
// Ena13=16; Enb=275; Enc=275; End=478;    
if(i<=Ona_n || i>=Ond_n) { PWM[3]=0;}
     else if(i>=Onb_n && i<=Onc_n) { PWM[3]=1;}
     else if(i<Onb_n) {PWM[3]=(i-Ona_n)/(Onb_n-Ona_n);}
     else {PWM[3]=(Ond_n-i)/(Ond_n-Onc_n);}
     PWM[3]=max(PWM[3],MaxOn);
     Serial.print("PWM[3]: ");
      Serial.println(PWM[3]);
// Ena14=-291; Enb=0; Enc=45; End=187;   
if(i<=Ona_mn || i>=Ond_mn) { PWM[4]=0;}
     else if(i>=Onb_mn && i<=Onc_mn) { PWM[4]=1;}
     else if(i<Onb_mn) {PWM[4]=(i-Ona_mn)/(Onb_mn-Ona_mn);}
     else {PWM[4]=(Ond_mn-i)/(Ond_mn-Onc_mn);}
     PWM[3]=max(PWM[3],MaxOmn);
     Serial.print("PWM[4]: ");
      Serial.println(PWM[4]);
for (int i=0; i<5; i++){
  PWM[0]=max(PWM[0],PWM[i]);
}
Serial.print("            => PWM_MAX: ");
Serial.print(PWM[0]); Serial.print(" + Suma: ");Serial.println(sum);
sum=sum+PWM[0];
Serial.print("            => Suma: ");
Serial.println(sum);
sump=sump+(PWM[0]*i);
}

//---------------------PWM----------------------
float c, f, CU;
ValorAnterior=ValorActual;
c=sump/(sum);
f=255.0/1023.0;
CU=c*f;
Serial.print("Error: ");
Serial.println(Error);
Serial.print("Error Prima: ");
Serial.println(Eprima);
Serial.print("Suma Ponderada: ");
Serial.println(sump);
Serial.print("Suma: ");
Serial.println(sum);
Serial.print("PWM: ");
Serial.println(c);
Serial.print("PWM_2: ");
Serial.println(CU);
Serial.println("-------------------------------------------");
Serial.println("-------------------------------------------");

//analogWrite(CU);

}

