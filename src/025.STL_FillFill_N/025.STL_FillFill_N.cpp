#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("025.STL_Fill Fill_N");

	vector<int> vec(10);

	cout << "Vector befor filling:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//fill заполняет коллекцию указаным элементом
	fill(vec.begin(), vec.end(), 9);
	cout << endl << "Vector after filling:" << endl;
	for (auto i : vec)
		cout << i << " ";

	//fill_n заполяет указаное количество элементов 
	//указаным элементом
	fill_n(vec.begin(), 4, 6);
	cout << endl << "Vector after filling:" << endl;
	for (auto i : vec)
		cout << i << " ";

	cout << endl;

	system("pause");
    return 0;
}

