#include "stdafx.h"
#include "java__lang__System.h"

namespace java::lang
{

	Pointer<PrintStream> System::out;

	void System::ClassInit()
	{
		out = new PrintStream();
	}

}
