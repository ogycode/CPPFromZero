#include "stdafx.h"

using namespace std;

struct Sum {
	Sum() { sum = 0; }
	void operator()(int n) { sum += n; }

	int sum;
};

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("019.STL_ForEach RangeFor");

	vector<int> vec
	{
		0,
		1,
		2,
		3,
		4
	};

	//вывод значения вектора с помощью range for
	//доступ с помощью ссылок 
	//возможна запись (int i : vec)
	cout << "Vector before using ForEach:" << endl;
	for (int &i : vec)
		cout << i << endl;

	//применит функцию-предикант к каждому элементу коллекции
	for_each(vec.begin(), vec.end(), [](int &i) { return i++; });

	//вывод значения вектора с помощью range for
	//без указания типа элемента коллекции
	//сокращает запись в некоторых случаях
	cout << endl << "Vector after using ForEach:" << endl;
	for (auto i : vec)
		cout << i << endl;

	//Таким образом можно вывести сумму всех элементов колекции
	Sum s = for_each(vec.begin(), vec.end(), Sum());
	cout << "Sum of all numbers in vector : " << s.sum << endl;

	system("pause");
	return 0;
}

