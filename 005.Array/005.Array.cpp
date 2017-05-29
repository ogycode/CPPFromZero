#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("005.Array");

	string names[5] = 
	{
		"John",
		"Donald",
		"Smith",
		"Sam",
		"Lucas"
	};

	cout << "Array of names:" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "Name #" << i << " :" << names[i] << endl;
	}
	cout << endl << "You can create yourself array of names, let go!" << endl;
	string ownName[5];
	for (size_t i = 0; i < 5; i++)
	{
		cout << "ownName[" << i << "]: ";
		cin >> ownName[i];
	}
	cout << "Your array:" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "Name #" << i << " :" << ownName[i] << endl;
	}


	system("pause");
    return 0;
}

