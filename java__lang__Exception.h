#pragma once

#include "java__lang__Throwable.h"

namespace java::lang
{

	class Exception : public Throwable
	{
	public:
		virtual void printStackTrace();
	};

}
