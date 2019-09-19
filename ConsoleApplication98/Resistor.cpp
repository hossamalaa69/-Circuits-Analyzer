#include "Resistor.h"


Resistor::Resistor()
{
}
void Resistor::ReadData()
{cout<<"Enter value of resistor"<<endl;
cin>>Value;
cout<<"Enter two Nodes which the resistor is between"<<endl;
cin>>P1>>P2;
}
void Resistor::SetValue(float R){Value=R;}
float Resistor::GetValue() const {return Value;}
Resistor::~Resistor(void)
{
}
