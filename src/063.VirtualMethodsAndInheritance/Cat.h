#pragma once
#include "Animal.h"
class Cat : virtual public Animal
{
public:
	Cat();
	~Cat();

	virtual void Say();
};

