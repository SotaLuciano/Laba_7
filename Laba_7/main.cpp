#include"Header.h"
#include "ChildStack.h"
void main()
{
	LinePrint();

	stack<string> MyStack;
	
	// Print list of all files in directory
	ListofFiles();
	
	string road = "D:\\Visual Studio\\Visual Studio C++ Projects\\Laba_7\\Laba_7\\"; // Way to directory
	char choise; // For using Yes/No

	while (true)
	{
		cout << "Enter full name of your file: ";
		string name;
		cin >> name;
		cout << endl;
		LinePrint();
		cout << endl;
		int count = LoadFileToStek(MyStack, name, road);
		Purge(MyStack);
		LinePrint();
		cout << "\nDo u want to open another file from this directory? Y/N: ";
		cin >> choise;
		if (choise == 'Y' || choise == 'y')
		{
			system("cls");

			ListofFiles();
		}
		else
		{
			break;
		}
	}
	_getch();
}