#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("003.If Else");

	int age = 0;

	cout << "Hello, how old are your?" << endl;
	cout << "I'm ";
	cin >> age;

	if (age >= 18)
		cout << "Great! Are you an adult." << endl;
	else
		cout << "Ooo, yong man." << endl;

	char ans = 'n';

	cout << "Am I right? (y/n)" << endl;
	cin >> ans;
	if (ans == 'y')
		cout << "Right!" << endl;
	else
		cout << "Okey. Whatever you say." << endl;

	system("pause");
    return 0;
}

