#include "stdafx.h"

using namespace std;

bool Pred(const int &i)
{
	return i % 2 == 0;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("023.STL_Copy Copy_If Copy_N Copy_Backward");

	vector<int> source{ 0,1,2,3,4,5,6,7,8,9 };

	vector<int> place(10);

	//copy копирует диапазон в другой вектор
	copy(source.begin(), source.end(), place.begin());
	cout << "place:" << endl;
	for (auto i : place)
		cout << i << endl;

	//copy_if копирует елементы из диапазона 
	//для которых предикат возвращает true
	vector<int> place2(5);
	copy_if(source.begin(), source.end(), place2.begin(), Pred);
	cout << "place2:" << endl;
	for (auto i : place2)
		cout << i << endl;

	//copy_n копирует указаное количество элементов
	vector<int> place3(3);
	copy_n(source.begin(), 3, place3.begin());
	cout << "place3:" << endl;
	for (auto i : place3)
		cout << i << endl;

	//copy_backward копирует вектор в конец другого вектора
	vector<int> place4(15);
	copy_backward(source.begin(), source.end(), place4.end());
	cout << "place4:" << endl;
	for (auto i : place4)
		cout << i << endl;

	system("pause");
	return 0;
}

