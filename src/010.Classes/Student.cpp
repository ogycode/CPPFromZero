#include "stdafx.h"
#include "Student.h"

Student::Student()
{
	scores = new int[scoresSize];
	firstName = new string();
	lastName = new string();

	for (size_t i = 0; i < scoresSize; i++)
		scores[i] = 0;
}
Student::Student(string firstName, string lastName)
{
	Student::SetFirstName(firstName);
	Student::SetLastName(lastName);
}
Student::~Student()
{
	delete[] scores;
	delete firstName;
	delete lastName;
}

void Student::SetFirstName(const string &FirstName)
{
	firstName = new string(FirstName);
}
void Student::SetLastName(const string & LastName)
{
	delete lastName;
	lastName = new string(LastName);
}
void Student::SetScores(const int * Scores, int size)
{
	delete[] scores;
	scoresSize = size;

	scores = new int[size];

	for (size_t i = 0; i < size; i++)
		scores[i] = Scores[i];
}

string Student::GetName()
{
	return *firstName + " " + *lastName;
}
int Student::GetAvgScore()
{
	int sum = 0;
	for (size_t i = 0; i < scoresSize; i++)
		sum += scores[i];

	return sum / scoresSize;
}
