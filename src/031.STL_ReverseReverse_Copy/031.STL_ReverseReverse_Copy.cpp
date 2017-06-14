#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("031.STL_ReverseReverse_Copy");

	vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };

	cout << "Vector befor reverse:" << endl;

	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	//reverse изменяет порядок элементов на противоположный
	reverse(vec.begin(), vec.end());

	cout << "Vector after reverse:" << endl;

	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	vector<int> vec2(10);

	cout << "Vector 2 befor reverse_copy:" << endl;

	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	//reverse_copy копирует диапазон в другое место при этом
	//меняет порядок элементов на противоположный
	reverse_copy(vec.begin(), vec.end(), vec2.begin());

	cout << "Vector 2 befor reverse_copy:" << endl;

	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	system("pause");
    return 0;
}

