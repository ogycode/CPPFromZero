#include "stdafx.h"
#include "MyStorage.h"

using namespace std;

template <typename T>
void PrintArray(const T *arr, int size);

int main()
{
	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("012.Template");

	cout << "Functions template, PrintArray(const T *arr, int size):" << endl;
	int arr1[5]{ 1,2,3,4,5 };
	PrintArray(arr1, 5);
	double arr2[5]{ 1.1,2.2,3.3,4.4,5.5 };
	PrintArray(arr2, 5);
	string arr3[5]{ "str1", "str2", "str3", "str4", "str5" };
	PrintArray(arr3, 5);

	cout << endl << "MyStorage:" << endl;
	MyStorage<5, int> *mstr = new MyStorage<5, int>();
	mstr->Add(4);
	mstr->Add(6);
	mstr->Add(63);
	mstr->Add(61);
	mstr->Add(1);
	mstr->Add(633);
	cout << "mstr->PrintStorage():" << endl;
	mstr->PrintStorage();
	delete mstr;
	
	system("pause");
	return 0;
}

template<typename T>
void PrintArray(const T * arr, int size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}
