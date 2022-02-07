#ifndef JAVA__UTIL__HASHMAP
#define JAVA__UTIL__HASHMAP

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class K, class V>
	class HashMap: public Object
	{
	public:
		virtual V put(K key, V value);
	};
}

#endif
