#pragma once
#include "stdafx.h"

template <int Size, typename T>
class MyStorage
{
private:
	T *box;
	int current = -1;

public:
	MyStorage()
	{
		box = new T[Size];
	}
	~MyStorage()
	{
		delete[] this->box;
	}

	void Add(const T &Element)
	{
		if (this->current < Size - 1)
		{
			this->current++;
			this->box[current] = Element;
		}
		else
			cout << "Storage is over!" << endl;
	}
	void RemoveLast()
	{
		if (current != -1)
		{
			this->box[current] = 0;
			this->current--;
		}
	}
	void Clear()
	{
		this->current = -1;
	}
	void PrintStorage()
	{
		for (size_t i = 0; i <= this->current; i++)
			cout << "Element[" << i << "] = " << this->box[i] << endl;
	}
};