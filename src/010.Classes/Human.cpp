#include "stdafx.h"
#include "Human.h"

Human::Human(string Name)
{
	this->Name = Name;
	this->Age = 0;
}
Human::Human(int Age)
{
	this->Age = Age;
	this->Name = "";
}
Human::Human(string Name, int Age)
{
	this->Name = Name;
	this->Age = Age;
}
Human::Human()
{
	this->Age = 0;
	this->Name = "";
}

Human::~Human() {}

void Human::SetName(string Name)
{
	this->Name = Name;
}
string Human::GetName()
{
	return this->Name;
}
int Human::GetAge()
{
	return Age;
}
