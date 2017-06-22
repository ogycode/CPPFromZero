#include "stdafx.h"

using namespace std;

//предикант возвращает true если
//число делится на 3 без остатка
bool Pred(int i)
{
	return i % 3 == 0;
}

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("035.STL_Partition and etc.");

	cout.setf(ios_base::boolalpha);

	vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };

	cout << "Vector: ";
	for (auto i : vec)
		cout << i << " ";
	
	//is_partitioned возвращает true если вектор разделен
	//согласно предиканту
	cout << endl << "Vector is_partitioned: " << is_partitioned(vec.begin(), vec.end(), Pred) << endl;

	cout << "Vector after partition: ";

	//partition разделяет вектор на две части условно, в первой части
	//элементы которым предикант вернул true во второй которым false
	partition(vec.begin(), vec.end(), Pred);

	for (auto i : vec)
		cout << i << " ";

	vector<int> vec2{ 0,1,2,3,4,5,6,7,8,9 };

	cout << endl <<"Vector after stable_partition: ";

	//stable_partition разделяет диапазон согласно предиканту но 
	//сохраняет первоначальный порядок элементов
	stable_partition(vec2.begin(), vec2.end(), Pred);

	for (auto i : vec2)
		cout << i << " ";

	cout << endl << "Vector after partition is_partitioned: " << is_partitioned(vec.begin(), vec.end(), Pred) << endl;


	vector<int> vec3{ 0,1,2,3,4,5,6,7,8,9 };

	vector<int> PredTrue(10);
	vector<int> PredFalse(10);

	cout << "'partition_copy':" << endl;

	//partition_copy делает то же, что и stable_partition НО
	//элементы, разделенные он копирует в разные, указаные диапазоны
	partition_copy(vec3.begin(), vec3.end(), PredTrue.begin(), PredFalse.begin(), Pred);

	cout << "PredTrue after partition_copy: ";
	for (auto i : PredTrue)
		cout << i << " ";

	cout << endl << "PredFalse after partition_copy: ";
	for (auto i : PredFalse)
		cout << i << " ";

	cout << endl;
	system("pause");
    return 0;
}

