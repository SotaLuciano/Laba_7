#pragma once
#include "Header.h"
class Stream
{
	friend ifstream& operator >> (ifstream& is, Stream& ms);
public:
	string info;
	int count_of_strings;
	Stream();

	string GetInfo()
	{
		return info;
	}

	int GetCount()
	{
		return count_of_strings;
	}
	~Stream();
};
