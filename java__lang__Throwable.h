#ifndef JAVA__LANG__THROWABLE
#define JAVA__LANG__THROWABLE

namespace java::lang
{
	class Throwable
	{
	public:
		Throwable()
		{
		}
		virtual ~Throwable();
		virtual void printStackTrace();
	};
}

#endif
