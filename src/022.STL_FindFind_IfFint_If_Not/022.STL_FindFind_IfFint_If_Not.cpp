#include "stdafx.h"

using namespace std;

bool Pred(const int &i)
{
	return (i * 3) + 2 == 2;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("022.STL_Find Find_If Find_If_Not");

	vector<int>vec{ 0,1,2,3,4,5,6,7,8,9 };
	int i = 0;
	cout << "What number are you want to find? (elem == i): ";
	cin >> i;
	//find возвращает итератор на элемент которые равен value
	auto result = find(vec.begin(), vec.end(), i);
	if (result != vec.end())
		cout << i << " is in vector!" << endl;
	else
		cout << i << " is not in vector!" << endl;

	//find_if возвращает итератор на элемент дл¤ которого
	//предикант возвращает true
	auto result2 = find_if(vec.begin(), vec.end(), Pred);
	if (result2 != vec.end())
		cout << *result2 << " is in vector!" << endl;
	else
		cout << "Vector dont have that element is not in vector!" << endl;

	//find_if_not возвращает итератор на элемент
	//дл¤ которого предикат возвращает false
	auto result3 = find_if_not(vec.begin(), vec.end(), Pred);
	if (result3 != vec.end())
		cout << *result3 << " is in vector!" << endl;
	else
		cout << "Vector dont have that element is not in vector!" << endl;

	system("pause");
    return 0;
}

