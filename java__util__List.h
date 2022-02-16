#ifndef JAVA__UTIL__LIST
#define JAVA__UTIL__LIST

#include "java__util__Iterator.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class List
	{
	public:
		List();
		virtual ~List();
		virtual bool add(T element)=0;
		virtual T remove(int index)=0;
		virtual int size()=0;
		virtual bool contains(T element);
		virtual Iterator<T>* iterator();
	};
}

#endif
