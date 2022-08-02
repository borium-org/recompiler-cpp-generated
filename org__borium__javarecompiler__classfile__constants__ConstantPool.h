#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class String;
}

namespace java::util
{
	template <class A> class Iterator;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
	class ReferencedClasses;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class Constant;
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
		virtual void addReferencedClasses(Pointer<ReferencedClasses> referencedClasses);
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<Constant> get(int index);
		virtual Pointer<String> getString(int index);
		virtual void read(Pointer<ByteInputStream> in);
		virtual void verify(int majorVersion, int minorVersion);
	};

}
