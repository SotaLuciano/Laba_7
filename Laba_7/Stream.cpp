#include "Stream.h"



Stream::Stream()
{
	info.assign("");
	count_of_strings = 0;
}

ifstream& operator >> (ifstream & is, Stream & ms)
{
	ms.info.assign("");

	istream_iterator<string> iter(is);
	istream_iterator<string> eof;

	while (iter != eof)
	{
		char c = is.get();

		ms.info += *iter;

		if (c == '\n' || is.eof())
		{
			break;
		}
		else if (c == ' ')
			ms.info += " ";

		++iter;
	}

	ms.count_of_strings++;

	return is;
};

Stream::~Stream()
{
}
