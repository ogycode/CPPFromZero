#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("030.STL_Swap Swap_Ranges Iter_Swap");

	int a = 7;
	int b = 33;

	cout << "Before swap: a=" << a << "; b=" << b << ";" << endl;
	//swap - меняет местами два значения
	swap(a, b);
	cout << "After swap: a=" << a << "; b=" << b << ";" << endl;

	vector<int> vec1(10);
	fill(vec1.begin(), vec1.end(), 5);

	vector<int> vec2(10);
	fill(vec2.begin(), vec2.end(), 2);

	cout << "Vector 1 befor swap_ranges:" << endl;
	for (auto i : vec1)
		cout << i << " ";
	cout << endl << "Vector 2 before swap_ranges:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	//swap_ranges свапает два диапазона
	swap_ranges(vec1.begin(), vec1.end(), vec2.begin());

	cout << endl << "Vector 1 after swap_ranges:" << endl;
	for (auto i : vec1)
		cout << i << " ";
	cout << endl << "Vector 2 after swap_ranges:" << endl;
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;


	vector<int> vec3(10);
	fill_n(vec3.begin(), 5, 5);

	cout << "Vector 3 befor iter_swap:" << endl;
	for (auto i : vec3)
		cout << i << " ";

	//iter_swap свапает элементы на которые указывают итераторы
	iter_swap(vec3.begin(), vec3.begin() + 7);

	cout << endl << "Vector 3 after iter_swap:" << endl;
	for (auto i : vec3)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}

