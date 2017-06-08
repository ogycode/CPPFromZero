#pragma once
#include "stdafx.h"

class Element
{
public:
	int index;

	Element(int i = 0);
	Element(const Element &copy);
	~Element();

	void SetIndex(int i);
	int GetIndex();

	Element& operator=(const Element &elem);
	bool operator<(const Element &elem) const;
	bool operator>(const Element &elem) const;
	friend std::ostream &operator<<(std::ostream &, const Element &);

};

