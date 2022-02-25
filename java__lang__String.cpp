#include "stdafx.h"
#include "java__lang__String.h"

namespace java::lang
{

	String::String()
	{
		data = nullptr;
	}

	String::String(const char* string)
	{
		data = _strdup(string);
	}

	String::~String()
	{
		if (data)
			free(data);
	}

	int String::hashCode()
	{
		int h = 0;
		size_t length = strlen(data);
		for (size_t i = 0; i < length; i++)
		{
			int v = data[i];
			h = 31 * h + (v & 0xff);
		}
		return h;
	}

	bool String::equals(const char* other)
	{
		return strcmp(data, other) == 0;
	}

	int String::length()
	{
		return (int)strlen(data);
	}

	bool String::startsWith(const char* start)
	{
		size_t length = strlen(start);
		return strncmp(data, start, length) == 0;
	}

	Pointer<String> String::replace(char from, char to)
	{
		String* newString = new String(data);
		for (char* ptr = newString->data; *ptr != 0; ptr++)
		{
			if (*ptr == from)
				*ptr = to;
		}
		return newString;
	}

	Pointer<String> String::valueOf(Pointer<String> string)
	{
		if (string == nullptr)
			return new String("null");
		return string;
	}

	Pointer<String> String::substring(int first, int last)
	{
		size_t length = strlen(data);
		ASSERT(first < last&& first < length&& last <= length);
		char* buf = (char*)_malloca((size_t)last - (size_t)first + 1);
		if (buf)
		{
			memcpy(buf, data + first, (size_t)last - (size_t)first);
			buf[last - first] = 0;
		}
		return new String(buf);
	}

}
