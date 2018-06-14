#include "stdafx.h"


Animal::Animal()
{
	std::cout << "Конструктор Animal" << std::endl;
}
Animal::~Animal()
{
	std::cout << "Деструктор класс Animal" << std::endl;
}

void Animal::Eat()
{
	std::cout << "Животное ест" << std::endl;
}
void Animal::Say()
{
	std::cout << "Животное говорит" << std::endl;
}
