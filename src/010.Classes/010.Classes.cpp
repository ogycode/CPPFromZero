#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("0010.Classes");

	Student *std = new Student();
	cout << "Without init:" << endl;
	cout << "std->GetName() - " << std->GetName() << endl;
	cout << "std->GetAvgScore() - " << std->GetAvgScore() << endl << endl;

	cout << "Let go set your own onject:" << endl;
	string str;
	cout << "What's you name?";
	cin >> str;
	std->SetFirstName(str);
	cout << "Waht's you surname?";
	cin >> str;
	std->SetLastName(str);
	int scores[3];
	cout << "Your 1 score:";
	cin >> scores[0];
	cout << "Your 2 score:";
	cin >> scores[1];
	cout << "Your 3 score:";
	cin >> scores[2];
	std->SetScores(scores, 3);
	cout << endl;

	cout << "With init:" << endl;
	cout << "std->GetName() - " << std->GetName() << endl;
	cout << "std->GetAvgScore() - " << std->GetAvgScore() << endl << endl;

	delete std;

	system("pause");
    return 0;
}

