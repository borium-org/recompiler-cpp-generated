#include "stdafx.h"
#include "java__lang__StringBuilder.h"

namespace java::lang
{

	StringBuilder::StringBuilder(Pointer<String> string)
	{
		buffer = string->data;
	}

	StringBuilder::StringBuilder(const char* string)
	{
		buffer = string;
	}

	StringBuilder::~StringBuilder()
	{
	}

	StringBuilder* StringBuilder::append(Pointer<String> string)
	{
		buffer += string->data;
		return this;
	}

	StringBuilder* StringBuilder::append(const char* string)
	{
		buffer += string;
		return this;
	}

	Pointer<String> StringBuilder::toString()
	{
		return new String(buffer);
	}

}
