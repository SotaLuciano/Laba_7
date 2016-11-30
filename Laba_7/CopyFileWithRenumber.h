#pragma once
#include "Header.h"
#include "ChildStack.h"
#include "Stream.h"

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

