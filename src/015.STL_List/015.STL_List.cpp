#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("0015.STL_List");

	list<int> intList1;
	list<int> intList2;
	int listSize = 0;

	cout << "Enter the list size: ";
	cin >> listSize;

	default_random_engine generator;
	uniform_int_distribution<int> distribution(1, 200);

	//��������� ������ �������� ����������� �����
	for (size_t i = 0; i < listSize; i++)
		intList1.push_back(distribution(generator));

	for (size_t i = 0; i < listSize; i++)
		intList2.push_back(distribution(generator));

	//������� ������
	cout << "List #1:" << endl;
	for (list<int>::iterator it = intList1.begin(); it != intList1.end(); it++)
		cout << "intList1 : " << *it << endl;

	cout << endl << "List #2:" << endl;
	for (list<int>::iterator it = intList2.begin(); it != intList2.end(); it++)
		cout << "intList2 : " << *it << endl;

	//��������� ������ �� �����������
	intList1.sort();
	intList2.sort();

	//������� �������������� ������
	cout << endl << "Sorted List #1:" << endl;
	for (list<int>::iterator it = intList1.begin(); it != intList1.end(); it++)
		cout << "intList1 : " << *it << endl;

	cout << endl << "Sorted List #2:" << endl;
	for (list<int>::iterator it = intList2.begin(); it != intList2.end(); it++)
		cout << "intList2 : " << *it << endl;

	//������� ��� �������������� ������
	intList1.merge(intList2);

	//������� ������ ������
	cout << endl << "Merged List #1:" << endl;
	for (list<int>::iterator it = intList1.begin(); it != intList1.end(); it++)
		cout << "intList1 : " << *it << endl;

	system("pause");
    return 0;
}

