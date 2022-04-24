#pragma once

namespace org::borium::javarecompiler::cplusplus
{

	class JavaTypeConverter
	{
	public:
		JavaTypeConverter(Pointer<String> type, int something);
		virtual Pointer<String> getCppType();
	};

}
