#ifndef JAVA__LANG__STRING
#define JAVA__LANG__STRING

#include "java__lang__Object.h"

namespace java::lang
{
	class String : public Object
	{
		friend class StringBuilder;
	public:
		String();
		String(const char* string);
		virtual ~String();
		static Pointer<String> valueOf(Pointer<String> string);
		virtual int hashCode();
		virtual int length();
		virtual bool equals(const char* other);
		virtual bool startsWith(const char* start);
		virtual Pointer<String> replace(char from, char to);
		virtual Pointer<String> substring(int first, int last);
	private:
		CString data;
	};
}

#endif
