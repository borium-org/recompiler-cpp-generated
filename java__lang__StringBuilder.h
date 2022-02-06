#ifndef JAVA__LANG__STRINGBUILDER
#define JAVA__LANG__STRINGBUILDER

#include "java__lang__String.h"

using namespace java::lang;

namespace java::lang
{
	class StringBuilder: public Object
	{
	public:
		StringBuilder();
		StringBuilder(const char*);
		virtual ~StringBuilder();
		StringBuilder* append(String *string);
		String* toString();
	};
}

#endif
