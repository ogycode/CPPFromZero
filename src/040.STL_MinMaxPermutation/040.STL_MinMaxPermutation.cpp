#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russian");
	SetConsoleTitle("040.STL_Min, Max, Premutation");

	int a = 0, b = 0;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	//max возвращает найбольшее из двух
	//min возвращает найменьшее из двух
	//minmax(a, b).first = min(a, b)
	//minmax(a, b).second = max(a, b)
	//max_element  возвращает максимальный элемент из диапазона
	//min_element  возвращает минимальный элемент из диапазона
	cout << "Bigest: " << max(a, b) << endl;
	cout << "Lower: " << min(a, b) << endl;

	string str = "";
	string strCopy;

	cout << "Enter string for permutation: ";
	cin >> str;

	strCopy = str;

	cout << "All lexicographical permutation: " << endl;

	//next_permutation переобразует строку в следующую возможнуй перестановку
	//prev_permutation переобразует строку в предыдущую перестановку
	do
	{
		std::cout << str << endl;
	} while (next_permutation(str.begin(), str.end()));


	//lexicographical_compare сравнивает две перестановки и определяет найбольшую из них
	cout << "Lexicographical compare: " << endl;
	if (lexicographical_compare(strCopy.begin(), strCopy.end(), str.begin(), str.end()))
		cout << strCopy << " >= " << str << endl;
	else
		cout << strCopy << " <= " << str << endl;


	vector<int> vec1{ 1,2,3,4,5 };
	vector<int> vec2{ 1,3,4,2,5 };
	vector<int> vec3{ 1,1,2,3,4 };

	cout << "Is permutation:" << endl;
	cout.setf(ios::boolalpha);

	//is_permutation вовращает true если второй диапазон является одной 
	//из перестановок первого диапазона
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
	cout << " is a permutation of ";
	copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, " "));
	cout << " " << is_permutation(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()) << endl;

	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
	cout << " is a permutation of ";
	copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout, " "));
	cout << " " << is_permutation(vec1.begin(), vec1.end(), vec3.begin(), vec3.end()) << endl;

	system("pause");
	return 0;
}

