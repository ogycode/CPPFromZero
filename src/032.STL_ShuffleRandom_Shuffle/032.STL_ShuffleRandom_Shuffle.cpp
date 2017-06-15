#include "stdafx.h"

using namespace std;

int myRandom(int i)
{
	return rand() % i;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("032.STL_Shuffle Random_Shuffle");

	//для адекватной работы страндартнго генератора рандомных чисел
	//std::rand()
	srand(unsigned(time(0)));

	//генератор случайных чисел
	random_device rd;
	mt19937 g(rd());

	vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	cout << "Vector befor shuffle:" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	//shuffle перемешивает случайным образом элементы в коллекции
	//принимет в качестве параметро начало и конец диапазона, а
	//также функции генерирующую слечайные числа
	shuffle(vec.begin(), vec.end(), g);

	cout << "Vector after shuffle:" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	vector<int> vec2{ 1,2,3,4,5,6,7,8,9 };

	cout << "Vector 2 befor shuffle:" << endl;
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	//random_shuffle перемешивает диапазон в случайном поряде, по умолчанеию 
	//использует стандартный генератор случайных чисел
	//также возможно передать свою функцию которая принимает один аргумент
	random_shuffle(vec2.begin(), vec2.end(), myRandom);

	cout << "Vector 2 after shuffle:" << endl;
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}

