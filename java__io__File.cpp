#include "stdafx.h"
#include "java__io__File.h"

namespace java::io
{

	File::File(Pointer<String> fileName)
	{
		this->fileName = fileName->operator CString();
	}

	File::~File()
	{
		file.Close();
	}

	bool File::exists()
	{
		DWORD attributes = GetFileAttributes(fileName);
		return (attributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_NORMAL)) != 0;
	}

	bool File::isFile()
	{
		DWORD attributes = GetFileAttributes(fileName);
		return (attributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
	}

}
