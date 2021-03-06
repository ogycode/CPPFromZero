#include "stdafx.h"


int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle(TEXT("063.Virtual Methods And Inheritance"));

	std::cout << "Наследоване:" << std::endl;
	{
		//При использовании виртуальных функций при наследовании, елси наследник
		//не переопределил функцию то используется функция базового класса
		//					Base
		//                  |  |
		//                |       |
		//       Child1 (no)	Child2(yes)
	    //                |       |
		//                  |  |
		//  Child3(no, использует функцию Child2)

		std::cout << "Cat" << std::endl;
		Cat cat;

		cat.Eat();
		cat.Say();

		std::cout << std::endl << "Lion" << std::endl;
		Lion lion;

		lion.Eat();
		lion.Say();

		std::cout << std::endl << "Tiger" << std::endl;
		Tiger tiger;

		tiger.Eat();
		tiger.Say();

		std::cout << std::endl;
	}

	std::cout << std::endl << "Масив 'базового' типа:" << std::endl;

	{
		const int size = 3;
		Animal* animals[size];

		animals[0] = new Cat();
		animals[1] = new Lion();
		animals[2] = new Tiger();

		std::cout << "Проход по списку:" << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			animals[i]->Say();
			delete animals[i];
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "Наследование:" << std::endl;

	{
		PublicAnimal publicAnimal;		//при публичном наследовании Public -> Public, Protected - Protected, Private - Private
										//при приватном наследовании Public -> Private, Protected - Private, Private - Private
		publicAnimal.Eat();				//при протектед наследовании Public -> Protected, Protected - Protected, Private - Private
		publicAnimal.Say();
	}

	system("pause");

    return 0;
}







/*OUTPUT
	Наследоване:
	Cat
	Конструктор Animal
	Конструктор Cat
	Животное ест
	Кот говорит

	Lion
	Конструктор Animal
	Конструктор Lion
	Животное ест
	Лев говрит

	Tiger
	Конструктор Animal
	Конструктор Cat
	Конструктор Lion
	Конструктор Tiger
	Животное ест
	Тигр говрит

	Деструктор Tiger
	Деструктор Lion
	Деструктор Cat
	Деструктор класс Animal
	Деструктор Lion
	Деструктор класс Animal
	Деструктор Cat
	Деструктор класс Animal

	Масив 'базового' типа:
	Конструктор Animal
	Конструктор Cat
	Конструктор Animal
	Конструктор Lion
	Конструктор Animal
	Конструктор Cat
	Конструктор Lion
	Конструктор Tiger
	Проход по списку:
	Кот говорит
	Деструктор Cat
	Деструктор класс Animal
	Лев говрит
	Деструктор Lion
	Деструктор класс Animal
	Тигр говрит
	Деструктор Tiger
	Деструктор Lion
	Деструктор Cat
	Деструктор класс Animal


	Наследование private:
	Конструктор Animal
	Конструктор Public животного
	Животное ест
	Животное говорит
	Деструктор Public животного
	Деструктор класс Animal
*/