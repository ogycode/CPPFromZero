#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("004.Loops");

	char loop = 'f';

	cout << "Select loop (f - for, w - while, d - do while)" << endl;
	cout << "Loop - ";
	cin >> loop;

	int d = 100;
	int w = 100;
	switch (loop)
	{
	case 'f':
	default:
		cout << "Loop: for(size_t i = 0; i < 100; i++)" << endl;
		for (size_t i = 0; i < 100; i++)
		{
			cout << "Iteration - " << i << endl;
		}
		break;
	case 'w':
		cout << "Loop: while (w >= 0)" << endl;
		while (w >= 0)
		{
			cout << "Iteration - " << w << endl;
			w--;
		}
		break;
	case 'd':
		cout << "Loop: do while (d >= 0)" << endl;
		do
		{
			cout << "Iteration - " << d << endl;
			d--;
		} while (d >= 0);
		break;
	}

	system("pause");
	return 0;
}

