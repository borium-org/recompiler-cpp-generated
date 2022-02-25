#ifndef JAVA__UTIL__ITERATOR
#define JAVA__UTIL__ITERATOR

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class Iterator : public Object
	{
	public:
		Iterator();
		virtual ~Iterator();
		virtual Pointer<T> next();
		virtual bool hasNext();
	};
}

#endif
