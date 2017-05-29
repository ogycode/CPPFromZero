#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("007.Pointer");

	int *p1 = new int;
	int *p2 = new int(8);
	int *p3 = new int(8);

	cout << "Non-init pointer" << endl;
	cout << "p1=\t" << p1 << endl;
	cout << "&p1=\t" << &p1 << "\t(address of p1)" << endl;
	cout << "*p1=\t" << *p1 << "\t\t(value of p1)" << endl << endl;

	cout << "Init pointer" << endl;
	cout << "p2=\t" << p2 << endl;
	cout << "&p2=\t" << &p2 << "\t(address of p2)" << endl;
	cout << "*p2=\t" << *p2 << "\t\t\t(value of p2)" << endl << endl;

	cout << "After operation:" << endl;
	*p1 = 4;
	cout << "p1=\t" << p1 << endl;
	cout << "&p1=\t" << &p1 << "\t(address of p1)" << endl;
	cout << "*p1=\t" << *p1 << "\t\t\t(value of p1)" << endl << endl;

	*p3 = *p1 + *p2;
	cout << "*p3 = *p1+*p2 = " << *p3 << endl;
	cout << "p1=\t" << p1 << endl;
	cout << "&p1=\t" << &p1 << "\t(address of p1)" << endl;
	cout << "*p1=\t" << *p1 << "\t\t\t(value of p1)" << endl << endl;
	cout << "p2=\t" << p2 << endl;
	cout << "&p2=\t" << &p2 << "\t(address of p2)" << endl;
	cout << "*p2=\t" << *p2 << "\t\t\t(value of p2)" << endl << endl;

	cout << "Value and PValue:" << endl;
	int value = 7;
	int *pvalue = &value;

	cout << "value=\t" << value << endl;
	cout << "pvalue=\t" << pvalue << endl;
	cout << "*pvalue=\t" << *pvalue << endl;
	cout << "&pvalue=\t" << &pvalue << endl << endl;

	cout << "After actions (pvalue += 1):" << endl;
	pvalue += 1;										//work with pointer
	cout << "pvalue=\t\t" << pvalue << endl;
	cout << "*pvalue=\t" << *pvalue << endl;
	cout << "&pvalue=\t" << &pvalue << endl;
	pvalue -= 1;

	cout << "After actions (*pvalue += 1):" << endl;
	*pvalue += 1;										//work with value
	cout << "pvalue=\t\t" << pvalue << endl;
	cout << "*pvalue=\t" << *pvalue << endl;
	cout << "&pvalue=\t" << &pvalue << endl;

	system("pause");
    return 0;
}

