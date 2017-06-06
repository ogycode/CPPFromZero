#include "stdafx.h"
#include "ComplexValue.h"

ComplexValue::ComplexValue()
{
	this->re = 0;
	this->im = 0;
}
ComplexValue::ComplexValue(double Re, double Im)
{
	this->re = Re;
	this->im = Im;
}
ComplexValue::~ComplexValue()
{
}

double ComplexValue::GetRe()
{
	return re;
}
double ComplexValue::GetIm()
{
	return im;
}
string ComplexValue::GetValue()
{
	double r = abs(this->re);
	double i = abs(this->im);

	if (im >= 0)
		return to_string(r) + " + i" + to_string(i);

	return to_string(r) + " - i" + to_string(i);
}
void ComplexValue::SetRe(double Re)
{
	this->re = Re;
}
void ComplexValue::SetIm(double Im)
{
	this->im = Im;
}
void ComplexValue::SetValue(double Re, double Im)
{
	this->SetRe(Re);
	this->SetIm(Im);
}

ostream &operator<<(ostream &os, ComplexValue &value)
{
	os << value.GetValue();
	return os;
}
ComplexValue ComplexValue::operator+(ComplexValue value)
{
	return ComplexValue(this->re + value.re, this->im + value.im);
}
ComplexValue ComplexValue::operator-(ComplexValue value)
{
	return ComplexValue(this->re - value.re, this->im - value.im);
}
ComplexValue ComplexValue::operator*(ComplexValue value)
{
	return ComplexValue(this->re*value.re - this->im*value.im, this->re*value.im + this->im*value.re);
}
ComplexValue ComplexValue::operator/(ComplexValue value)
{
	double r;
	double i;

	r = (this->re*value.re + this->im*value.im) / (pow(value.re, 2) + pow(value.im, 2));
	i = (value.re*this->im - this->re*value.im) / (pow(value.re, 2) + pow(value.im, 2));

	return ComplexValue(r, i);
}


