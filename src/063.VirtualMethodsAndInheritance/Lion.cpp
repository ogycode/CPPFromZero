#include "stdafx.h"

Lion::Lion()
{
	std::cout << "Конструктор Lion" << std::endl;
}
Lion::~Lion()
{
	std::cout << "Деструктор Lion" << std::endl;
}

void Lion::Say()
{
	std::cout << "Лев говрит" << std::endl;
}
