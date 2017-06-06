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
	//����� ����� ������� ����� ����������� ����� �� ��� ������ ����� ������������ ������� 
	//���������� ������� ����� ����������� ���������� � ���������� ����
	//��� ������ ����� ����������� ������ ����������� ���� ����������!
	virtual ~Human() = 0;

	virtual Human* Create() = 0;			//������� ������� ����� ������ Humna	{ return new Human();      }
	virtual Human* Clone() = 0;				//������� ��������� ������� ������		{ return new Human(*this); }

	void SetName(string Name);
	string GetName();
	virtual int GetAge();
	//����� ����������� �������, ������ ���� ��������������
	//� ����������� ������
	virtual string Say() = 0;

private:
	int Age;
	string Name;
};

