#ifndef JAVA__UTIL__HASHMAP
#define JAVA__UTIL__HASHMAP

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class K, class V>
	class HashMap : public Object
	{
	public:
		HashMap();
		virtual ~HashMap();
		virtual Pointer<V> put(Pointer<K> key, Pointer<V> value);
		virtual Pointer<V> get(Pointer<K> key);
		virtual bool containsKey(Pointer<K> key);
	};
}

#endif
