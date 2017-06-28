#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "Russian");
	SetConsoleTitle("039.STL_Operation on heap");

	vector<int> vec1{ 2,4,44,5,2,1,1,2,33,3,4 };

	//is_heap возвращает true если диапазон является кучей
	if (is_heap(vec1.begin(), vec1.end()))
	{
		cout << "Vector 1 is a heap: ";
		copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
	}
	else
	{
		cout << "Vector isn't a heap, making..." << endl << "Before: ";
		copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
		cout << endl << "After: ";

		//make_heap делает из диапазона кучу
		make_heap(vec1.begin(), vec1.end());

		copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));
	}

	if (is_heap(vec1.begin(), vec1.end()))
		cout << endl << "Now vector is a heap" << endl;

	int elem = 0;
	cout << "Adding new element to heap: ";
	cin >> elem;

	//push_heap - вставляет элемент в кучу
	//pop_heap - удаляет найбольшый элемент из кучи
	vec1.push_back(elem);
	push_heap(vec1.begin(), vec1.end());

	cout << "Heap after pushing: ";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	//sort_heap превращает кучу в обычный отсортированый по возрастанию
	//диапазон или по предиканту
	sort_heap(vec1.begin(), vec1.end());
	cout << endl << "Heap after sorting to range: ";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	
	cout << endl;
	system("pause");
    return 0;
}

