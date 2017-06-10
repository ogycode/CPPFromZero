#include "stdafx.h"

using namespace std;

bool Pred(int i)
{
	return i > 0 && i < 10;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("017.STL_Count Count_If");

	vector<int> b(15);
	b[0] = 42;
	b[1] = 8;
	b[2] = 21;
	b[3] = 76;
	b[4] = 1;
	b[5] = 1;
	b[6] = 1;
	b[7] = 61;
	b[8] = 6;
	b[9] = 1;
	b[10] = 662;
	b[11] = 33;
	b[12] = 42;
	b[13] = 42;
	b[14] = 42;

	//алгоритм count считате количество элементов 
	//равных value, count(start, end, value)
	cout << "Coutn of 42 in vector b : " << count(b.begin(), b.end(), 42) << endl;
	cout << "Coutn of 1 in vector b : " << count(b.begin(), b.end(), 1) << endl;
	cout << "Coutn of 8 in vector b : " << count(b.begin(), b.end(), 8) << endl;
	cout << "Coutn of 0 in vector b : " << count(b.begin(), b.end(), 0) << endl;

	//coutn_if считате количество элементов для 
	//которых предикат возвращает true
	cout << "Count_If of numbers betwen 0 and 10 in vector b : " << count_if(b.begin(), b.end(), Pred) << endl;

	//пример с лямбда-выражением,
	//количество цифер делящихся на 2 без остатка
	cout << "Count_If of Numbers that are divisible by 2 without residue in vector b : " << count_if(b.begin(), b.end(), [](int i) {return i % 2 == 0; }) << endl;

	system("pause");
    return 0;
}

