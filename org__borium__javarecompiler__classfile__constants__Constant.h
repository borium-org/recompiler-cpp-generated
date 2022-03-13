#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class ClassFormatError;
	class StringBuilder;
}

namespace org::borium::javarecompiler::classfile
{
	class ByteInputStream;
	class IndentedOutputStream;
}

namespace org::borium::javarecompiler::classfile::constants
{
	class ConstantClassInfo;
	class ConstantDouble;
	class ConstantDynamic;
	class ConstantFieldrefInfo;
	class ConstantFloat;
	class ConstantInteger;
	class ConstantInterfaceMethodrefInfo;
	class ConstantInvokeDynamic;
	class ConstantLong;
	class ConstantMethodHandle;
	class ConstantMethodType;
	class ConstantMethodrefInfo;
	class ConstantModule;
	class ConstantNameAndTypeInfo;
	class ConstantPackage;
	class ConstantPool;
	class ConstantStringInfo;
	class ConstantUtf8Info;
}

using namespace java::lang;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile::constants
{

	class Constant : public Object
	{
	public:
		const int CONSTANT_Utf8 = 1;
		const int CONSTANT_Integer = 3;
		const int CONSTANT_Float = 4;
		const int CONSTANT_Long = 5;
		const int CONSTANT_Double = 6;
		const int CONSTANT_Class = 7;
		const int CONSTANT_String = 8;
		const int CONSTANT_Fieldref = 9;
		const int CONSTANT_Methodref = 10;
		const int CONSTANT_InterfaceMethodref = 11;
		const int CONSTANT_NameAndType = 12;
		const int CONSTANT_MethodHandle = 15;
		const int CONSTANT_MethodType = 16;
		const int CONSTANT_Dynamic = 17;
		const int CONSTANT_InvokeDynamic = 18;
		const int CONSTANT_Module = 19;
		const int CONSTANT_Package = 20;
		int tag;

		Constant();
		static Pointer<Constant> create(int tag);
		virtual void dump(Pointer<IndentedOutputStream> param1) = 0;
		virtual bool is(int constantType);
		virtual void fixup(Pointer<ConstantPool> constantPool);
		virtual void read(Pointer<ByteInputStream> param1) = 0;
		virtual bool verify(int param1, int param2, Pointer<ConstantPool> param3, int param4) = 0;
	};

}
