#include "stdafx.h"

using namespace std;

bool PredAll(const int &i)
{
	return i > 0;
}
bool PredAny(const int &i)
{
	return i < 0;
}
bool PredNone(const int &i)
{
	return i == 33;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("018.STL_All_Of Any_Of None_Of");

	vector<int> vec
	{
		4,		33,
		5,		42,
		7,		5,
		52,		66,
		66,		8
	};

	//All_Of возвращает true если все значения вектора
	//в предиканте возрващают true
	if (all_of(vec.begin(), vec.end(), PredAll))
		cout << "All numbers in vector upper then zero" << endl;
	else
		cout << "Non all numbers in vector upper then zero" << endl;


	//Any_Of возрващает true если хотябы 
	//один элемент ветора в предиканте
	//возрващает true
	if (any_of(vec.begin(), vec.end(), PredAny))
		cout << "One or more numbers lower then zero" << endl;
	else
		cout << "All nmbers upper then zero" << endl;

	//None_Of возвращает true если все значения
	//вектора в предиканте возвращают false
	if (none_of(vec.begin(), vec.end(), PredNone))
		cout << "In the vector no number 33" << endl;
	else
		cout << "In the vector there is number 33" << endl;

	system("pause");
	return 0;
}

