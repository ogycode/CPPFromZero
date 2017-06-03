#pragma once
using namespace std;

class Student
{
private:
	int scoresSize = 5;
	int *scores = NULL;
	string *firstName = NULL;
	string *lastName = NULL;

public:
	Student();
	Student(string firstName, string lastName);
	~Student();

	void SetFirstName(const string &FirstName);
	void SetLastName(const string &LastName);
	void SetScores(const int *Scores, int size);

	string GetName();
	int GetAvgScore();
};