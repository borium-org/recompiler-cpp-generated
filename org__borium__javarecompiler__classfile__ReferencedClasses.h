#pragma once

namespace org::borium::javarecompiler::classfile
{

	class ReferencedClasses
	{
	public:
		virtual Pointer<Iterator<String>> iterator();
	};

}
