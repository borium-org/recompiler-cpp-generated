#ifndef ORG__BORIUM__JAVARECOMPILER__CLASSFILE__INDENTEDOUTPUTSTREAM
#define ORG__BORIUM__JAVARECOMPILER__CLASSFILE__INDENTEDOUTPUTSTREAM

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream : public Object
	{
	public:
		IndentedOutputStream(Pointer<String> fileName);
		virtual ~IndentedOutputStream();
		virtual void indent(int level);
		virtual void iprint(Pointer<String> string);
		virtual void print(Pointer<String> string);
		virtual void print(const char* string);
		virtual void println();
		virtual void println(Pointer<String> string);
		virtual void println(const char* string);
		virtual void printHex(int value, int width);
	};
}

#endif
