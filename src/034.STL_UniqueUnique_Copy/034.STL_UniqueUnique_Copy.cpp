#include "stdafx.h"

using namespace std;

bool Pred(const int &i, const int &g)
{
	return i == g;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("034.STL_Unique Unique_Copy");

	vector<int> vec{ 1,3,4,4,4,4,67,4,55,2,2,2,2,4,1,5 };

	//отсортируем вектор дл¤ стабильной работы алгоритма unique
	sort(vec.begin(), vec.end());

	cout << "Vector befor unique:" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	//коди ниже удал¤ет элементы в диапазоне которые повтор¤ютс¤ оставл¤¤ только первое вхождение
	//этого элемента в коллекции, т.е. коллекци¤ не будет иметь одинаковых элементов
	//так как алгоритм перезаписует некторые элементы и не измен¤ет размера коллекции
	//то необходимо удалить неопределенные элементы методом erase
	auto iter = unique(vec.begin(), vec.end(), Pred);
	vec.erase(iter, vec.end());

	cout << "Vector after unique:" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	vector<int> vec2{ 4,55,11,11,11,34,5,6,6,3,32,2,22,4,66,66,6,5,5,3,3,5 };

	//отсортируем вектор дл¤ стабильной работы алгоритма unique
	sort(vec2.begin(), vec2.end());

	vector<int> vec3;

	cout << "Vector 2 befor unique_copy:" << endl;
	for (auto i : vec2)
		cout << i << " ";
	cout << endl;

	//unique_copy делает тоже самое, что и unique но при этом копирует
	//элементы в новое расположение Ѕ≈« похожих элементов
	unique_copy(vec2.begin(), vec2.end(), back_inserter(vec3), Pred);

	cout << "New vector after unique_copy:" << endl;
	for (auto i : vec3)
		cout << i << " ";
	cout << endl;

	system("pause");
    return 0;
}

