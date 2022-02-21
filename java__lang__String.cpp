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
		int length = strlen(data);
		for (int i = 0; i < length; i++)
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

}
