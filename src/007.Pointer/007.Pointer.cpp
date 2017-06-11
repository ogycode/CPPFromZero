#include "stdafx.h"

using namespace std;

int Sum(int, int);

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("007.Pointer");

	int value = 10;
	int *pointer = &value;

	cout << "value = " << value << endl;					//переменнна
	cout << "*pointer = " << *pointer << endl;				//значение переменной value через указатель
	cout << "&value = " << &value << endl;					//аддрес переменной value
	cout << "pointer = " << pointer << endl << endl;		//аддрес переменной value, значение переменной pointer

	value += 20;
	cout << "value += 20, value = " << value << endl;
	*pointer += 20;											//изменение значение переменной через указатель
	cout << "*pointer += 20, value = " << value << endl << endl;

	//Указатель на функцию
	int(*ptrSum)(int, int) = Sum;
	cout << "Sum(1,1) = " << Sum(1, 1) << endl;
	cout << "ptrSum(1,1) = " << ptrSum(1, 1) << endl;

	system("pause");
	return 0;
}

int Sum(int a, int b)
{
	return a + b;
}
