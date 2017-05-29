#include "stdafx.h"

using namespace std;

void Console(string);
void ConsoleL(string);
bool NullOrWhiteSpace(string);

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("006.Functions");

	string str;

	ConsoleL("Check line to null or white space your string. Enter.");
	Console("String: ");
	cin >> str;

	if (NullOrWhiteSpace(str))
		ConsoleL("Your string is empty!");
	else
		ConsoleL("Your string is'n empty!");

	system("pause");
    return 0;
}

void ConsoleL(string line)
{
	cout << line << endl;
}
void Console(string line)
{
	cout << line;
}
bool NullOrWhiteSpace(string str)
{
	return str.empty();
}

