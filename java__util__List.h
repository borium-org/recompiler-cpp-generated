#pragma once

#include "java__util__Iterator.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class List
	{
	public:
		virtual bool add(Pointer<T> element) = 0;
		virtual Pointer<T> remove(int index) = 0;
		virtual int size() = 0;
		virtual bool contains(Pointer<T> element) = 0;
		virtual Pointer<Iterator<T>> iterator() = 0;
	};
}
