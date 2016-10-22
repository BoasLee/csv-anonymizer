#include "stdafx.h"
#include "My Class.h"


MyTDE::MyTDE(string InputPathUser, string OutputPathUser, bool ChangeColumnUser[], int SizeColumnUser)
{

	InputFilePath = InputPathUser;
	OutputFilePath = OutputPathUser;
	Switch = new bool[SizeColumnUser];
	for (int i = 0; i < SizeColumnUser; i++)
	{
		Switch[i] = ChangeColumnUser[i];
	}
	SizeOfColumn = SizeColumnUser;
}
MyTDE::~MyTDE()
{
	delete[] Switch;
}

int MyTDE::GetNumberofColumns(string a)
{
	int count = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ',')
		{
			count++;
		}
	}
	return (++count);
}

int MyTDE::VerifyColumns(string a, int b, int c)
{
	if (GetNumberofColumns(a) != b)
	{
		return (1);
	}
	return(0);
}

string MyTDE::DeleteFirstWord(string &a)
{
	int comma;
	string b;
	comma = a.find(",");
	b = a.substr(0, comma);
	a = a.substr(comma + 1, a.length());
	return (b);
}
void MyTDE::DisplayComma(int a, int b, ofstream& c)
{
	if (a != b - 1)
	{
		c << ",";
	}
}

int MyTDE::ConvertMethod()
{
	ifstream InputFile;
	ofstream OutputFile;
	string MyString, key; // whole line being read, key value put into the map, determines which columns to change.
	int NumberofRows = 0;
	map<string, string> *MapArray = NULL; // map to keep track of all the different key values for each column

	//opens the files
	InputFile.open(InputFilePath);
	OutputFile.open(OutputFilePath);



	// Reads in the first line, create X amount of maps accordingly, creates array size of bool accordingly.
	getline(InputFile, MyString);
	NumberofRows++;
	MapArray = new map<string, string>[SizeOfColumn];

		// Iterates and adds in each header to the correct map. 
	for (int i = 0; i < SizeOfColumn; i++)
	{
		key = DeleteFirstWord(MyString);
		MapArray[i][key] = "Column " + to_string(i + 1);
		OutputFile << MapArray[i][key];
		DisplayComma(i, SizeOfColumn, OutputFile);
	}
	OutputFile << endl;


	// Iterates and adds the data to the correct map. 
	while (!InputFile.eof())
	{
		getline(InputFile, MyString);
		NumberofRows++;
		if (VerifyColumns(MyString, SizeOfColumn, NumberofRows) == 1)
		{
			return (1);
		}
		for (int i = 0; i < SizeOfColumn; i++)
		{
			if (Switch[i] == true) // loop runs when columns needs to be changed.
			{
				key = DeleteFirstWord(MyString);
				if (MapArray[i].find(key) == MapArray[i].end())
				{
					MapArray[i][key] = "Item " + to_string(MapArray[i].size()) + " in column " + to_string(i + 1);
					OutputFile << MapArray[i][key];
				}
				else
				{
					OutputFile << MapArray[i][key];
				}
				DisplayComma(i, SizeOfColumn, OutputFile);
			}
			else // loop runs when column does not need to be changed.
			{
				key = DeleteFirstWord(MyString);
				MapArray[i][key] = key;
				OutputFile << MapArray[i][key];
				DisplayComma(i, SizeOfColumn, OutputFile);
			}
		}
		OutputFile << endl;
	}

	// closing the files and de-allocating the memory. 	
	InputFile.close();
	OutputFile.close();
	delete[] MapArray;
	return (0);
}