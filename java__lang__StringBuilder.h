#ifndef JAVA__LANG__STRINGBUILDER
#define JAVA__LANG__STRINGBUILDER

#include "java__lang__String.h"

using namespace java::lang;

namespace java::lang
{
	class StringBuilder : public Object
	{
	public:
		//StringBuilder();
		//StringBuilder(String *string);
		StringBuilder(const char* string);
		//virtual ~StringBuilder();
		StringBuilder* append(Pointer<String> string);
		StringBuilder* append(const char* string);
		Pointer<String> toString();
	private:
		char buffer[100];
		size_t length;
		char* ptr;
	};
}

#endif
