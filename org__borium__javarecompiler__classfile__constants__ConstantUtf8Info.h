#pragma once

#include "org__borium__javarecompiler__classfile__constants__Constant.h"

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantUtf8Info : public Constant
	{
	public:
		virtual Pointer<String> string();
	};

}
