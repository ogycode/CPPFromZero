#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("0014.STL_Vector");

	int vectorSize = 0;
	cout << "Enter size of vector: ";
	cin >> vectorSize;

	//вектор на указаное кличество элементов, заполненый нулями
	vector<int> intVector(vectorSize);					

	//C++ 11, генератор случайных чисел
	//c 1 по 200
	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 200);

	//заполняем вектор случайными значениями
	for (size_t i = 0; i < vectorSize; i++)
		intVector[i] = distribution(generator);

	cout << "Vector is created! Vector:" << endl;
	for (size_t i = 0; i < intVector.size(); i++)
		cout << "intVector[" << i << "] : " << intVector[i] << endl;

	//добовляем значение в конец ветора
	int value = 0;
	cout << endl << "Add to end new value: ";
	cin >> value;
	intVector.push_back(value);
	cout << "Vector with added value to back:" << endl;
	for (size_t i = 0; i < intVector.size(); i++)
		cout << "intVector[" << i << "] : " << intVector[i] << endl;

	//добовляем элемент в начало
	cout << endl << "Add to begin new value: ";
	cin >> value;
	intVector.insert(intVector.begin(), value);
	cout << "Vector with added value to begin:" << endl;
	for (size_t i = 0; i < intVector.size(); i++)
		cout << "intVector[" << i << "] : " << intVector[i] << endl;

	cout << endl << "Vector inforation:" << endl;
	cout << "intVector.size() : " << intVector.size() << endl;
	cout << "intVector.max_size() : " << intVector.max_size() << endl;
	cout << "intVector.empty() : " << intVector.empty() << endl;
	cout << "intVector.capacity() : " << intVector.capacity() << endl;

	system("pause");
	return 0;
}

