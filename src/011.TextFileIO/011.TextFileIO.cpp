#include "stdafx.h"

using namespace std;

int main()
{
	system("color 70");
	setlocale(0, "");
	SetConsoleTitle("0011.Text File I/O");

	//write
	string filePath;
	string fileContent;
	string fileName;
	cout << "Enter path for new text file: ";
	cin >> filePath;
	cout << "Waht are you want to write to file? File content: ";
	cin >> fileContent;
	cout << "Enter file name: ";
	cin >> fileName;

	ofstream fileWrite;
	fileWrite.open(filePath + "\\" + fileName + ".txt");
	if (fileWrite.is_open())
	{
		fileWrite << fileContent;
		cout << "File " + fileName + ".txt was saved in " + filePath << endl << endl;
	}
	else
	{
		cout << "File " << filePath + "\\" + fileName + ".txt" << " cannot open!" << endl;
	}
	
	fileWrite.close();

	//read
	string openFilePath;
	cout << "Open file for read. Enter path to file: ";
	cin >> openFilePath;

	ifstream fileRead;
	fileRead.open(openFilePath);
	if (fileRead.is_open())
	{
		cout << "Contetn of " << openFilePath << endl;
		string buffer;

		while (!fileRead.eof())
		{
			getline(fileRead, buffer);
			cout << buffer << endl;
		}
	}
	else
	{
		cout << "File " << openFilePath << " cannot open!" << endl;
	}

	system("pause");
	return 0;
}

