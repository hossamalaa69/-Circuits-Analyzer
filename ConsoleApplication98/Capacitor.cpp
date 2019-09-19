#include "Capacitor.h"


Capacitor::Capacitor(void)
{
}
void Capacitor::ReadData()
{cout<<"Enter value of capactance"<<endl;
cin>>Value;
cout<<"Enter two Nodes which the capastor is between"<<endl;
cin>>P1>>P2;
}

float Capacitor::GetValue()const {return Value;}

Capacitor::~Capacitor(void)
{
}
