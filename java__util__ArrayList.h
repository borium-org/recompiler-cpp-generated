#ifndef JAVA__UTIL__ARRAYLIST
#define JAVA__UTIL__ARRAYLIST

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class ArrayList: public Object
	{
	public:
		virtual bool add(T element);
	};
}

#endif
