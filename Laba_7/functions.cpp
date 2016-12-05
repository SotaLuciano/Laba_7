#include "Header.h"
#include "Stream.h"

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