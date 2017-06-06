#include "stdafx.h"
#include "Student.h"

Student::Student() : Human()
{
	this->scores = new int[scoresSize];

	for (size_t i = 0; i < this->scoresSize; i++)
		this->scores[i] = 0;
}
Student::Student(string fName, string lName) : Human(fName + " " + lName)
{
	this->scores = new int[this->scoresSize];
}
Student::~Student()
{
	delete[] this->scores;
}


void Student::SetScores(const int * Scores, int size)
{
	this->scoresSize = size;

	this->scores = new int[size];

	for (size_t i = 0; i < size; i++)
		this->scores[i] = Scores[i];
}
int Student::GetAvgScore()
{
	int sum = 0;
	for (size_t i = 0; i < this->scoresSize; i++)
		sum += this->scores[i];

	return sum / this->scoresSize;
}
Human * Student::Create()
{
	return new Student();
}
Human * Student::Clone()
{
	return new Student(*this);
}
string Student::Say()
{
	return "Hello, I'm a student! My name is " + this->GetName() + ". I'm " + to_string(this->GetAge()) + " years old.";
}
