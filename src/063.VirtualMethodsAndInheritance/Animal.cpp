#include "stdafx.h"


Animal::Animal()
{
	std::cout << "����������� Animal" << std::endl;
}
Animal::~Animal()
{
	std::cout << "���������� ����� Animal" << std::endl;
}

void Animal::Eat()
{
	std::cout << "�������� ���" << std::endl;
}
void Animal::Say()
{
	std::cout << "�������� �������" << std::endl;
}
