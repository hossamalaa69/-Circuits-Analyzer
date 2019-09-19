#pragma once
#include <iostream>
#include"VoltageSource.h"
using namespace std;

class Resistor
{float Value;
public:
	int P1,P2;
	VoltageSource v;
	Resistor();
	void ReadData();
	void SetValue(float);
	float GetValue() const;
	~Resistor();
};

