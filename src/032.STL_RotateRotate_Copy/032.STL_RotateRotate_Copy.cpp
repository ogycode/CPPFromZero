#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("032.STL_RotateRotate_Copy");

	vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };

	cout << "Vector before rotate:" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	//rotate совершает перестановку элементов пока 
	//элемент middle не станет на первое место
	rotate(vec.begin(), vec.begin() + 3, vec.end());

	cout << "Vector after rotate:" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	vector<int> vec2(10);

	cout << "Vector 2 before rotate_copy:" << endl;
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	//делаето тоже самое, что и rotate только копирует этот диапазон
	//в указаное расположение
	rotate_copy(vec.begin(), vec.begin() + 2, vec.end(), vec2.begin());

	cout << "Vector 2 after rotate_copy:" << endl;
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	system("pause");
    return 0;
}

