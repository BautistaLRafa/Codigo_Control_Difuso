#include <TimerOne.h>
float Ena, Enb, Enc, End, Emp, Ep, Ez, En, Emn, vol, Error, Eprima;
float Epmp, Epp, Epz, Epn, Epmn;
float MaxOmn=0, MaxOn=0, MaxOz=0, MaxOp=0, MaxOmp=0;
int sensor;

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
vol=1.5;
Eprima=5;
Serial.print("Eprima: ");
 Serial.println(Eprima);
 float ref = 4;
 Serial.print("ref: ");
 Serial.println(ref);
  //if (Serial.available()>0){
 // ref = Serial.read();}
 Error=ref-vol;                     //Determina el valor de Error(referencia-valor del sensor)
 Serial.print(" error: ");
 Serial.println(Error);
 //-----------Fuzzificacion-Conjunto-de-Entrada-Error----------
  if(Error<=5.7 && Error>=2){Serial.println("Entro al 1 IF"); //determina Error muy positivo(Emp)
     Ena=2; Enb=3.5; Enc=5; End=5.7;
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
  if(Error<=3 && Error>=0){Serial.println("Entro al 2 IF");//determina Error positivo(Ep)
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
  if(Error<=0.5 && Error>=-0.5){Serial.println("Entro al 3 IF");//determina Error cero(Ez)
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
  if(Error<=0 && Error>=-3){Serial.println("Entro al 4 IF");//determina Error negativo(En)
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
  if(Error<=-2 && Error>=-5.7){Serial.println("Entro al 5 IF");//determina Error muy negativo(Emn)
     Ena=-5.7; Enb=-4; Enc=-3.5; End=-2;
     if(Error<=Ena || Error>=End)
     { Emn=0;}
     else
     if(Error>=Enb && Error<=Enc)
     { Emn=1;}
     else
     if(Error<Enb || Error>Enc)
     {Emn=(Error-Ena)/(Enb-Ena);}
     else
     if(Error<End || Error>Enc)
     {Emn=(Error+Ena)/(End-Enc);}
     else{
     Emn=0;}
     }
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
if(Eprima<=14.5 && Eprima>=5.5){ Serial.println("Entro al 1 IF2"); //determina Error prima muy positivo(Emp)
     Ena=5.5; Enb=8; Enc=10.5; End=14.5;
     if(Eprima<=Ena || Eprima>=End)
     { Emp=0;}
     else
     if(Eprima>=Enb && Eprima<=Enc)
     { Epmp=1;}
     else
     if(Eprima<Enb || Eprima>Ena)
     {Epmp=(Eprima-Ena)/(Enb-Ena);}
     else
     if(Eprima<End || Eprima>Enc)
     {Emp=(Eprima+Ena)/(End-Enc);}
     else{
     Epmp=0;}
     }
  if(Eprima<=7.9 && Eprima>=0){Serial.println("Entro al 2 IF2");//determina Error prima muy positivo(Emp)
     Ena=0; Enb=2; Enc=5.5; End=7.9;
     if(Eprima<=Ena || Eprima>=End)
     { Epp=0;}
     else
     if(Eprima>=Enb && Eprima<=Enc)
     { Epp=1;}
     else
     if(Eprima<Enb || Eprima>Ena)
     {Epp=(Eprima-Ena)/(Enb-Ena);}
     else
     if(Eprima<End || Eprima>Enc)
     {Epp=(Eprima+Ena)/(End-Enc);}
     else{
     Epp=0;}
     }
  if(Eprima<=2 && Eprima>=-2){Serial.println("Entro al 3 IF2");//determina Error prima muy positivo(Emp)
     Ena=-2; Enb=0; Enc=0; End=2;
     if(Eprima<=Ena || Eprima>=End)
     { Epz=0;}
     else
     if(Eprima>=Enb && Eprima<=Enc)
     { Epz=1;}
     else
     if(Eprima<Enb || Eprima>Ena)
     {Epz=(Eprima-Ena)/(Enb-Ena);}
     else
     if(Eprima<End || Eprima>Enc)
     {Epz=(Eprima+Ena)/(End-Enc);}
     else{
     Epz=0;}
     }
  if(Eprima<=0 && Eprima>=-7.9){Serial.println("Entro al 4 IF2");//determina Error prima muy positivo(Emp)
     Ena=-7.9; Enb=-5.5; Enc=-2; End=0;
     if(Eprima<=Ena || Eprima>=End)
     { Epn=0;}
     else
     if(Eprima>=Enb && Eprima<=Enc)
     { Epn=1;}
     else
     if(Eprima<Enb || Eprima>Ena)
     {Epn=(Eprima-Ena)/(Enb-Ena);}
     else
     if(Eprima<End || Eprima>Enc)
     {Epn=(Eprima+Ena)/(End-Enc);}
     else{
     Epn=0;}
     }
  if(Eprima<=-5.5 && Eprima>=-14.5){Serial.println("Entro al 5 IF2");//determina Error prima muy positivo(Emp)
     Ena=-14.5; Enb=-10.5; Enc=-8; End=5.5;
     if(Eprima<=Ena || Eprima>=End)
     { Epmn=0;}
     else
     if(Eprima>=Enb && Eprima<=Enc)
     { Epmn=1;}
     else
     if(Eprima<Enb || Eprima>Enc)
     {Epmn=(Eprima-Ena)/(Enb-Ena);}
     else
     if(Eprima<End || Eprima>Enc)
     {Epmn=(Eprima+Ena)/(End-Enc);}
     else{
     Epmn=0;}
     }
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
MaxOmn=Omn[0];
for (int i=0; i<5; i++){
     if(MaxOmn<Omn[i]){
        MaxOmn=Omn[i];} //Selecciona el maximo Omn
}
On[0]=min(En,Epmn);
On[1]=min(En,Epn);
On[2]=min(En,Epz);
On[3]=min(En,Epp);
On[4]=min(En,Epmp);
On[5]=min(Ez,Epmp);
MaxOn=On[0];
for (int i=0; i<6; i++){
     if(MaxOn<On[i]){
        MaxOn=On[i];}   //Selecciona el maximo On
}
Oz[0]=min(Ez,Epn);
Oz[1]=min(Ez,Epz);
Oz[2]=min(Ez,Epp);
MaxOz=Oz[0];
for (int i=0; i<3; i++){
     if(MaxOz<Oz[i]){
        MaxOz=Oz[i];}    //Selecciona el maximo Oz
}
Op[0]=min(Ep,Epmn);
Op[1]=min(Ep,Epn);
Op[2]=min(Ep,Epz);
Op[3]=min(Ep,Epp);
Op[4]=min(Ep,Epmp);
Op[5]=min(Ez,Epmn);
MaxOp=Op[0];
for (int i=0; i<6; i++){
     if(MaxOp<Op[i]){
        MaxOp=Op[i];}     //Selecciona el maximo Op
}
Omp[0]=min(Emp,Epmn);
Omp[1]=min(Emp,Epn);
Omp[2]=min(Emp,Epz);
Omp[3]=min(Emp,Epp);
Omp[4]=min(Emp,Epmp);
MaxOmp=Omp[0];
for (int i=0; i<5; i++){
     if(MaxOmp<Omp[i]){
        MaxOmp=Omp[i];}  //Selecciona el maximo Omp
}
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
float sump=0, sum=0, Omp1, Op1, Oz1, On1, Omn1;
for (int i=0; i<1023; i=i+10){
  Serial.println(i);
    if(i<=1481 && i>=932){           
     Ena=932; Enb=1176; Enc=1237; End=1481;
     if(i<=Ena || i>=End)
     { Omp1=0;}
     else
     if(i>=Enb && i<=Enc)
     { Omp1=MaxOmp;}
     else
     if(i<Enb || i>Ena)
     {Omp1=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Omp1=(i+Ena)/(End-Enc);}
     else{
     Omp1=0;}
     }
    sum=sum+Omp1;
    sump=sump+(Omp1*i);
    
     if(i<=1110 && i>=623){           
     Ena=623; Enb=888; Enc=888; End=1110;
     if(i<=Ena || i>=End)
     { Op1=0;}
     else
     if(i>=Enb && i<=Enc)
     { Op1=MaxOp;}
     else
     if(i<Enb || i>Enc)
     {Op1=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Op1=(i+Ena)/(End-Enc);}
     else{
     Op1=0;}
     }
    sum=sum+Op1;
    sump=sump+(Op1*i);
     
     if(i<=830 && i>=278){           
     Ena=278; Enb=578; Enc=578; End=830;
     if(i<=Ena || i>=End)
     { Oz1=0;}
     else
     if(i>=Enb && i<=Enc)
     { Oz1=MaxOz;}
     else
     if(i<Enb || i>Ena)
     {Oz1=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Oz1=(i+Ena)/(End-Enc);}
     else{
     Oz1=0;}
     }
    sum=sum+Oz1;
    sump=sump+(Oz1*i);
     
     if(i<=478 && i>=16){           
     Ena=16; Enb=275; Enc=275; End=478;
     if(i<=Ena || i>=End)
     { On1=0;}
     else
     if(i>=Enb && i<=Enc)
     { On1=MaxOn;}
     else
     if(i<Enb || i>Ena)
     {On1=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {On1=(i+Ena)/(End-Enc);}
     else{
     On1=0;}
     }
    sum=sum+On1;
    sump=sump+(On1*i);
     
     if(i<=187 && i>=-291){           
     Ena=-291; Enb=0; Enc=45; End=187;
     if(i<=Ena || i>=End)
     { Omn1=0;}
     else
     if(i>=Enb && i<=Ena)
     { Omn1=MaxOmn;}
     else
     if(i<Enb || i>Enc)
     {Omn1=(i-Ena)/(Enb-Ena);}
     else
     if(i<End || i>Enc)
     {Omn1=(i+Ena)/(End-Enc);}
     else{
     Omn1=0;}
     }
    sum=sum+Omn1;
    sump=sump+(Omn1*i);
 }
//---------------------PWM----------------------
float c, f, CU;
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




