#pragma once

#include "java__lang__Object.h"

using namespace java::lang;

namespace java::util
{
	template<class K, class V>
	class HashMap : public Object
	{
	public:
		HashMap()
		{
		}
		virtual ~HashMap()
		{
			while (map.GetCount() > 0)
			{
				POSITION pos = map.GetStartPosition();
				Pointer<K> key;
				Pointer<V> value;
				map.GetNextAssoc(pos, key, value);
				map.RemoveKey(key);
				// make sure these Pointer objects are deactivated
				key = nullptr;
				value = nullptr;
			}
		}
		virtual Pointer<V> put(Pointer<K> key, Pointer<V> value)
		{
			Pointer<V> previous;
			bool found = map.Lookup(key, previous);
			map.SetAt(key, value);
			V* returnValue = found ? previous.getValue() : nullptr;
			return returnValue;
		}
		virtual Pointer<V> get(Pointer<K> key)
		{
			Pointer<V> value;
			bool found = map.Lookup(key, value);
			V* returnValue = found ? value.getValue() : nullptr;
			return returnValue;
		}
		virtual bool containsKey(Pointer<K> key)
		{
			Pointer<V> value;
			return map.Lookup(key, value);
		}
	private:
		CMap<Pointer<K>, Pointer<K>, Pointer<V>, Pointer<V>> map;
	};
}
