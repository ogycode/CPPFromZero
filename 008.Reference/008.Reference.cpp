#include "stdafx.h"

using namespace std;

int SumByValue(int);
int SumByReference(int &);
int SumByReference2(const int &);
int SumByPointer(int *);

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("008.Reference");

	int value = 99;
	int &ref = value;

	cout << "value = " << value << endl;
	cout << "ref = " << ref << endl << endl;

	cout << "Change value:" << endl;
	value++;
	cout << "value = " << value << endl;
	cout << "ref = " << ref << endl << endl;

	cout << "Change ref:" << endl;
	ref++;
	cout << "value = " << value << endl;
	cout << "ref = " << ref << endl << endl;

	cout << "Function:" << endl;
	int func = 10;
	cout << "value = " << func << endl;
	cout << "SumByValue(func) = " << SumByValue(func) << endl;
	cout << "value = " << func << endl;
	cout << "SumByReference(func) = " << SumByReference(func) << endl;
	cout << "value = " << func << endl;
	cout << "SumByReference2(func) = " << SumByReference2(func) << endl;
	cout << "value = " << func << endl;
	cout << "SumByPointer(&func) = " << SumByPointer(&func) << endl;
	cout << "value = " << func << endl;

	system("pause");
    return 0;
}

int SumByValue(int value)
{
	value += value;
	return value;
}
int SumByReference(int &ref) 
{
	ref += ref;
	return ref;
}
int SumByReference2(const int &ref)
{
	//ref += ref;
	return ref + ref;
}
int SumByPointer(int *prt)
{
	*prt += *prt;
	return *prt;
}