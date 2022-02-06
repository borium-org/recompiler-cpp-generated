#ifndef JAVA__LANG__STRING
#define JAVA__LANG__STRING

namespace java::lang
{
	class String: public Object
	{
	public:
		String();
		virtual ~String();
		virtual int hashCode();
		virtual bool equals(const char *other);
	};
}

#endif
