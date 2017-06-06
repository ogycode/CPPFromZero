#pragma once
#include "stdafx.h"
#include "Human.h"

using namespace std;

class Student: virtual public Human
{
private:
	int scoresSize = 5;
	int *scores;

public:
	Student();
	Student(string firstName, string lastName);
	~Student();

	void SetScores(const int *Scores, int size);
	int GetAvgScore();

	// Унаследовано через Human, Функции которые обязательно нужно ПЕРЕОПРЕДЕЛИТЬ
	virtual Human * Create() override;
	virtual Human * Clone() override;
	virtual string Say() override;
};