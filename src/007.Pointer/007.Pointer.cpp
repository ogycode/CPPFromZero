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

	cout << "value = " << value << endl;					//�����������
	cout << "*pointer = " << *pointer << endl;				//�������� ���������� value ����� ���������
	cout << "&value = " << &value << endl;					//������ ���������� value
	cout << "pointer = " << pointer << endl << endl;		//������ ���������� value, �������� ���������� pointer

	value += 20;
	cout << "value += 20, value = " << value << endl;
	*pointer += 20;											//��������� �������� ���������� ����� ���������
	cout << "*pointer += 20, value = " << value << endl << endl;

	//��������� �� �������
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
