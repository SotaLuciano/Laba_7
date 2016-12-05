#pragma once
#include "Header.h"
#include "Stream.h"

class ChildStack : public stack<string>
{
public:
	ChildStack() : stack<string>()
	{

	}

	void LoadFileToStek(string name, string road)
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

			this->push(a);
		}
		file.close();
	}
	
	void Purge()// Purge all stack
	{
		while (!this->empty())
		{
			cout << this->top();//extracting top element
			this->pop();
		}
	}
	
	void ReverseStack()
	{
		string item;
		ChildStack tmpStack;

		while (this->empty() == false)
		{
			item = this->top();
			this->pop();
			tmpStack.push(item);
		}
		this->swap(tmpStack);
	}
};

