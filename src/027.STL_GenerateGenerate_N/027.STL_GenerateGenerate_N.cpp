#include "stdafx.h"

using namespace std;

int RandValue()
{
	return 4;
}
int RandValue2()
{
	return 5;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("027.STL_Generate Generate_N");

	vector<int> vec(10);

	cout << "Vector before using generate algorithm:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//алгоритмя genearte сохраняет в вектор результат работы функции
	generate(vec.begin(), vec.end(), RandValue);

	//алгоритм generate_n сохраняет в вектор результат
	//работы функции указаное количество раз
	generate_n(vec.begin(), 4, RandValue2);

	cout << endl << "Vector after using generate:" << endl;
	for (auto i : vec)
		cout << i << " ";

	cout << endl;

	system("pause");
    return 0;
}

