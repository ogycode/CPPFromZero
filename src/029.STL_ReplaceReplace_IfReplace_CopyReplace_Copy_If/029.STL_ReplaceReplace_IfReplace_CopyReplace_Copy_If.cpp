#include "stdafx.h"

using namespace std;

bool Pred(const int &i)
{
	return i == 1;
}
bool Pred2(const int &i)
{
	return i < 0;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("029.STL_Remove Remove_If Remove_Copy Remove_Copy_If");

	vector<int> vec(10);

	cout << "Vector before replace:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//replace заменяет элементы в диапазоне
	//(указаные на указаные)
	replace(vec.begin(), vec.end(), 0, 1);

	cout << endl << "Vector after replace:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//replace_if заменяет элементы указаным значением для котрого 
	//предикант возсращает true
	replace_if(vec.begin(), vec.end(), Pred, 2);

	cout << endl << "Vector after replace_if:" << endl;
	for (auto i : vec)
		cout << i << " ";

	vector<int> vec2(10);

	cout << endl << "Vector 2 before replace_copy:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	//replace_copy копирует элементы в новое расположение
	//при этом замен¤ет элементы которые равны указаному 
	//значению на новое указаное значение
	replace_copy(vec.begin(), vec.end(), vec2.begin(), 2, 3);

	cout << endl << "Vector 2 after replace_copy:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	fill_n(vec.begin(), 4, -6);

	cout << endl << "Vector before replace_copy_if:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//replace_copy_if копирует диапазон в указаное место
	//заменяет елементы к которым предикант возвращает true
	//на указаные элемент
	replace_copy_if(vec.begin(), vec.end(), vec2.begin(), Pred2, 55);

	cout << endl << "Vector 2 after replace_copy_if:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	cout << endl;

	system("pause");
    return 0;
}

