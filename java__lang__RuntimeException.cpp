#include "stdafx.h"
#include "java__lang__RuntimeException.h"

namespace java::lang
{

	RuntimeException::RuntimeException(Pointer<String> message)
	{
		errorMessage = message;
	}

	RuntimeException::~RuntimeException()
	{
	}

	void RuntimeException::printStackTrace()
	{
		TRACE("Printing stack trace nere\n");
	}

}
