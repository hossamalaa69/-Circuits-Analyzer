#pragma once
#include <iostream>
using namespace std;
#include"VoltageSource.h"

class Capacitor
{float Value;
public:
	int P1,P2;
	VoltageSource v;
	Capacitor();
	void ReadData();
	float GetValue() const;
	~Capacitor();
};

