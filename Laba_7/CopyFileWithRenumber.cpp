#include "CopyFileWithRenumber.h"

void CopyFileWithRenumber::Copy_File()
{
	string copyname = file_name + "_copy.txt";
	file_name += ".txt";

	ofstream isc(copyname, ios::app);

	stack<string> MyStack;

	string road = "D:\\Visual Studio\\Visual Studio C++ Projects\\Laba_7\\Laba_7\\";

	LoadFileToStek(MyStack, file_name, road);

	ReverseStack(MyStack);

	while (!MyStack.empty())
	{
		isc << MyStack.top();
		MyStack.pop();
	}
	isc.close();
}

void CopyFileWithRenumber::Set_File_Name()
{
	cout << "Enter name of file: ";
	cin >> file_name;
}
