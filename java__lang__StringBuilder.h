#pragma once

#include "java__lang__String.h"

using namespace java::lang;

namespace java::lang
{
	class StringBuilder : public Object
	{
	public:
		//StringBuilder();
		StringBuilder(Pointer<String> string);
		StringBuilder(const char* string);
		virtual ~StringBuilder();
		Pointer<StringBuilder> append(Pointer<String> string);
		Pointer<StringBuilder> append(const char* string);
		Pointer<StringBuilder> append(int integer);
		Pointer<String> toString();
	private:
		CString buffer;
	};
}
