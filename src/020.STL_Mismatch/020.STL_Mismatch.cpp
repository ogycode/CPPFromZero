#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("020.STL_Mismatch");

	vector<int> one
	{
		1,
		2,
		3,
		4,
		6,
		6
	};
	vector<int> two
	{
		1,
		2,
		4,
		4,
		5,
		6
	};

	//mismatch сравнивает два множества и возвращает pair содержащую
	//итареторы на непохожие элементы, в случае выше алгоритм
	//вернет итераторы на 3 и 4
	pair<vector<int>::iterator, vector<int>::iterator> p = mismatch(one.begin(), one.end(), two.begin());

	cout << "Equals elements: " << endl;
	for (vector<int>::iterator i = one.begin(); i != p.first; i++)
	{
		cout << *i << endl;
	}

	//определим зеркальность колекции элементов
	vector<int> mirror
	{
		1,
		2,
		3,
		4,
		3,
		2,
		1
	};
	vector<int> noMirror
	{
		1,
		2,
		3,
		4,
		2,
		2,
		1
	};
	cout << "Vector mirror:" << endl;
	pair<vector<int>::iterator, vector<int>::reverse_iterator> p2 = mismatch(mirror.begin(), mirror.end(), mirror.rbegin());
	if (p2.first == mirror.end())
		cout << "Vector is mirror" << endl;
	else
		cout << "Vector is not mirror" << endl;

	cout << "Vector noMirror:" << endl;
	pair<vector<int>::iterator, vector<int>::reverse_iterator> p3 = mismatch(noMirror.begin(), noMirror.end(), noMirror.rbegin());
	if (p3.first == noMirror.end())
		cout << "Vector is mirror" << endl;
	else
		cout << "Vector is not mirror" << endl;

	system("pause");
    return 0;
}

