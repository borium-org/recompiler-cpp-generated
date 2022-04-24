#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class String;
}

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream : public Object
	{
	public:
		IndentedOutputStream(Pointer<String> fileName);
		virtual ~IndentedOutputStream();
		virtual void indent(int level);
		virtual void iprint(Pointer<String> string);
		virtual void iprintln(Pointer<String> string);
		virtual void print(Pointer<String> string);
		virtual void println();
		virtual void println(Pointer<String> string);
		virtual void printHex(int value, int width);
		virtual void close();
	};
}
