#ifndef JAVA__UTIL__ARRAYLIST
#define JAVA__UTIL__ARRAYLIST

#include "java__lang__Object.h"
#include "java__util__List.h"
#include "java__util__Iterator.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class ArrayList: public Object, public List<T>
	{
	public:
		virtual bool add(T element);
		virtual T remove(int index);
		virtual int size();
		virtual Iterator<T>* iterator();
	};
}

#endif
