#include "Header.h"

void Print(fstream & Text)
{
	Text.seekg(0, ios::beg);
	char n[Max_Len];
	while (!Text.eof())
	{
		Text >> n;
		cout << n << endl;
	}
	Text.flush();
}

int LoadFileToStek(Stack & MyStack, string name, string road)
{

	fstream file(road + name);

	const int MAX_SIZE = 10;

	char *buffer = new char[MAX_SIZE];

	char *arr = new char[MAX_SIZE];

	int n = MAX_SIZE;

	int count = 1;

	bool isFirst = true;

	char k1;
	while (file.get(k1))
	{
		/*if (file.eof())
		break;*/

		file.seekg(-1, ios::cur);

		file.getline(buffer, MAX_SIZE, '\n');

		if (isFirst)
		{
			strcpy(arr, buffer);

		}

		char k;

		file.clear();

		file.seekg(-1, ios::cur);

		file.get(k);
		if (!file.get(k1))
		{
			k = '\n';
		}
		file.seekg(-1, ios::cur);
		if (k == '\n' || !file.good() || k == '\n')
		{

			if (isFirst)
			{
				strcpy(arr, buffer);
			}
			else
			{
				strcat(arr, buffer);
			}



			strcat(arr, "\n");
			//RENUMBER
			char *a = new char[(strlen(arr) + 2 + (int)log10(count))];

			sprintf(a, "%d: %s", count, arr);
			//END RENUMBER
			MyStack.push(a);

			count++;

			isFirst = true;

			delete[] arr;

			n = MAX_SIZE;

			arr = new char[n];

		}
		else
		{
			char *b = _strdup(arr);

			n = n * 2;

			delete[] arr;

			arr = new char[n];

			strcpy(arr, b);

			if (isFirst)
			{
				isFirst = false;
			}
			else
			{
				strcat(arr, buffer);
			}

		}

	}

	file.close();
	return count;
}


void Purge(Stack & MyStack)// Purge all stack
{
	while (!MyStack.empty())
	{
		cout << MyStack.top() << endl;//extracting top element
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