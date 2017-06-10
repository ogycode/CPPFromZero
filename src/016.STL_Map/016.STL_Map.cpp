#include "stdafx.h"

#include "Element.h"

using namespace std;

struct sortLess
{
	bool operator()(const int &a, const int &b) const
	{
		return a < b;
	}
};
struct sortElemntLess
{
	bool operator()(const Element &a, const Element &b) const
	{
		return a < b;
	}
};

int main()
{
	/*map - Dictionary
	  ключ должен быть уникальными

	  multimap
	  ключ может быть не уникальным
	*/

	system("color 70");
	setlocale(0, "Russina");
	SetConsoleTitle("016.STL_Map");

	//просто мапа <int, string>
	map<int, string> simple;

	simple[5235] = "First";
	simple[6541] = "Second";
	simple[8141] = "Thrid";

	//сначала
	cout << "simple<int, string> (from begin):" << endl;
	for (map<int, string>::iterator i = simple.begin(); i != simple.end(); i++)
		cout << (*i).first << " : " << (*i).second << endl;

	//сконца
	cout << "simple<int, string> (from end):" << endl;
	for (map<int, string>::reverse_iterator i = simple.rbegin(); i != simple.rend(); i++)
		cout << (*i).first << " : " << (*i).second << endl;

	map<string, int> simple2;
	simple2["Hello"] = 0;
	simple2["World"] = 1;

	simple2.insert(map<string, int>::value_type("Insert", 2));
	simple2.insert(map<string, int>::value_type("Insert2", 3));

	cout << "simple2<string, int>:" << endl;
	for (map<string, int>::iterator i = simple2.begin(); i != simple2.end(); i++)
		cout << (*i).first << " : " << (*i).second << endl;

	//map  с сортировкой
	//сортировка с помощью less<int>
	//такая самая как и с помощью 
	//своего компаратора sortLess
	map<int, string, sortLess> sortMap;
	sortMap[532] = "M. Jeckson";
	sortMap[521] = "J. Peters";
	sortMap[621] = "S. Ivanov";
	sortMap[243] = "A. Mishel";
	sortMap[632] = "A. Petrencko";
	sortMap[111] = "V. Henry";

	sortMap.insert(pair<int, string>(342, "Ins. March"));
	sortMap.insert(pair<int, string>(732, "Ins. Vadar"));

	cout << endl << "sortMap.size() : " << sortMap.size() << endl;
	cout << "map<int, string, sortLess>:" << endl;
	for (map<int, string>::iterator i = sortMap.begin(); i != sortMap.end(); i++)
		cout << (*i).first << " : " << (*i).second << endl;

	//map с ключем классом Element
	// + сортировка по этому ключу
	map<Element, string, sortElemntLess> mapElement;
	Element three(3);
	mapElement[three] = "three";
	Element one(1);
	mapElement[one] = "one";
	Element two(2);
	mapElement[two] = "two";

	Element ten(10);
	mapElement.insert(pair<Element, string>(ten, "ten"));

	cout << endl << "map<Element, string, sortElemntLess>:" << endl;
	for (map<Element, string>::iterator i = mapElement.begin(); i != mapElement.end(); i++)
		cout << (*i).first << " : " << (*i).second << endl;

	system("pause");
	return 0;
}

