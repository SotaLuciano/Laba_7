#include "Header.h"
#include "ChildStack.h"
#include "Stream.h"

void LoadFileToStek(Stack & MyStack, string name, string road)
{

	ifstream file(road + name);
	if (!file)
	{
		cout << "Wroung name of file!";
		return;
	}
	ostringstream os;
	Stream exp;

	while (!file.eof())
	{
		file >> exp;

		int count = exp.GetCount();

		char* buf = new char[(int)log10(count)];

		string inf = exp.GetInfo();

		os << _itoa(count, buf, 10) << ": " << inf << "\n";

		string a = os.str();

		os.str("");

		MyStack.push(a);
	}
	file.close();	
}

void Purge(Stack & MyStack)// Purge all stack
{
	while (!MyStack.empty())
	{
		cout << MyStack.top();//extracting top element
		MyStack.pop();
	}
}

void LinePrint(void)
{
	for (int i = 0; i < 160; i++)
		cout << '*';
}

void ListofFiles(void)
{
	WIN32_FIND_DATAA FindFileData; // function for searching files

	HANDLE hSearch;

	cout << "\t\t\t\t\tStart searching" << endl;

	LinePrint();

	cout << "\t\t\t\t\tRESULTS:" << endl;

	//Searching files

	hSearch = FindFirstFileA(("d:\\Visual Studio\\Visual Studio C++ Projects\\Laba_7\\Laba_7\\*.txt"), &FindFileData); // Way to directory

	if (hSearch == INVALID_HANDLE_VALUE)
	{
		printf("Invalid File Handle. GetLastError reports %d\n", GetLastError());
	}
	else
	{
		do
		{
			printf("%s\n", FindFileData.cFileName);			// Print files
		} while (FindNextFileA(hSearch, &FindFileData));	//Search next file
		FindClose(hSearch);
	}
}

void ReverseStack(Stack & _stack)
{
	string item;
	Stack tmpStack;

	while (_stack.empty() == false)
	{
		item = _stack.top();
		_stack.pop();
		tmpStack.push(item);
	}
	_stack = tmpStack;
}