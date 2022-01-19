#ifndef JAVA__LANG__OBJECT
#define JAVA__LANG__OBJECT

namespace java::lang
{
	class Object
	{
	public:
		Object();
	};

	template<class T>
	class JavaArray
	{

	};

	template<class T>
	class CountedReference
	{
public:
		CountedReference(T & pointer);
	};
}

#endif
