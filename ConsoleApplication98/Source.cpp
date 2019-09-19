#include <complex>
#include <iostream>
#include "Resistor.h"
#include "Inductor.h"
#include "Capacitor.h"
#include "VoltageSource.h"
using namespace std;


float GetReq (const Resistor x[],int n)
{ 
float eq=0;
for(int i=0;i<n;i++)
{
if(x[i].P1==x[i+1].P1 && x[i].P2==x[i+1].P2)
	eq+=((x[i].GetValue() * x[i+1].GetValue())/(x[i].GetValue() + x[i+1].GetValue())) - (x[i].GetValue()+x[i+1].GetValue()) ;
}
for(int i=0;i<n;i++)
eq+=x[i].GetValue();
return eq;
}


float GetReq (const Inductor x[],int n)
{ 
float eq=0;
for(int i=0;i<n;i++)
{
if(x[i].P1==x[i+1].P1 && x[i].P2==x[i+1].P2)
	eq+=((x[i].GetValue() * x[i+1].GetValue())/(x[i].GetValue() + x[i+1].GetValue())) - (x[i].GetValue()+x[i+1].GetValue()) ;
}
for(int i=0;i<n;i++)
eq+=x[i].GetValue();
return eq;
}


float GetReq (const Capacitor x[],int n)
{
	float y=0,pr=0,s=0,eq=0;
	for (int i=0;i<n;i++)
		y+=(1.0/x[i].GetValue());

	for (int i=0;i<n;i++)
		if(x[i].P1==x[i+1].P1 && x[i].P2==x[i+1].P2)
		{
			pr+=(1.0/(x[i].GetValue()+x[i+1].GetValue())) ;
			s+=((1.0/x[i].GetValue())+(1.0/x[i+1].GetValue())) ;
		}
		y+=pr-s;
		eq=1.0/y;
		return eq;
}


int main()

{

const float Pi=3.141592654;
float omega;                                  //invoke user to enter value of omega 
cout<<"Enter the value of omega"<<endl;
cin>>omega;


int nN;                                         //invoke user to enter number of nodes
cout<<"enter number of nodes"<<endl;
cin>>nN;

	int nR;                                       //enter number of resisitors
cout<<"enter number of resitors"<<endl;
cin>>nR;

	int nL;                                        //number of inductors
cout<<"enter number of inductors"<<endl;
cin>>nL;
      int nC;                                       //number of capacitors
cout<<"enter number of capacitors"<<endl;
cin>>nC;

      int nV;                                       //number of voltage sources
cout<<"enter number of Voltage Sources"<<endl;
cin>>nV;
    
       //int nI;                                   //number of current sources
//cout<<"enter number of Current Sources"<<endl;
//cin>>nI;

Resistor arrR[20];                              //creating 20 element of "Z" >> resistors,capacitors and inductors  
Inductor arrL[20];
Capacitor arrC[20];
VoltageSource arrV[5];
//CurrentSource arrI[5];

for(int i=0;i<nR;i++) {arrR[i].ReadData();}      //Invoke user to enter all elements of circuits
for(int i=0;i<nL;i++) {arrL[i].ReadData();}
for(int i=0;i<nC;i++) {arrC[i].ReadData();}
for(int i=0;i<nV;i++) {arrV[i].ReadData();}
//for(int i=0;i<nI;i++){arrI[i].ReadData();}

float Rt;                                 //variable which stores equivalent of Resistors
if(nR==1) Rt=arrR[0].GetValue();         //if there's one resistors >>so it's not series or parallel >>so we don't need to call fn. of equivalent
else Rt=GetReq(arrR,nR);                  //calling Fn. of calculating Req

float Veq=0,Peq=0;                             //variable which stores equivalent of VoltageSources
for(int i=0;i<nV;i++)
{
Veq+=arrV[i].GetValue();
Peq+=arrV[i].GetPhase()*Pi/180;						//calculating the total phase
}

float Leq;                                  //variable which stores equivalent of Inductors
if(nL==1) Leq=arrL[0].GetValue();
else Leq=GetReq(arrL,nL);                 

float Ceq;                                             //variable which stores equivalent of Capacitors
if(nC==1) Ceq=arrC[0].GetValue();
else Ceq=GetReq(arrC,nC); 



float Z_real = Rt;                                          //Creating variable which stores Real part of Impedence 
float Z_imag =((Leq*omega)-(1/(Ceq*omega)));              //Creating variable which stores Imaginary part of Impedence 

//cout<<"Impedenece =("<<Z_real<<")+("<<Z_imag<<"j)"<<endl;    //Printing Impedence in "Complex" form
float Zv,Zp,Iv,Ip,I_real,I_imag,Ip2;
Zv=sqrt(Z_real*Z_real+Z_imag*Z_imag);
Zp=atan(Z_imag/Z_real);
Iv=Veq/Zv;		Ip=(Peq-Zp);//gettig the current in exponintial form
Ip2=(Peq-Zp)*Pi/180;
I_real=Iv*cos(Ip);		I_imag=Iv*sin(Ip);					//gettig the current in Complex form



cout<<"Current in Complex =("<<I_real<<")+("<<I_imag<<"j)"<<endl;    //Printing Current in "Complex" form
cout<<"Current in phasor = "<<Iv<<"+"<<"<"<<Ip*180/Pi<<endl;

for(int i=0;i<nN-1;i++)
{cout<<"I"<<i<<i+1<<" = "<<Iv<<" <"<<Ip*180/Pi<<endl;
}
cout<<"I"<<nN<<0<<" = "<<Iv<<" <"<<Ip*180/Pi<<endl;

//for(int i=0;i<nN;i++)
//{	
//for(int j=0;j<nV;j++){if(arrV[j].P1==i&&arrV[j].P2==i+1)
//{
//	cout<<"V = "<<i+1<<arrV[j].GetValue()<<" <"<<arrV[j].GetPhase()<<endl;
//}
//for(int j=0;j<nL;j++){if(arrL[j].P1==i&&arrL[j].P2==i+1){
//	cout<<"V "<<i+1<<"="<<-arrL[j].GetValue()*I_imag<<"+"<<arrL[j].GetValue()*I_real<<"i"<<endl;
//}
//for(int j=0;j<nR;j++){if(arrR[j].P1==i&&arrR[j].P2==0)
//cout<<"V"<<i<<"="<<arrR[j].GetValue()*I_real<<"+"<<I_imag*arrR[j].GetValue()<<"i"<<endl;
//	}}
//}

for (int i=0;i<nR;i++)
{
	arrR[i].v.SetReal(I_real*arrR[i].GetValue());
	arrR[i].v.SetImag(I_imag*arrR[i].GetValue());
}

for(int i=0;i<nC;i++)
{
	float z;
	z=(-1/(omega*arrC[i].GetValue()));
	arrC[i].v.SetReal(-1*I_imag*z);
	arrC[i].v.SetImag(I_real*z);
}

for(int i=0;i<nL;i++)
{
	float z=omega*arrL[i].GetValue();
	arrL[i].v.SetReal(-1*I_imag*z);
	arrL[i].v.SetImag(I_real*z);
}



VoltageSource arrVN[10];
arrVN[0].SetReal(0);
arrVN[0].SetImag(0);


for (int i=1;i<=nN;i++)
{
	for(int j=0;j<nV;j++)
	{
		if(arrV[j].P1==i-1 && arrV[j].P2==i)
		{
			arrVN[i].SetReal(arrVN[i-1].GetReal() - arrV[j].GetReal());
			arrVN[i].SetImag(arrVN[i-1].GetImag() - arrV[j].GetImag());
		}
	}

	for(int j=0;j<nR;j++)
	{
	   if(arrR[j].P1==i-1 && arrR[j].P2==i)
		{
			arrVN[i].SetReal(arrVN[i-1].GetReal() + arrR[j].v.GetReal());
			arrVN[i].SetImag(arrVN[i-1].GetImag() + arrR[j].v.GetImag());
		}
	
	}
	for(int j=0;j<nC;j++)
	{
	   if(arrC[j].P1==i-1 && arrC[j].P2==i)
		{
			arrVN[i].SetReal(arrVN[i-1].GetReal() + arrC[j].v.GetReal());
			arrVN[i].SetImag(arrVN[i-1].GetImag() + arrC[j].v.GetImag());
		}
	}
	for(int j=0;j<nL;j++)
	{
	   if(arrL[j].P1==i-1 && arrL[j].P2==i)
		{
			arrVN[i].SetReal(arrVN[i-1].GetReal() + arrL[j].v.GetReal());
			arrVN[i].SetImag(arrVN[i-1].GetImag() + arrL[j].v.GetImag());
		}
	}

}


for(int i=0;i<=nN;i++)
{
	cout<<"V"<<i<<" = ("<<arrVN[i].GetReal()<<","<<arrVN[i].GetImag()<<"j )"<<endl;
}

system("pause");

return 0;
}

