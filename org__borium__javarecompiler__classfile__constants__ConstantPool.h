#pragma once

#include "java__lang__Class.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantUtf8Info.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantPool: public Object
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
