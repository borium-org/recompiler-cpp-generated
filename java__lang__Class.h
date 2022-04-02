#pragma once

namespace java::lang
{
	class Object;
	template<class T> class Pointer;
	class String;

	class Class
	{
	public:
		virtual bool isInstance(Pointer<Object> clazz);
		virtual Pointer<String> getSimpleName();
	};

}
