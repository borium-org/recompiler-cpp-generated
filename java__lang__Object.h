#ifndef JAVA__LANG__OBJECT
#define JAVA__LANG__OBJECT

namespace java::lang
{
	class Object
	{
	public:
		Object();
		virtual ~Object();
		static void ClassInit();
		virtual int hashCode();
		virtual bool equals(Object *other);

	};

	template<class T> T GetStatic(void (*classInit)(), T field);

	template<class T>
	class JavaArray
	{
	public:
		JavaArray(int length);
		void assignString(int index, const char *value);
		T get(int index);
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
