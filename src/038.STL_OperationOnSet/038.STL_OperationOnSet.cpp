#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russian");
	SetConsoleTitle("038.STL_Operation on set");

	//ВСЕ ДЕЙСТВИЯ ТОЛЬКО НА ОТСОРТИРОВАНЫХ МНОЖЕСТВАХ!!!

	vector<int> vec1{ 1,6,6,8,9,22,44 };
	vector<int> vec2{ 2,66,67,88,88,999 };

	cout << "Vector 1: ";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	cout << endl << "Vector 2: ";
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));

	vector<int> vec3;

	//merge сливает два отсортированых диапазона в один
	//есть возможность использовать предикант
	merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(vec3));

	cout << endl << "Mergered Vector 3: ";
	copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout, " "));

	vector<int> vec4{ 1,2,3,1,4,5,6,7 };

	cout << endl << "Vector 4 before inplace_merge: ";
	copy(vec4.begin(), vec4.end(), ostream_iterator<int>(cout, " "));

	//сливает два последовательных поддиапазона (отсортированых) в один
	//все должно находится в одной коллекции
	inplace_merge(vec4.begin(), vec4.begin() + 3, vec4.end());

	cout << endl << "Vector 4 after inplace_merge: ";
	copy(vec4.begin(), vec4.end(), ostream_iterator<int>(cout, " "));

	cout.setf(ios_base::boolalpha);

	vector<int> vec5{ 1,2,3 };

	//includes возвращает true если один диапазно является поддиапазоном второго
	cout << endl << "Vector 4 Includes Vector 5: " << includes(vec4.begin(), vec4.end(), vec5.begin(), vec5.end()) << endl;

	vector<int> vec6{ 1,2,3,4,5,6,7,8,9 };
	vector<int> vec7{ 2,4,6,8 };
	vector<int> vec8;
	vector<int> vec9;
	vector<int> vec10;

	//set_difference вычисляет разницу диапазонов, убирает из первого диапазона
	//элементы которые встречаются во втором
	set_difference(vec6.begin(), vec6.end(), vec7.begin(), vec7.end(), back_inserter(vec8));

	cout << "Vector 6 minus Vector 7: ";
	copy(vec8.begin(), vec8.end(), ostream_iterator<int>(cout, " "));

	//set_intersection определяет пересеченя диапазонов, оставляет только те
	//элементы которые встречаются в обоих диапазнах
	set_intersection(vec6.begin(), vec6.end(), vec5.begin(), vec5.end(), back_inserter(vec9));

	cout << endl << "Vector 5 and Vector 6 intersection: ";
	copy(vec9.begin(), vec9.end(), ostream_iterator<int>(cout, " "));

	//set_symmetric_difference копирует в первый диапазон элементы из второго 
	//которые не встречаются в первом
	//set_union действует подобным образом
	set_symmetric_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), back_inserter(vec10));

	cout << endl << "Symmetric difference by Vector 1 and Vector 2: ";
	copy(vec10.begin(), vec10.end(), ostream_iterator<int>(cout, " "));

	cout << endl;
	system("pause");
    return 0;
}

