#include "stdafx.h"
#include "Element.h"

Element::Element(int i)
{
	this->SetIndex(i);
}
Element::Element(const Element &copy)
{
	this->index = copy.index;
}
Element::~Element() {}

void Element::SetIndex(int i)
{
	this->index = i;
}
int Element::GetIndex()
{
	return this->index;
}

Element& Element::operator=(const Element &elem)
{
	this->SetIndex(GetIndex());
	return *this;
}
bool Element::operator<(const Element &elem) const
{
	return this->index < elem.index;
}
bool Element::operator>(const Element & elem) const
{
	return this->index > elem.index;
}
std::ostream & operator<<(std::ostream &out, const Element &elem)
{
	out << elem.index;
	return out;
}
