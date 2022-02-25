#include "stdafx.h"
#include "java__lang__String.h"

namespace java::lang
{

	String::String()
	{
	}

	String::String(const char* string)
	{
		data = string;
	}

	String::~String()
	{
	}

	int String::hashCode()
	{
		int h = 0;
		int length = data.GetLength();
		for (int i = 0; i < length; i++)
		{
			int v = data[i];
			h = 31 * h + (v & 0xff);
		}
		return h;
	}

	bool String::equals(const char* other)
	{
		return data == other;
	}

	int String::length()
	{
		return data.GetLength();
	}

	bool String::startsWith(const char* start)
	{
		size_t length = strlen(start);
		return strncmp(data, start, length) == 0;
	}

	Pointer<String> String::replace(char from, char to)
	{
		CString newString = data;
		newString.Replace(from, to);
		return new String(newString);
	}

	Pointer<String> String::valueOf(Pointer<String> string)
	{
		if (string == nullptr)
			return new String("null");
		return string;
	}

	Pointer<String> String::substring(int first, int last)
	{
		CString buf = data.Mid(first, last - first);
		return new String(buf);
	}

}
