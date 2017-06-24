#include "stdafx.h"

using namespace std;

bool Pred(int i, int j)
{
	return j > i;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("036.STL_Sort and etc.");

	cout.setf(ios_base::boolalpha);

	vector<int> vec{ 5,6,3,4,5,5,6,7,8,9,2,3,4,5 };

	cout << "Vector :";
	for (auto i : vec)
		cout << i << " ";

	//is_sorted возвращает true если диапазон отсортирован согласно предиканту
	//или по возрастанию, если предиканта нет
	cout << "is_sorted: " << is_sorted(vec.begin(), vec.end(), Pred) << endl;

	//sort			- сортирует в порядке возростания, возможно применить предикант для кастомного сортирования
	//partial_sort	- сортирует указаный диапазон в диапазоне
	//partial_sort_copy		- partial_sort_copy тоже, что и partial_sort но копирует отсортированый поддиапазон в новое расположение
	//stable_sort	- тоже, что и sort но сохраняет начальный порядок равных элементов
	sort(vec.begin(), vec.end(), Pred);

	cout << "After sort:" << endl << "Vector :";
	for (auto i : vec)
		cout << i << " ";

	cout << "is_sorted: " << is_sorted(vec.begin(), vec.end(), Pred) << endl;

	system("pause");
    return 0;
}

