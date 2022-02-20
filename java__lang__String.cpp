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

}
