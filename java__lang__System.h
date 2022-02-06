#ifndef JAVA__LANG__SYSTEM
#define JAVA__LANG__SYSTEM

#include "java__io__PrintStream.h"

using namespace java::io;

namespace java::lang
{
	class System
	{
	public:
		static PrintStream* out;
		static void ClassInit();
	};
}

#endif
