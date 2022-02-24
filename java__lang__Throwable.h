#ifndef JAVA__LANG__THROWABLE
#define JAVA__LANG__THROWABLE

namespace java::lang
{
	class Throwable
	{
	public:
		virtual ~Throwable()
		{
		}
		virtual void printStackTrace() = 0;
	};
}

#endif
