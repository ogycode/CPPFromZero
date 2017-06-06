#include "stdafx.h"

#include "Student.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("0010.Classes");

	Student *std = new Student();
	cout << "Without init:" << endl;
	cout << "std->GetName() - " << std->GetName() << endl;
	cout << "std->GetAvgScore() - " << std->GetAvgScore() << endl;
	cout << "std->Say() - " << std->Say() << endl << endl;

	cout << "Let go set your own onject:" << endl;
	string str;
	cout << "What's you name?";
	cin >> str;
	std->SetName(str);
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

	Student *std2 = new Student("Vadim", "Verloka");
	std2->SetScores(scores, 3);
	cout << "With pre-init:" << endl;
	cout << "std2->GetName() - " << std2->GetName() << endl;
	cout << "std2->Say() - " << std2->Say() << endl;
	cout << "std2->GetAvgScore() - " << std2->GetAvgScore() << endl << endl;

	cout << "Copy std2:" << endl;
	cout << "std2->Clone()->Say() : " << std2->Clone()->Say() << endl;

	system("pause");
    return 0;
}

