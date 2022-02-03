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
	public:
		JavaArray(int);
		void assignString(int index, const char * value);
		int length;
	};

	template<class T>
	class CountedReference
	{
	public:
		CountedReference(T &pointer);
	};
}

#endif
