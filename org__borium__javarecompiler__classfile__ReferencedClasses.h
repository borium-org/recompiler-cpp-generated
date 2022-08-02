#pragma once

namespace org::borium::javarecompiler::classfile
{

	class ReferencedClasses
	{
	public:
		virtual Pointer<Iterator<String>> iterator();
		virtual void add(Pointer<String> type);
	};

}
