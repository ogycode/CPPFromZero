#pragma once
#include "stdafx.h"
using namespace std;
class Human
{
public:
	Human(string Name);
	Human(int Age);
	Human(string Name, int Age);
	Human();
	//Когда нужно создать чисто вирутальный класс но нет других чисто виртулальных функций 
	//необходимо создать чисто вирутальный деструктор и определить тело
	//для других чисто виртуальных функци определение тела ЗАПРЕЩЕННО!
	virtual ~Human() = 0;

	virtual Human* Create() = 0;			//Функция создаст новый обьект Humna	{ return new Human();      }
	virtual Human* Clone() = 0;				//Фугкция скопирует текущий обьект		{ return new Human(*this); }

	void SetName(string Name);
	string GetName();
	virtual int GetAge();
	//чисто виртуальная функция, должна быть переопределена
	//в производном классе
	virtual string Say() = 0;

private:
	int Age;
	string Name;
};

