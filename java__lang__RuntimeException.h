#ifndef JAVA__LANG__RUNTIMEEXCEPTION
#define JAVA__LANG__RUNTIMEEXCEPTION

#include "java__lang__String.h"
#include "java__lang__Throwable.h"

using namespace java::lang;

namespace java::lang
{

	class RuntimeException : public Throwable
	{
	public:
		//RuntimeException();
		RuntimeException(Pointer<String> message);
		virtual ~RuntimeException();
		virtual void printStackTrace();
	private:
		Pointer<String> errorMessage;
	};

}

#endif
