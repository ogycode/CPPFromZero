#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("002.Data Types");

	int i = 90;
	double d = 99.99;
	float f = 88.88;
	char c = 'g';
	bool b = true;

	cout << "Data types:" << endl;
	cout << "Int:\t" << i << "\tsizeof(i) = " << sizeof(i) << " byte" << endl;
	cout << "Double:\t" << d << "\tsizeof(d) = " << sizeof(d) << " byte" << endl;
	cout << "Float:\t" << f << "\tsizeof(f) = " << sizeof(f) << " byte" << endl;
	cout << "Char:\t" << c << "\tsizeof(c) = " << sizeof(c) << " byte" << endl;
	cout << "Bool:\t" << b << "\tsizeof(b) = " << sizeof(b) << " byte" << endl;

	system("pause");
    return 0;
}

