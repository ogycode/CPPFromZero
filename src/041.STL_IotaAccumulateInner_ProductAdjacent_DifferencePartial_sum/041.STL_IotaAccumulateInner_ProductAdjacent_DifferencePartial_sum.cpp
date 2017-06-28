#include "stdafx.h"

using namespace std;

int Multiply(int x, int y)
{
	return x*y;
}

int main()
{
	system("color 70");
	setlocale(0, "Russian");
	SetConsoleTitle("041.STL_Iota, Accumulate, Inner_Product, Adjacent_Difference, Partial_Sum");

	vector<int> vec1(10);
	cout << "Vector before iota: ";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	//iota заполн¤ет диапазон таким образом, что первый элемент равен
	//указаному, а послудуюущие больше предыдущего на еденицу
	iota(vec1.begin(), vec1.end(), 1);

	cout << endl << "Vector after iota: ";
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	//accumulate считате суму всех еэелментов в диапазоне
	//также с помощью предиканта возможно получить умножение всех элементов и прочее
	cout << endl << "Sum of all elements in vector 1: " << accumulate(vec1.begin(), vec1.end(), 0) << endl;
	cout << "Multiply of all elements in vector 1: " << accumulate(vec1.begin(), vec1.end(), 1, Multiply) << endl;

	vector<int> vec2(10);
	iota(vec2.begin(), vec2.end(), 10);

	//inner_product скал¤рно умножает два диапазона (вектора)
	cout << "Inner product of vector 1 and vector 2: " << inner_product(vec1.begin(), vec1.end(), vec2.begin(), 0) << endl;
	cout << "Adjacent difference of vector 1 : " << endl;

	//adjacent_difference записывает в новый диапазон различи¤ двух соседних элементов
	//указаного диапазона, т.е. на сколько отличаетс¤ первый от второго и т.д
	adjacent_difference(vec1.begin(), vec1.end(), vec1.begin());
	copy(vec1.begin(), vec1.end(), ostream_iterator<int>(cout, " "));

	vector<int> vec3(10);
	fill(vec3.begin(), vec3.end(), 10);

	//partial_sum записывает суму элементов в таком виде:
	//*(d_first)   = *first;
	//*(d_first + 1) = *first + *(first + 1);
	//*(d_first + 2) = *first + *(first + 1) + *(first + 2);
	//*(d_first + 3) = *first + *(first + 1) + *(first + 2) + *(first + 3);
	//...
	cout << endl << "Partial sum of Vector 3: ";
	partial_sum(vec3.begin(), vec3.end(), std::ostream_iterator<int>(std::cout, " "));
	fill(vec3.begin(), vec3.end(), 2);

	//partial_sum тут с помощью предиканта записываетс¤ в вектор произведение
	cout << endl << "Partial pow of Vector 3: ";
	partial_sum(vec3.begin(), vec3.end(), vec3.begin(), multiplies<int>());
	copy(vec3.begin(), vec3.end(), ostream_iterator<int>(cout, " "));

	cout << endl;
	system("pause");
    return 0;
}

