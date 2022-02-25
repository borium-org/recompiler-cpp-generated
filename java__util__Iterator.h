#pragma once

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class Iterator
	{
	public:
		virtual Pointer<T> next() = 0;
		virtual bool hasNext() = 0;
	};
}
