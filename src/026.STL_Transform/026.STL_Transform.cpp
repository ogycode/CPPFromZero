#include "stdafx.h"

using namespace std;

int SUM(int i, int j)
{
	return i + j;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("026.STL_Transform");

	vector<int> vec(10);
	fill(vec.begin(), vec.end(), 2);

	cout << "Vector befor transform (uno):" << endl;
	for (auto i : vec)
		cout << i << " ";

	//в данном случае transform примен¤ет унарную функцию к каждому элементу колекции
	//в данном случае прибавл¤ет к каждому элементу еденицу
	//и копирует новый елемент в этот же вектор
	//ѕ–»ћ≈– с л¤бда-выражением
	transform(vec.begin(), vec.end(), vec.begin(), [](int i) { return i+1; });

	cout<< endl << "Vector after transform (uno):" << endl;
	for (auto i : vec)
		cout << i << " ";

	vector<int> vec2(10);
	fill(vec2.begin(), vec2.end(), 4);

	//даном случае transform примен¤ет бинарную функцию в которой в качестве 
	//аргументов передаютс¤ одноименные элементы двох векторов
	//в данном случае в первый вектор копируетс¤ сума одноименных
	//векторов
	//ѕ–≈ћ≈– с обычной функцией
	transform(vec.begin(), vec.end(), vec2.begin(), vec.begin(), SUM);

	cout << endl << "Vector after transform (duo):" << endl;
	for (auto i : vec)
		cout << i << " ";
	cout << endl;

	system("pause");
    return 0;
}

