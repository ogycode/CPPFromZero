#include "stdafx.h"
#include "ComplexValue.h"
using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("013.Operator Overloading");

	ComplexValue value1(15, 2);
	ComplexValue value2(25, -2);

	cout << "Value1 : " << value1.GetValue() << endl;
	cout << "Value2 : " << value2.GetValue() << endl << endl;

	cout << "Value1 + Value2 = " << value1 + value2 << endl;
	cout << "Value1 - Value2 = " << value1 - value2 << endl;
	cout << "Value1 * Value2 = " << value1 * value2 << endl;
	cout << "Value1 / Value2 = " << value1 / value2 << endl;

	system("pause");
    return 0;
}

