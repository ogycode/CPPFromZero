#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("037.STL_Binary search");

	vector<int> vec{ 1,2,3,4,5,5,5,5,6,6,7,8,9 };

	//lower_bound возвращает итератор на первый элемент меньше чем заданое значение
	//upper_bound возвращает итератор на первый элемент больше чем заданое значение
	//возможно использование предикантов
	//ТОЛЬКО НА ОТСОРТИРОАНЫХ ДИАПАЗОНАХ
	auto low = lower_bound(vec.begin(), vec.end(), 5);
	auto upr = upper_bound(vec.begin(), vec.end(), 5);

	cout << "Range of low and upper (5):" << endl;
	copy(low, upr, ostream_iterator<int>(cout, " "));

	//binary_search возвращает true если в диапазоне есть элмент равный указаному значению
	//или удовлетвор¤ещее предиканту
	//ТОЛЬКО НА ОТСОРТИРОАНЫХ ДИАПАЗОНАХ

	vector<int> vec2{ 1,1,1,1,3,7,8,8,8,8,9,10 };

	//equal_range возвращает пару на начало и конец диапазона равный указаному значению
	//ТОЛЬКО НА ОТСОРТИРОАНЫХ ДИАПАЗОНАХ
	auto range = equal_range(vec2.begin(), vec2.end(), 8);

	cout << endl << "Equal range by 8:" << endl;
	for (auto i = range.first; i != range.second; ++i)
		cout << *i << " ";

	cout << endl;
	system("pause");
    return 0;
}

