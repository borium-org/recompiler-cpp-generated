#ifndef JAVA__LANG__RUNTIMEEXCEPTION
#define JAVA__LANG__RUNTIMEEXCEPTION

#include "java__lang__String.h"

using namespace java::lang;

namespace java::lang
{
	class RuntimeException
	{
	public:
		RuntimeException();
		RuntimeException(String *message);
		virtual ~RuntimeException();
	};
}

#endif
