#pragma once
#include <iostream>
using namespace std;

class VoltageSource
{float Value,Phase,Real,Imag;
public:
	int P1,P2;
	VoltageSource();
	void ReadData();
	float GetValue();
	float GetPhase();
	~VoltageSource();
	void SetReal(float);
	void SetImag(float);
	float GetReal();
	float GetImag();
	
};

