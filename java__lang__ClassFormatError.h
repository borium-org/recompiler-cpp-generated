#ifndef JAVA__LANG__CLASSFORMATERROR
#define JAVA__LANG__CLASSFORMATERROR

#include "java__lang__Exception.h"

namespace java::lang
{
	class ClassFormatError : public Exception
	{
	public:
		ClassFormatError(const char* message);
		ClassFormatError(Pointer<String> message);
	};
}

#endif
