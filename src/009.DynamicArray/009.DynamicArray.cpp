#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("009.Dynamic Array");

	int size = 0;

	cout << "Enter array size: ";
	cin >> size;

	int *arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}

	cout << "Your array:" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	delete[] arr;

	system("pause");
	return 0;
}

