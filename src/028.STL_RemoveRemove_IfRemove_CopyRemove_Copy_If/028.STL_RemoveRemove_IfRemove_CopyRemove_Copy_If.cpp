#include "stdafx.h"

using namespace std;

bool Pred(const int &i)
{
	return i < 0;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("028.STL_Remove Remove_If Remove_Copy Remove_Copy_If");

	vector<int> vec(10);
	fill(vec.begin(), vec.end(), 4);
	fill_n(vec.begin(), 7, 5);
	fill_n(vec.begin(), 5, -3);

	cout << "Vector before remove:" << endl;

	for (auto i : vec)
		cout << i << " ";

	//remove удаляет все элементы которые равны указаному value
	remove(vec.begin(), vec.end(), 5);
	cout << endl << "Vector after remove:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//remove_if удаляет все элементы для которых предикант возвращает true
	remove_if(vec.begin(), vec.end(), Pred);
	cout << endl << "Vector after remove_if:" << endl;
	for (auto i : vec)
		cout << i << " ";

	fill_n(vec.begin(), 7, 5);
	fill_n(vec.begin(), 5, -3);

	vector<int> vec2(10);

	//remove_copy копирует все элементы в новое расположение
	//если они не равны value
	remove_copy(vec.begin(), vec.end(), vec2.begin(), 5);
	cout << endl << "Vector after remove_copy:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	fill(vec2.begin(), vec2.end(), 0);

	//remove_copy_if копирует элементы в новое расположение
	//если предикант возвращает false для этого элемента
	remove_copy_if(vec.begin(), vec.end(), vec2.begin(), Pred);
	cout << endl << "Vector after remove_copy_if:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	cout << endl;

	system("pause");
    return 0;
}

