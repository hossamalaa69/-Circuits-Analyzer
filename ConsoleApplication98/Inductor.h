#pragma once
#include <iostream>
using namespace std;
#include"VoltageSource.h"
class Inductor
{
float Value;
public:
	int P1,P2;
	VoltageSource v;
	Inductor();
	void ReadData();
	float GetValue() const;
	~Inductor();
};

