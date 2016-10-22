#pragma once
#include <fstream>
#include <map>
#include <string>


using namespace std;

class MyTDE
{
	public:
		MyTDE(string, string, bool[], int);
		~MyTDE();
		int GetNumberofColumns(string);
		int VerifyColumns(string a, int b, int c);
		string DeleteFirstWord(string&);
		int ConvertMethod();
		void DisplayComma(int a, int b, ofstream& c);

	private:
		string InputFilePath;
		string OutputFilePath;
		bool *Switch;
		int SizeOfColumn;
};