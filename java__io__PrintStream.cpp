#include "stdafx.h"
#include "java__io__PrintStream.h"
#include "java__lang__String.h"

namespace java::io
{

	PrintStream::PrintStream()
	{
	}

	PrintStream::~PrintStream()
	{
	}

	void PrintStream::println(const char* text)
	{
		printf("%s\n", text);
	}

	void PrintStream::println(Pointer<String> text)
	{
		CString textOut = text->operator CString();
		printf("%s\n", textOut.GetBuffer());
	}

}
