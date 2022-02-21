#ifndef JAVA__LANG__STRING
#define JAVA__LANG__STRING

#include "java__lang__Object.h"

namespace java::lang
{
	class String : public Object
	{
	public:
		String();
		String(const char* string);
		virtual ~String();
		//static String* valueOf(String* string);
		virtual int hashCode();
		//virtual int length();
		virtual bool equals(const char* other);
		//virtual bool startsWith(const char* start);
		//virtual String* replace(char from, char to);
		//virtual String* substring(int first, int last);
	private:
		char* data;
	};
}

#endif
