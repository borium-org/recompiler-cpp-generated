#include "stdafx.h"
#include "java__lang__StringBuilder.h"

namespace java::lang
{

	StringBuilder::StringBuilder(const char* string)
	{
		length = 100;
		ptr = buffer;
		if (strlen(string) >= length)
		{
			length *= 2;
			ptr = new char[length];
		}
		strcpy_s(ptr, length, string);
	}

	StringBuilder* StringBuilder::append(Pointer<String> string)
	{
		if (strlen(ptr) + string->length() >= length)
		{
			length *= 2;
			char* ptr1 = new char[length];
			strcpy_s(ptr1, length, ptr);
			delete ptr;
			ptr = ptr1;
		}
		strcat_s(ptr, length, string->data);
		return this;
	}

	StringBuilder* StringBuilder::append(const char* string)
	{
		if (strlen(ptr) + strlen(string) >= length)
		{
			length *= 2;
			char* ptr1 = new char[length];
			strcpy_s(ptr1, length, ptr);
			delete ptr;
			ptr = ptr1;
		}
		strcat_s(ptr, length, string);
		return this;
	}

	Pointer<String> StringBuilder::toString()
	{
		return new String(ptr);
	}

}
