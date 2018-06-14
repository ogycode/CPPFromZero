#include "stdafx.h"

Tiger::Tiger()
{
	std::cout << "Конструктор Tiger" << std::endl;
}
Tiger::~Tiger()
{
	std::cout << "Деструктор Tiger" << std::endl;
}

void Tiger::Say()
{
	std::cout << "Тигр говрит" << std::endl;
}
