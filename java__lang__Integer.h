#pragma once

namespace java::lang
{

	class Integer
	{
	public:
		static void ClassInit();
		static Pointer<String> toHexString(int value);
	};

}
