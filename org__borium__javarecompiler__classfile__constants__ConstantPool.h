#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class Class;
	class ClassFormatError;
	class String;
	class StringBuilder;
}

namespace java::util
{
	template<class T> class ArrayList;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
	class ConstantClassInfo;
	class ConstantUtf8Info;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantPool : public Object
	{
	public:
		Pointer<JavaArray<Constant>> constants;

		ConstantPool();
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<Constant> get(int index);
		virtual Pointer<Constant> get(int index, Pointer<Class> clazz);
		virtual Pointer<ArrayList<String>> getReferencedClasses();
		virtual Pointer<String> getString(int index);
		virtual void read(Pointer<ByteInputStream> in);
		virtual void verify(int majorVersion, int minorVersion);
	};

}
