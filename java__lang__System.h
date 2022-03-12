#pragma once

#include "java__io__PrintStream.h"

using namespace java::io;

namespace java::lang
{
	class System
	{
	public:
		static Pointer<PrintStream> out;
		static void ClassInit();
	};
}
