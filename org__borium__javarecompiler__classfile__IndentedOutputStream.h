#ifndef ORG__BORIUM__JAVARECOMPILER__CLASSFILE__INDENTEDOUTPUTSTREAM
#define ORG__BORIUM__JAVARECOMPILER__CLASSFILE__INDENTEDOUTPUTSTREAM

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream: public Object
	{
	public:
		IndentedOutputStream(String *fileName);
		virtual ~IndentedOutputStream();
	};
}

#endif
