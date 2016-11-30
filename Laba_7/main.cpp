#include"Header.h"
#include "CopyFileWithRenumber.h"

void main()
{
	int choise_num;

	cout << "If you want load file to stack, enter --- '1'\nIf you want to copy file, enter --- '2'" << endl;
	cin >> choise_num;
	system("cls");
	if (choise_num == 1)
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
			LoadFileToStek(MyStack, name, road);
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
	}
	else if (choise_num == 2)
	{
		CopyFileWithRenumber MyCopy;
		MyCopy.Set_File_Name();
		MyCopy.Copy_File();
	}
	else cout << "Error 405, wrong enter!";
	_getch();
}