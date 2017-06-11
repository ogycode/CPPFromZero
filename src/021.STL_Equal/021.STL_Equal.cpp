#include "stdafx.h"

using namespace std;

//Определяет, является ли слова палиндромами
void Palindrome(const string &str)
{
	if (equal(str.begin(), str.begin() + str.size() / 2, str.rbegin()))
		cout << str << " is palindrome" << endl;
	else
		cout << str << " is not palindrome" << endl;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("021.STL_Equal");

	vector<int> one
	{
		1,
		1,
		3
	};
	vector<int> two
	{
		1,
		2,
		3
	};

	//equal сравнивает два множества 
	//и возвращает true если они одинаковые
	if (equal(one.begin(), one.end(), two.begin()))
		cout << "Vectors is equals" << endl;
	else
		cout << "Vectors is not equals" << endl;

	Palindrome("Hello");
	Palindrome("No");
	Palindrome("Vadim");
	Palindrome("ABBA");

	system("pause");
    return 0;
}

