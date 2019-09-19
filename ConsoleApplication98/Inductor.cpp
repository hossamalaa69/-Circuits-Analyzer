#include "Inductor.h"


Inductor::Inductor(void)
{
}

void Inductor::ReadData()
{cout<<"Enter value of inductance"<<endl;
cin>>Value;
cout<<"Enter two Nodes which the inductor is between"<<endl;
cin>>P1>>P2;
}

float Inductor::GetValue()const{return Value;}

Inductor::~Inductor(void)
{
}
