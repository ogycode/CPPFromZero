#include "stdafx.h"

Cat::Cat()
{
	std::cout << "Конструктор Cat" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Деструктор Cat" << std::endl;
}

void Cat::Say()
{
	std::cout << "Кот говорит" << std::endl;
}
