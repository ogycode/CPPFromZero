#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("024.STL_Move Move_Backward");

	vector<int> vec(20);

	for (size_t i = 0; i < 5; i++)
		vec[i] = i + 1;

	cout << "Vector befor moving:" << endl;
	for (auto i : vec)
		cout << i << " ";
	
	//move перемещает диапазон элементов в другой диапазон
	//по сути алгоритм копирует диапазон, т.е. в старом диапазоне 
	//возможно останется валидные значения
	move(vec.begin(), vec.begin() + 5, vec.begin() + 10);
	cout << endl << "Vector after moving:" << endl;
	for (auto i : vec)
		cout << i << " ";

	vector<int> vec2(10);

	for (size_t i = 0; i < 5; i++)
		vec2[i] = i + 1;

	cout << endl << "Vector 2 befor moving:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	//move_backward перемещает элементы диапазона в конец другого диапазона
	//по сути копирует задом-наперед диапазон
	move_backward(vec2.begin(), vec2.begin() + 5, vec2.end());
	cout << endl << "Vector 2 after moving:" << endl;
	for (auto i : vec2)
		cout << i << " ";

	cout << endl;

	system("pause");
    return 0;
}

