#include "stdafx.h"
#include "Student.h"

Student::Student()
{
	this->scores = new int[scoresSize];
	this->firstName = new string();
	this->lastName = new string();

	for (size_t i = 0; i < this->scoresSize; i++)
		this->scores[i] = 0;
}
Student::Student(string fName, string lName)
{
	this->scores = new int[this->scoresSize];
	this->firstName = new string();
	this->lastName = new string();

	Student::SetFirstName(fName);
	Student::SetLastName(lName);
}
Student::~Student()
{
	delete[] this->scores;
	delete this->firstName;
	delete this->lastName;
}

void Student::SetFirstName(const string &FirstName)
{
	this->firstName = new string(FirstName);
}
void Student::SetLastName(const string &LastName)
{
	this->lastName = new string(LastName);
}
void Student::SetScores(const int * Scores, int size)
{
	this->scoresSize = size;

	this->scores = new int[size];

	for (size_t i = 0; i < size; i++)
		this->scores[i] = Scores[i];
}

string Student::GetName()
{
	return *this->firstName + " " + *this->lastName;
}
int Student::GetAvgScore()
{
	int sum = 0;
	for (size_t i = 0; i < this->scoresSize; i++)
		sum += this->scores[i];

	return sum / this->scoresSize;
}
