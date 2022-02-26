#pragma once

#include "java__lang__String.h"
#include "java__lang__Throwable.h"

using namespace java::util;

namespace java::util
{

	class NoSuchElementException : public Throwable
	{
	public:
		NoSuchElementException()
		{
		}
		NoSuchElementException(Pointer<String> message)
		{
		}
		virtual ~NoSuchElementException()
		{
		}
		virtual void printStackTrace()
		{
		}
	private:
		Pointer<String> errorMessage;
	};

}
