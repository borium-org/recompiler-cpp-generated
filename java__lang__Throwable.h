#pragma once

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
