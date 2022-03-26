#pragma once

#include "java__io__DataInputStream.h"
#include "java__io__FileInputStream.h"
#include "java__io__IOException.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__ClassAttribute.h"
#include "org__borium__javarecompiler__classfile__ClassField.h"
#include "org__borium__javarecompiler__classfile__ClassMethod.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile
{

	class ClassFile : public Object
	{
	public:
		Pointer<ByteInputStream> in;
		int majorVersion;
		int minorVersion;
		Pointer<ConstantPool> cp;
		int accessFlags;
		int thisClass;
		int superClass;
		Pointer<JavaArray<int>> interfaces;
		Pointer<JavaArray<ClassField>> fields;
		Pointer<JavaArray<ClassMethod>> methods;
		Pointer<HashMap<String, ClassAttribute>> attributes;
		Pointer<ArrayList<ClassAttribute>> attributeList;
		Pointer<String> className;
		Pointer<String> superClassName;

		ClassFile();
		static int printAccessFlag(Pointer<IndentedOutputStream> stream, int flags, int bit, Pointer<String> string);
		static int printAccessFlag(Pointer<IndentedOutputStream> stream, int flags, int bit, const char* string);
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<String> getClassName();
		virtual Pointer<String> getClassSimpleName();
		virtual Pointer<JavaArray<ClassField>> getFields();
		virtual Pointer<JavaArray<ClassMethod>> getMethods();
		virtual Pointer<String> getParentClassName();
		virtual Pointer<ReferencedClasses> getReferencedClasses();
		virtual void read(Pointer<String> fileName);
		virtual void dumpAttributes(Pointer<IndentedOutputStream> stream);
		virtual void dumpClassInfo(Pointer<IndentedOutputStream> stream);
		virtual void dumpFields(Pointer<IndentedOutputStream> stream);
		virtual void dumpInterfaces(Pointer<IndentedOutputStream> stream);
		virtual void dumpMethods(Pointer<IndentedOutputStream> stream);
		virtual void readAttributes();
		virtual void readClassInfo();
		virtual void readConstants();
		virtual void readFields();
		virtual void readID();
		virtual void readInterfaces();
		virtual void readMethods();
		virtual void readVersion();
	};

}
