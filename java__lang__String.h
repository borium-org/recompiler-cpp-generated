#pragma once

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
		static Pointer<String> valueOf(int integer);
		virtual int hashCode();
		virtual int length();
		virtual bool equals(const char* other);
		virtual bool startsWith(const char* start);
		virtual Pointer<String> replace(char from, char to);
		virtual Pointer<String> substring(int first);
		virtual Pointer<String> substring(int first, int last);
		virtual int lastIndexOf(char ch);
		operator CString() const
		{
			return data;
		}
	private:
		CString data;
	};
}
