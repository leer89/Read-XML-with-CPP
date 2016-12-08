// ReadXML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void intro();
void address(ifstream& fin, string& line);

int main()
{
	string line;
	ifstream fin;

	fin.open("address.xml");

	if (fin.fail()) //opens the file
	{
		cout << "Opening file failed \n";
		exit(1);
	}

	intro();
	address(fin, line); //this is my function call

	return 0;
}

void intro()
{
	cout << "This program will output addresses only located in Palmdale:\n";
}

void address(ifstream& fin, string& line) //the function that outputs the addresses
{
	int pos1, pos2;

	while (getline(fin, line))
	{
		if ((pos1 = line.find("<name>")) < string::npos) //string::npos indicates the length of the string
		{
			pos1 = line.find(">"); //this locates the numered location of <name>
			pos2 = line.find("</name>"); //locates the numbered location of </name>

			cout << endl << line.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
			//the function line.substr outputs what is in between of the memory location of pos1 and pos2
			//pos + 1 reads the first output after <name>
			//pos2 - pos - 1 cancels the +1 to pos1
		}

		if ((pos1 = line.find("<street>")) < string::npos)
		{
			pos1 = line.find(">");
			pos2 = line.find("</street>");

			cout << line.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
		}

		if ((pos1 = line.find("<city>")) < string::npos)
		{
			pos1 = line.find(">");
			pos2 = line.find("</city>");

			cout << line.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
		}

		if ((pos1 = line.find("<state>")) < string::npos)
		{
			pos1 = line.find(">");
			pos2 = line.find("</state>");

			cout << line.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
		}
		if ((pos1 = line.find("<zip>")) < string::npos)
		{
			pos1 = line.find(">");
			pos2 = line.find("</zip>");

			cout << line.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
		}
	}
}