#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"

namespace org::borium::javarecompiler::classfile::constants
{

	Constant::Constant() :
			Object() //
			, tag(0) //
	{
		return;
	}

	Pointer<Constant> Constant::create(int tag)
	{
		switch (tag)
		{
		case 1:
			goto L0060;
		case 2:
			goto L00E8;
		case 3:
			goto L0068;
		case 4:
			goto L0070;
		case 5:
			goto L0078;
		case 6:
			goto L0080;
		case 7:
			goto L0088;
		case 8:
			goto L0090;
		case 9:
			goto L0098;
		case 10:
			goto L00A0;
		case 11:
			goto L00A8;
		case 12:
			goto L00B0;
		case 13:
			goto L00E8;
		case 14:
			goto L00E8;
		case 15:
			goto L00B8;
		case 16:
			goto L00C0;
		case 17:
			goto L00C8;
		case 18:
			goto L00D0;
		case 19:
			goto L00D8;
		case 20:
			goto L00E0;
		default:
			goto L00E8;
		}
		L0060: //
		// ARETURN: Type mismatch
		return new ConstantUtf8Info();
		L0068: //
		// ARETURN: Type mismatch
		return new ConstantInteger();
		L0070: //
		// ARETURN: Type mismatch
		return new ConstantFloat();
		L0078: //
		// ARETURN: Type mismatch
		return new ConstantLong();
		L0080: //
		// ARETURN: Type mismatch
		return new ConstantDouble();
		L0088: //
		// ARETURN: Type mismatch
		return new ConstantClassInfo();
		L0090: //
		// ARETURN: Type mismatch
		return new ConstantStringInfo();
		L0098: //
		// ARETURN: Type mismatch
		return new ConstantFieldrefInfo();
		L00A0: //
		// ARETURN: Type mismatch
		return new ConstantMethodrefInfo();
		L00A8: //
		// ARETURN: Type mismatch
		return new ConstantInterfaceMethodrefInfo();
		L00B0: //
		// ARETURN: Type mismatch
		return new ConstantNameAndTypeInfo();
		L00B8: //
		// ARETURN: Type mismatch
		return new ConstantMethodHandle();
		L00C0: //
		// ARETURN: Type mismatch
		return new ConstantMethodType();
		L00C8: //
		// ARETURN: Type mismatch
		return new ConstantDynamic();
		L00D0: //
		// ARETURN: Type mismatch
		return new ConstantInvokeDynamic();
		L00D8: //
		// ARETURN: Type mismatch
		return new ConstantModule();
		L00E0: //
		// ARETURN: Type mismatch
		return new ConstantPackage();
		L00E8: //
		throw new ClassFormatError((new StringBuilder("Bad constant type "))->append(tag)->toString());
	}

	bool Constant::is(int constantType)
	{
		if ((constantType) != (this->tag))
			goto L000A;
		return 1;
		L000A: //
		return 0;
	}

	void Constant::fixup(Pointer<ConstantPool> constantPool)
	{
		return;
	}

}
