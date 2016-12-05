#pragma once
#include "Header.h"
#include "Stream.h"
#include "ChildStack.h"

class CopyFileWithRenumber
{
public:
	string file_name;
	CopyFileWithRenumber()
	{
		file_name.assign("");
	}
	void Set_File_Name();
	void Copy_File();
};

