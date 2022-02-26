#ifndef JAVA__IO__PRINTSTREAM
#define JAVA__IO__PRINTSTREAM

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::io
{
	class PrintStream : public Object
	{
	public:
		PrintStream();
		~PrintStream();
		virtual void println(const char* text);
		virtual void println(Pointer<String> text);
	};
}

#endif
