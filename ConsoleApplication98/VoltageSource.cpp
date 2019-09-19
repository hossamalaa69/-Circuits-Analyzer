#include "VoltageSource.h"


VoltageSource::VoltageSource(void)
{
}
void VoltageSource::ReadData()
{cout<<"Enter value of Voltage Source"<<endl;
cin>>Value;
cout<<"Enter the phase of the Source in degrees"<<endl;
cin>>Phase;
cout<<"Enter two Nodes which the Source is between"<<endl;
cin>>P1>>P2;
Real=Value*cos(Phase*3.14/180);
Imag=Value*sin(Phase*3.14/180);
}

float VoltageSource::GetValue(){return Value;}
float VoltageSource::GetPhase(){return Phase;}
void VoltageSource::SetReal(float A) {Real=A;}
void VoltageSource::SetImag(float i) {Imag=i;}
float VoltageSource::GetReal() {return Real;}
float VoltageSource::GetImag() {return Imag;}
VoltageSource::~VoltageSource()
{
}
