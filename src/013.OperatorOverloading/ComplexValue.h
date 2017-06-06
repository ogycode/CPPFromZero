#pragma once
#include "stdafx.h"
using namespace std;

class ComplexValue
{
private:
	double re;
	double im;

public:
	ComplexValue();
	ComplexValue(double Re, double Im);
	~ComplexValue();

	double GetRe();
	double GetIm();
	string GetValue();
	void SetRe(double Re);
	void SetIm(double Im);
	void SetValue(double Re, double Im);

	friend ostream& operator<<(ostream& os, ComplexValue& vaue);

	ComplexValue operator+(ComplexValue v);
	ComplexValue operator-(ComplexValue v);
	ComplexValue operator*(ComplexValue v);
	ComplexValue operator/(ComplexValue v);
};

