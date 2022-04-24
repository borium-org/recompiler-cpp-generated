#include "stdafx.h"
#include "org__borium__javarecompiler__Statics.h"

#include "java__lang__Integer.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__cplusplus__JavaTypeConverter.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler
{

	Statics::Statics() :
		//		aload 0
		//				stack[0]: Statics=this
		//		invokespecial java.lang.Object.<init>
		Object() //
		//				stack: empty
	{
		//		return
		return;
		//				stack: empty
	}

	Pointer<String> Statics::addPointerIfNeeded(Pointer<String> type)
	{
		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_00CC;
		//		aload 0
		//				stack[0]: String=type
		//		dup
		//				stack[0]: String=type
		//				stack[1]: String=type
		//		astore 1
		local_0002 = type;
		//				stack[0]: String=type
		//		invokevirtual java.lang.String.hashCode
		//				stack[0]: int=type->hashCode()
		//		lookupswitch 9 cases
		switch (type->hashCode())
		{
		case (int)0xB0F77BD1:
			goto L0058;
		case (int)0x000197EF:
			goto L0064;
		case (int)0x002E3AEA:
			goto L0070;
		case (int)0x002E6108:
			goto L007C;
		case (int)0x002E9356:
			goto L0088;
		case (int)0x0032C67C:
			goto L0094;
		case (int)0x00375194:
			goto L00A0;
		case (int)0x05D0225C:
			goto L00AC;
		case (int)0x0685847C:
			goto L00B8;
		default:
			goto L00C6;
		}
		//				stack: empty
	L0058: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "double"
		//				stack[0]: String=local_0002
		//				stack[1]: String="double"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("double")
		//		ifne L00C4
		if (local_0002->equals("double"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L0064: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "int"
		//				stack[0]: String=local_0002
		//				stack[1]: String="int"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("int")
		//		ifne L00C4
		if (local_0002->equals("int"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L0070: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "bool"
		//				stack[0]: String=local_0002
		//				stack[1]: String="bool"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("bool")
		//		ifne L00C4
		if (local_0002->equals("bool"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L007C: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "byte"
		//				stack[0]: String=local_0002
		//				stack[1]: String="byte"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("byte")
		//		ifne L00C4
		if (local_0002->equals("byte"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L0088: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "char"
		//				stack[0]: String=local_0002
		//				stack[1]: String="char"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("char")
		//		ifne L00C4
		if (local_0002->equals("char"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L0094: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "long"
		//				stack[0]: String=local_0002
		//				stack[1]: String="long"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("long")
		//		ifne L00C4
		if (local_0002->equals("long"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L00A0: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "void"
		//				stack[0]: String=local_0002
		//				stack[1]: String="void"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("void")
		//		ifne L00C4
		if (local_0002->equals("void"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L00AC: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "float"
		//				stack[0]: String=local_0002
		//				stack[1]: String="float"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("float")
		//		ifne L00C4
		if (local_0002->equals("float"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L00B8: //
		//		aload 1
		//				stack[0]: String=local_0002
		//		ldc "short"
		//				stack[0]: String=local_0002
		//				stack[1]: String="short"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0002->equals("short")
		//		ifne L00C4
		if (local_0002->equals("short"))
			goto L00C4;
		//				stack: empty
		//		goto L00C6
		goto L00C6;
		//				stack: empty
	L00C4: //
		//		aload 0
		//				stack[0]: String=type
		//		areturn
		return type;
		//				stack: empty
	L00C6: //
		//		new java.lang.StringBuilder
		//				stack[0]: StringBuilder=new
		//		dup
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//		ldc "Pointer<"
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//				stack[2]: String="Pointer<"
		//		invokespecial java.lang.StringBuilder.<init>
		temp_00CC = new StringBuilder("Pointer<");
		//				stack[0]: StringBuilder=temp_00CC
		//		aload 0
		//				stack[0]: StringBuilder=temp_00CC
		//				stack[1]: String=type
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: StringBuilder=temp_00CC->append(type)
		//		ldc ">"
		//				stack[0]: StringBuilder=temp_00CC->append(type)
		//				stack[1]: String=">"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: StringBuilder=temp_00CC->append(type)->append(">")
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: String=temp_00CC->append(type)->append(">")->toString()
		//		areturn
		return temp_00CC->append(type)->append(">")->toString();
		//				stack: empty
	}

	Pointer<String> Statics::addPointersIfNeeded(Pointer<String> methodType)
	{
		Pointer<String> signature;
		Pointer<String> result;
		int pos = 0;
		Pointer<String> type;
		Pointer<StringBuilder> temp_003E;
		Pointer<StringBuilder> temp_0065;
		Pointer<StringBuilder> temp_00A0;
		Pointer<StringBuilder> temp_00C3;
		Pointer<StringBuilder> temp_00E4;
		//		aload 0
		//				stack[0]: String=methodType
		//		astore 1
		signature = methodType;
		//				stack: empty
		//		aload 1
		//				stack[0]: String=signature
		//		ldc "("
		//				stack[0]: String=signature
		//				stack[1]: String="("
		//		invokevirtual java.lang.String.startsWith
		//				stack[0]: bool=signature->startsWith("(")
		//		ldc "Method type: Method() expected"
		//				stack[0]: bool=signature->startsWith("(")
		//				stack[1]: String="Method type: Method() expected"
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		Statics::Assert(signature->startsWith("("), "Method type: Method() expected");
		//				stack: empty
		//		ldc "("
		//				stack[0]: String="("
		//		astore 2
		result = "(";
		//				stack: empty
		//		aload 1
		//				stack[0]: String=signature
		//		iconst 1
		//				stack[0]: String=signature
		//				stack[1]: int=1
		//		invokevirtual java.lang.String.substring
		//				stack[0]: String=signature->substring(1)
		//		astore 1
		signature = signature->substring(1);
		//				stack: empty
		//		goto L00B2
		goto L00B2;
		//				stack: empty
	L0019: //
		//		aload 1
		//				stack[0]: String=signature
		//		bipush 32
		//				stack[0]: String=signature
		//				stack[1]: int=32
		//		invokevirtual java.lang.String.indexOf
		//				stack[0]: int=signature->indexOf(32)
		//		istore 3
		pos = signature->indexOf(32);
		//				stack: empty
		//		iload 3
		//				stack[0]: int=pos
		//		ifle L0028
		if ((pos) <= 0)
			goto L0028;
		//				stack: empty
		//		iconst 1
		//				stack[0]: int=1
		//		goto L0029
		goto L0029;
		//				stack[0]: int=1
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: int=0
		//		ldc "Method type: Space between type and name not found"
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: String="Method type: Space between type and name not found"
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert(0, "Method type: Space between type and name not found");
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=0
		//		iload 3
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=0
		//				stack[3]: int=pos
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=signature->substring(0, pos)
		//		astore 4
		type = signature->substring(0, pos);
		//				stack[0]: int=1
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=result
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=String::valueOf(result)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_003E = new StringBuilder(String::valueOf(result));
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_003E
		//		aload 4
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_003E
		//				stack[2]: String=type
		//		invokestatic org.borium.javarecompiler.Statics.addPointerIfNeeded
		Statics::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_003E
		//				stack[2]: String=Statics::addPointerIfNeeded(type)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_003E->append(Statics::addPointerIfNeeded(type))
		//		ldc " "
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_003E->append(Statics::addPointerIfNeeded(type))
		//				stack[2]: String=" "
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_003E->append(Statics::addPointerIfNeeded(type))->append(" ")
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: String=temp_003E->append(Statics::addPointerIfNeeded(type))->append(" ")->toString()
		//		astore 2
		result = temp_003E->append(Statics::addPointerIfNeeded(type))->append(" ")->toString();
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iload 3
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=pos
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=pos
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=(pos)+(1)
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=signature->substring((pos)+(1))
		//		astore 1
		signature = signature->substring((pos)+(1));
		//				stack[0]: int=1
		//		goto L007B
		goto L007B;
		//				stack[0]: int=1
	L005D: //
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=result
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=String::valueOf(result)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0065 = new StringBuilder(String::valueOf(result));
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0065
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0065
		//				stack[2]: String=signature
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0065
		//				stack[2]: String=signature
		//				stack[3]: int=0
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0065
		//				stack[2]: String=signature
		//				stack[3]: int=0
		//				stack[4]: int=1
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0065
		//				stack[2]: String=signature->substring(0, 1)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0065->append(signature->substring(0, 1))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: String=temp_0065->append(signature->substring(0, 1))->toString()
		//		astore 2
		result = temp_0065->append(signature->substring(0, 1))->toString();
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=1
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=signature->substring(1)
		//		astore 1
		signature = signature->substring(1);
		//				stack[0]: int=1
	L007B: //
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=0
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: int=1
		//				stack[1]: char=signature->charAt(0)
		//		bipush 44
		//				stack[0]: int=1
		//				stack[1]: char=signature->charAt(0)
		//				stack[2]: int=44
		//		if_icmpeq L008F
		if ((signature->charAt(0)) == (44))
			goto L008F;
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=0
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: int=1
		//				stack[1]: char=signature->charAt(0)
		//		bipush 41
		//				stack[0]: int=1
		//				stack[1]: char=signature->charAt(0)
		//				stack[2]: int=41
		//		if_icmpne L005D
		if ((signature->charAt(0)) != (41))
			goto L005D;
		//				stack[0]: int=1
	L008F: //
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		ldc ", "
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: String=", "
		//		invokevirtual java.lang.String.startsWith
		//				stack[0]: int=1
		//				stack[1]: bool=signature->startsWith(", ")
		//		ifeq L00B2
		if (!(signature->startsWith(", ")))
			goto L00B2;
		//				stack[0]: int=1
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=result
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=String::valueOf(result)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_00A0 = new StringBuilder(String::valueOf(result));
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00A0
		//		ldc ", "
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00A0
		//				stack[2]: String=", "
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00A0->append(", ")
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: String=temp_00A0->append(", ")->toString()
		//		astore 2
		result = temp_00A0->append(", ")->toString();
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iconst 2
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=2
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=signature->substring(2)
		//		astore 1
		signature = signature->substring(2);
		//				stack[0]: int=1
	L00B2: //
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		ldc ")"
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: String=")"
		//		invokevirtual java.lang.String.startsWith
		//				stack[0]: int=1
		//				stack[1]: bool=signature->startsWith(")")
		//		ifeq L0019
		if (!(signature->startsWith(")")))
			goto L0019;
		//				stack[0]: int=1
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=result
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=String::valueOf(result)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_00C3 = new StringBuilder(String::valueOf(result));
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00C3
		//		bipush 41
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00C3
		//				stack[2]: int=41
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00C3->append(41)
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: String=temp_00C3->append(41)->toString()
		//		astore 2
		result = temp_00C3->append(41)->toString();
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//				stack[2]: int=1
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=signature->substring(1)
		//		astore 1
		signature = signature->substring(1);
		//				stack[0]: int=1
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: String=signature
		//		invokevirtual java.lang.String.length
		//				stack[0]: int=1
		//				stack[1]: int=signature->length()
		//		ifle L00F2
		if ((signature->length()) <= 0)
			goto L00F2;
		//				stack[0]: int=1
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=result
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=String::valueOf(result)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_00E4 = new StringBuilder(String::valueOf(result));
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00E4
		//		aload 1
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00E4
		//				stack[2]: String=signature
		//		invokestatic org.borium.javarecompiler.Statics.addPointerIfNeeded
		Statics::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00E4
		//				stack[2]: String=Statics::addPointerIfNeeded(signature)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_00E4->append(Statics::addPointerIfNeeded(signature))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: String=temp_00E4->append(Statics::addPointerIfNeeded(signature))->toString()
		//		astore 2
		result = temp_00E4->append(Statics::addPointerIfNeeded(signature))->toString();
		//				stack[0]: int=1
	L00F2: //
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: String=result
		//		areturn
		return result;
		//				stack[0]: int=1
	}

	void Statics::Assert(bool condition, Pointer<String> errorMessage)
	{
		Pointer<RuntimeException> temp_0009;
		//		iload 0
		//				stack[0]: bool=condition
		//		ifne L000D
		if (condition)
			goto L000D;
		//				stack: empty
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException=new
		//		dup
		//				stack[0]: RuntimeException=new
		//				stack[1]: RuntimeException=new
		//		aload 1
		//				stack[0]: RuntimeException=new
		//				stack[1]: RuntimeException=new
		//				stack[2]: String=errorMessage
		//		invokespecial java.lang.RuntimeException.<init>
		temp_0009 = new RuntimeException(errorMessage);
		//				stack[0]: RuntimeException=temp_0009
		//		athrow
		throw temp_0009;
		//				stack: empty
	L000D: //
		//		return
		return;
		//				stack: empty
	}

	void Statics::Check(Pointer<IndentedOutputStream> stream, bool condition, Pointer<String> errorMessage)
	{
		Pointer<StringBuilder> temp_000B;
		//		iload 1
		//				stack[0]: bool=condition
		//		ifne L0018
		if (condition)
			goto L0018;
		//				stack: empty
		//		aload 0
		//				stack[0]: IndentedOutputStream=stream
		//		new java.lang.StringBuilder
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		ldc "// "
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String="// "
		//		invokespecial java.lang.StringBuilder.<init>
		temp_000B = new StringBuilder("// ");
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: StringBuilder=temp_000B
		//		aload 2
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: StringBuilder=temp_000B
		//				stack[2]: String=errorMessage
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: StringBuilder=temp_000B->append(errorMessage)
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: IndentedOutputStream=stream
		//				stack[1]: String=temp_000B->append(errorMessage)->toString()
		//		invokevirtual org.borium.javarecompiler.classfile.IndentedOutputStream.iprintln
		stream->iprintln(temp_000B->append(errorMessage)->toString());
		//				stack: empty
	L0018: //
		//		return
		return;
		//				stack: empty
	}

	Pointer<String> Statics::commaSeparatedList(Pointer<JavaArray<String>> values)
	{
		Pointer<String> result;
		Pointer<String> separator;
		Pointer<String> param;
		Pointer<JavaArray<String>> local_0008;
		Pointer<StringBuilder> temp_0021;
		//		ldc ""
		//				stack[0]: String=""
		//		astore 1
		result = "";
		//				stack: empty
		//		ldc ""
		//				stack[0]: String=""
		//		astore 2
		separator = "";
		//				stack: empty
		//		aload 0
		//				stack[0]: JavaArray<String>=values
		//		dup
		//				stack[0]: JavaArray<String>=values
		//				stack[1]: JavaArray<String>=values
		//		astore 6
		local_0008 = (JavaArray<String>*)(values.getValue());
		//				stack[0]: JavaArray<String>=values
		//		arraylength
		//				stack[0]: int=values->length
		//		istore 5
		int local_000B = values->length;
		//				stack: empty
		//		iconst 0
		//				stack[0]: int=0
		//		istore 4
		int local_000E = 0;
		//				stack: empty
		//		goto L0036
		goto L0036;
		//				stack: empty
	L0013: //
		//		aload 6
		//				stack[0]: JavaArray<String>=local_0008
		//		iload 4
		//				stack[0]: JavaArray<String>=local_0008
		//				stack[1]: int=local_000E
		//		aaload
		//				stack[0]: String=local_0008->get(local_000E)
		//		astore 3
		param = local_0008->get(local_000E);
		//				stack: empty
		//		new java.lang.StringBuilder
		//				stack[0]: StringBuilder=new
		//		dup
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//		aload 1
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//				stack[2]: String=result
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//				stack[2]: String=String::valueOf(result)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0021 = new StringBuilder(String::valueOf(result));
		//				stack[0]: StringBuilder=temp_0021
		//		aload 2
		//				stack[0]: StringBuilder=temp_0021
		//				stack[1]: String=separator
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: StringBuilder=temp_0021->append(separator)
		//		aload 3
		//				stack[0]: StringBuilder=temp_0021->append(separator)
		//				stack[1]: String=param
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: StringBuilder=temp_0021->append(separator)->append(param)
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: String=temp_0021->append(separator)->append(param)->toString()
		//		astore 1
		result = temp_0021->append(separator)->append(param)->toString();
		//				stack: empty
		//		ldc ", "
		//				stack[0]: String=", "
		//		astore 2
		separator = ", ";
		//				stack: empty
		//		iinc 4 1
		local_000E += 1;
		//				stack: empty
	L0036: //
		//		iload 4
		//				stack[0]: int=local_000E
		//		iload 5
		//				stack[0]: int=local_000E
		//				stack[1]: int=local_000B
		//		if_icmplt L0013
		if ((local_000E) < (local_000B))
			goto L0013;
		//				stack: empty
		//		aload 1
		//				stack[0]: String=result
		//		areturn
		return result;
		//				stack: empty
	}

	Pointer<String> Statics::dotToNamespace(Pointer<String> dots)
	{
		//		ldc "::"
		//				stack[0]: String="::"
		//		aload 0
		//				stack[0]: String="::"
		//				stack[1]: String=dots
		//		ldc "[.]"
		//				stack[0]: String="::"
		//				stack[1]: String=dots
		//				stack[2]: String="[.]"
		//		invokevirtual java.lang.String.split
		//				stack[0]: String="::"
		//				stack[1]: String[]=dots->split("[.]")
		//		invokestatic java.lang.String.join
		String::ClassInit();
		// Parameter type mismatch
		// Parameter type mismatch
		//				stack[0]: String=String::join("::", dots->split("[.]"))
		//		areturn
		return String::join("::", dots->split("[.]"));
		//				stack: empty
	}

	int Statics::getParameterCount(Pointer<String> javaDescriptor)
	{
		Pointer<JavaRawArray<int>> data;
		Pointer<RuntimeException> temp_000F;
		Pointer<JavaRawArray<int>> temp_0014;
		//		aload 0
		//				stack[0]: String=javaDescriptor
		//		ldc "("
		//				stack[0]: String=javaDescriptor
		//				stack[1]: String="("
		//		invokevirtual java.lang.String.startsWith
		//				stack[0]: bool=javaDescriptor->startsWith("(")
		//		ifne L0013
		if (javaDescriptor->startsWith("("))
			goto L0013;
		//				stack: empty
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException=new
		//		dup
		//				stack[0]: RuntimeException=new
		//				stack[1]: RuntimeException=new
		//		ldc "Get parameter count for non-method"
		//				stack[0]: RuntimeException=new
		//				stack[1]: RuntimeException=new
		//				stack[2]: String="Get parameter count for non-method"
		//		invokespecial java.lang.RuntimeException.<init>
		temp_000F = new RuntimeException("Get parameter count for non-method");
		//				stack[0]: RuntimeException=temp_000F
		//		athrow
		throw temp_000F;
		//				stack: empty
	L0013: //
		//		iconst 2
		//				stack[0]: int=2
		//		newarray int
		temp_0014 = new JavaRawArray<int>(2);
		//				stack[0]: JavaRawArray<int>=temp_0014
		//		dup
		//				stack[0]: JavaRawArray<int>=temp_0014
		//				stack[1]: JavaRawArray<int>=temp_0014
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=temp_0014
		//				stack[1]: JavaRawArray<int>=temp_0014
		//				stack[2]: int=0
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=temp_0014
		//				stack[1]: JavaRawArray<int>=temp_0014
		//				stack[2]: int=0
		//				stack[3]: int=1
		//		iastore
		temp_0014->assign(0, 1);
		//				stack[0]: JavaRawArray<int>=temp_0014
		//		astore 1
		data = (JavaRawArray<int>*)(temp_0014.getValue());
		//				stack: empty
		//		goto L0023
		goto L0023;
		//				stack: empty
	L001E: //
		//		aload 0
		//				stack[0]: String=javaDescriptor
		//		aload 1
		//				stack[0]: String=javaDescriptor
		//				stack[1]: JavaRawArray<int>=data
		//		invokestatic org.borium.javarecompiler.Statics.parseSingleType
		Statics::ClassInit();
		Statics::parseSingleType(javaDescriptor, data);
		//				stack: empty
	L0023: //
		//		aload 0
		//				stack[0]: String=javaDescriptor
		//		aload 1
		//				stack[0]: String=javaDescriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=javaDescriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=javaDescriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=javaDescriptor->charAt(data->get(0))
		//		bipush 41
		//				stack[0]: char=javaDescriptor->charAt(data->get(0))
		//				stack[1]: int=41
		//		if_icmpne L001E
		if ((javaDescriptor->charAt(data->get(0))) != (41))
			goto L001E;
		//				stack: empty
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//		iaload
		//				stack[0]: int=data->get(1)
		//		ireturn
		return data->get(1);
		//				stack: empty
	}

	Pointer<String> Statics::hexString(int value, int length)
	{
		Pointer<String> result;
		Pointer<StringBuilder> temp_0006;
		//		new java.lang.StringBuilder
		//				stack[0]: StringBuilder=new
		//		dup
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//		ldc "00000000"
		//				stack[0]: StringBuilder=new
		//				stack[1]: StringBuilder=new
		//				stack[2]: String="00000000"
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0006 = new StringBuilder("00000000");
		//				stack[0]: StringBuilder=temp_0006
		//		iload 0
		//				stack[0]: StringBuilder=temp_0006
		//				stack[1]: int=value
		//		invokestatic java.lang.Integer.toHexString
		Integer::ClassInit();
		//				stack[0]: StringBuilder=temp_0006
		//				stack[1]: String=Integer::toHexString(value)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: StringBuilder=temp_0006->append(Integer::toHexString(value))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: String=temp_0006->append(Integer::toHexString(value))->toString()
		//		astore 2
		result = temp_0006->append(Integer::toHexString(value))->toString();
		//				stack: empty
		//		aload 2
		//				stack[0]: String=result
		//		aload 2
		//				stack[0]: String=result
		//				stack[1]: String=result
		//		invokevirtual java.lang.String.length
		//				stack[0]: String=result
		//				stack[1]: int=result->length()
		//		iload 1
		//				stack[0]: String=result
		//				stack[1]: int=result->length()
		//				stack[2]: int=length
		//		isub
		//				stack[0]: String=result
		//				stack[1]: int=(result->length()) - (length)
		//		invokevirtual java.lang.String.substring
		//				stack[0]: String=result->substring((result->length()) - (length))
		//		astore 2
		result = result->substring((result->length()) - (length));
		//				stack: empty
		//		aload 2
		//				stack[0]: String=result
		//		invokevirtual java.lang.String.toUpperCase
		//				stack[0]: String=result->toUpperCase()
		//		areturn
		return result->toUpperCase();
		//				stack: empty
	}

	bool Statics::isTemplate(Pointer<String> type)
	{
		int index = 0;
		//		aload 0
		//				stack[0]: String=type
		//		bipush 60
		//				stack[0]: String=type
		//				stack[1]: int=60
		//		invokevirtual java.lang.String.indexOf
		//				stack[0]: int=type->indexOf(60)
		//		istore 1
		index = type->indexOf(60);
		//				stack: empty
		//		iload 1
		//				stack[0]: int=index
		//		ifeq L000F
		if ((index) == 0)
			goto L000F;
		//				stack: empty
		//		iconst 1
		//				stack[0]: int=1
		//		goto L0010
		goto L0010;
		//				stack[0]: int=1
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: int=0
		//		ldc "Template: Starts with '<'"
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: String="Template: Starts with '<'"
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert(0, "Template: Starts with '<'");
		//				stack[0]: int=1
		//		iload 1
		//				stack[0]: int=1
		//				stack[1]: int=index
		//		ifle L001B
		if ((index) <= 0)
			goto L001B;
		//				stack[0]: int=1
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: int=1
		//		ireturn
		return 1;
		//				stack[0]: int=1
	L001B: //
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: int=0
		//		ireturn
		return 0;
		//				stack[0]: int=1
	}

	Pointer<String> Statics::javaToCppClass(Pointer<String> javaClassName)
	{
		Pointer<JavaArray<String>> split;
		//		aload 0
		//				stack[0]: String=javaClassName
		//		ldc "[.]"
		//				stack[0]: String=javaClassName
		//				stack[1]: String="[.]"
		//		invokevirtual java.lang.String.split
		//				stack[0]: String[]=javaClassName->split("[.]")
		//		astore 1
		split = (JavaArray<String>*)(javaClassName->split("[.]").getValue());
		//				stack: empty
		//		ldc "::"
		//				stack[0]: String="::"
		//		aload 1
		//				stack[0]: String="::"
		//				stack[1]: JavaArray<String>=split
		//		invokestatic java.lang.String.join
		String::ClassInit();
		// Parameter type mismatch
		//				stack[0]: String=String::join("::", split)
		//		areturn
		return String::join("::", split);
		//				stack: empty
	}

	Pointer<String> Statics::parseJavaReturnType(Pointer<String> javaMethodSignature)
	{
		int pos = 0;
		Pointer<String> type;
		int dimensions = 0;
		Pointer<String> returnType;
		Pointer<JavaTypeConverter> temp_00EE;
		Pointer<StringBuilder> temp_0107;
		Pointer<StringBuilder> temp_0120;
		//		aload 0
		//				stack[0]: String=javaMethodSignature
		//		bipush 41
		//				stack[0]: String=javaMethodSignature
		//				stack[1]: int=41
		//		invokevirtual java.lang.String.indexOf
		//				stack[0]: int=javaMethodSignature->indexOf(41)
		//		istore 1
		pos = javaMethodSignature->indexOf(41);
		//				stack: empty
		//		iload 1
		//				stack[0]: int=pos
		//		iconst 1
		//				stack[0]: int=pos
		//				stack[1]: int=1
		//		if_icmplt L0010
		if ((pos) < (1))
			goto L0010;
		//				stack: empty
		//		iconst 1
		//				stack[0]: int=1
		//		goto L0011
		goto L0011;
		//				stack[0]: int=1
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: int=0
		//		ldc "Method with no return type"
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: String="Method with no return type"
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert(0, "Method with no return type");
		//				stack[0]: int=1
		//		aload 0
		//				stack[0]: int=1
		//				stack[1]: String=javaMethodSignature
		//		iload 1
		//				stack[0]: int=1
		//				stack[1]: String=javaMethodSignature
		//				stack[2]: int=pos
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: String=javaMethodSignature
		//				stack[2]: int=pos
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: int=1
		//				stack[1]: String=javaMethodSignature
		//				stack[2]: int=(pos)+(1)
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=javaMethodSignature->substring((pos)+(1))
		//		astore 2
		type = javaMethodSignature->substring((pos)+(1));
		//				stack[0]: int=1
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: int=0
		//		istore 3
		dimensions = 0;
		//				stack[0]: int=1
		//		goto L002C
		goto L002C;
		//				stack[0]: int=1
	L0023: //
		//		iinc 3 1
		dimensions += 1;
		//				stack[0]: int=1
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: String=type
		//		iconst 1
		//				stack[0]: int=1
		//				stack[1]: String=type
		//				stack[2]: int=1
		//		invokevirtual java.lang.String.substring
		//				stack[0]: int=1
		//				stack[1]: String=type->substring(1)
		//		astore 2
		type = type->substring(1);
		//				stack[0]: int=1
	L002C: //
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: String=type
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: String=type
		//				stack[2]: int=0
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: int=1
		//				stack[1]: char=type->charAt(0)
		//		bipush 91
		//				stack[0]: int=1
		//				stack[1]: char=type->charAt(0)
		//				stack[2]: int=91
		//		if_icmpeq L0023
		if ((type->charAt(0)) == (91))
			goto L0023;
		//				stack[0]: int=1
		//		ldc ""
		//				stack[0]: int=1
		//				stack[1]: String=""
		//		astore 4
		returnType = "";
		//				stack[0]: int=1
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: String=type
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: String=type
		//				stack[2]: int=0
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: int=1
		//				stack[1]: char=type->charAt(0)
		//		tableswitch 25 cases
		switch (type->charAt(0))
		{
		case 66:
			goto L00B0;
		case 67:
			goto L00B7;
		case 68:
			goto L00BE;
		case 69:
			goto L0100;
		case 70:
			goto L00C5;
		case 71:
			goto L0100;
		case 72:
			goto L0100;
		case 73:
			goto L00CC;
		case 74:
			goto L00D3;
		case 75:
			goto L0100;
		case 76:
			goto L00E8;
		case 77:
			goto L0100;
		case 78:
			goto L0100;
		case 79:
			goto L0100;
		case 80:
			goto L0100;
		case 81:
			goto L0100;
		case 82:
			goto L0100;
		case 83:
			goto L00DA;
		case 84:
			goto L0100;
		case 85:
			goto L0100;
		case 86:
			goto L00F9;
		case 87:
			goto L0100;
		case 88:
			goto L0100;
		case 89:
			goto L0100;
		case 90:
			goto L00E1;
		default:
			goto L0100;
		}
		//				stack[0]: int=1
	L00B0: //
		//		ldc "byte"
		//				stack[0]: int=1
		//				stack[1]: String="byte"
		//		astore 4
		returnType = "byte";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00B7: //
		//		ldc "char"
		//				stack[0]: int=1
		//				stack[1]: String="char"
		//		astore 4
		returnType = "char";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00BE: //
		//		ldc "double"
		//				stack[0]: int=1
		//				stack[1]: String="double"
		//		astore 4
		returnType = "double";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00C5: //
		//		ldc "float"
		//				stack[0]: int=1
		//				stack[1]: String="float"
		//		astore 4
		returnType = "float";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00CC: //
		//		ldc "int"
		//				stack[0]: int=1
		//				stack[1]: String="int"
		//		astore 4
		returnType = "int";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00D3: //
		//		ldc "long"
		//				stack[0]: int=1
		//				stack[1]: String="long"
		//		astore 4
		returnType = "long";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00DA: //
		//		ldc "short"
		//				stack[0]: int=1
		//				stack[1]: String="short"
		//		astore 4
		returnType = "short";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00E1: //
		//		ldc "bool"
		//				stack[0]: int=1
		//				stack[1]: String="bool"
		//		astore 4
		returnType = "bool";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00E8: //
		//		new org.borium.javarecompiler.cplusplus.JavaTypeConverter
		//				stack[0]: int=1
		//				stack[1]: JavaTypeConverter=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: JavaTypeConverter=new
		//				stack[2]: JavaTypeConverter=new
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: JavaTypeConverter=new
		//				stack[2]: JavaTypeConverter=new
		//				stack[3]: String=type
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: JavaTypeConverter=new
		//				stack[2]: JavaTypeConverter=new
		//				stack[3]: String=type
		//				stack[4]: int=0
		//		invokespecial org.borium.javarecompiler.cplusplus.JavaTypeConverter.<init>
		// Parameter type mismatch
		// Parameter type mismatch
		temp_00EE = new JavaTypeConverter(type, 0);
		//				stack[0]: int=1
		//				stack[1]: JavaTypeConverter=temp_00EE
		//		invokevirtual org.borium.javarecompiler.cplusplus.JavaTypeConverter.getCppType
		//				stack[0]: int=1
		//				stack[1]: String=temp_00EE->getCppType()
		//		astore 4
		returnType = temp_00EE->getCppType();
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L00F9: //
		//		ldc "void"
		//				stack[0]: int=1
		//				stack[1]: String="void"
		//		astore 4
		returnType = "void";
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L0100: //
		//		iconst 0
		//				stack[0]: int=1
		//				stack[1]: int=0
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: StringBuilder=new
		//				stack[3]: StringBuilder=new
		//		ldc "Unhandled type "
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: StringBuilder=new
		//				stack[3]: StringBuilder=new
		//				stack[4]: String="Unhandled type "
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0107 = new StringBuilder("Unhandled type ");
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: StringBuilder=temp_0107
		//		aload 2
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: StringBuilder=temp_0107
		//				stack[3]: String=type
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: StringBuilder=temp_0107->append(type)
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: int=0
		//				stack[2]: String=temp_0107->append(type)->toString()
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert(0, temp_0107->append(type)->toString());
		//				stack[0]: int=1
		//		goto L0130
		goto L0130;
		//				stack[0]: int=1
	L0117: //
		//		new java.lang.StringBuilder
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//		dup
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//		aload 4
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=returnType
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=new
		//				stack[2]: StringBuilder=new
		//				stack[3]: String=String::valueOf(returnType)
		//		invokespecial java.lang.StringBuilder.<init>
		temp_0120 = new StringBuilder(String::valueOf(returnType));
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0120
		//		ldc "[]"
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0120
		//				stack[2]: String="[]"
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: int=1
		//				stack[1]: StringBuilder=temp_0120->append("[]")
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: int=1
		//				stack[1]: String=temp_0120->append("[]")->toString()
		//		astore 4
		returnType = temp_0120->append("[]")->toString();
		//				stack[0]: int=1
		//		iinc 3 -1
		dimensions += -1;
		//				stack[0]: int=1
	L0130: //
		//		iload 3
		//				stack[0]: int=1
		//				stack[1]: int=dimensions
		//		ifgt L0117
		if ((dimensions) > 0)
			goto L0117;
		//				stack[0]: int=1
		//		aload 4
		//				stack[0]: int=1
		//				stack[1]: String=returnType
		//		areturn
		return returnType;
		//				stack[0]: int=1
	}

	Pointer<String> Statics::removeJavaArray(Pointer<String> javaArray)
	{
		//		aload 0
		//				stack[0]: String=javaArray
		//		ldc "JavaArray<"
		//				stack[0]: String=javaArray
		//				stack[1]: String="JavaArray<"
		//		invokevirtual java.lang.String.startsWith
		//				stack[0]: bool=javaArray->startsWith("JavaArray<")
		//		ldc "JavaArray<> expected"
		//				stack[0]: bool=javaArray->startsWith("JavaArray<")
		//				stack[1]: String="JavaArray<> expected"
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		Statics::Assert(javaArray->startsWith("JavaArray<"), "JavaArray<> expected");
		//				stack: empty
		//		aload 0
		//				stack[0]: String=javaArray
		//		bipush 10
		//				stack[0]: String=javaArray
		//				stack[1]: int=10
		//		aload 0
		//				stack[0]: String=javaArray
		//				stack[1]: int=10
		//				stack[2]: String=javaArray
		//		invokevirtual java.lang.String.length
		//				stack[0]: String=javaArray
		//				stack[1]: int=10
		//				stack[2]: int=javaArray->length()
		//		iconst 1
		//				stack[0]: String=javaArray
		//				stack[1]: int=10
		//				stack[2]: int=javaArray->length()
		//				stack[3]: int=1
		//		isub
		//				stack[0]: String=javaArray
		//				stack[1]: int=10
		//				stack[2]: int=(javaArray->length()) - (1)
		//		invokevirtual java.lang.String.substring
		//				stack[0]: String=javaArray->substring(10, (javaArray->length()) - (1))
		//		areturn
		return javaArray->substring(10, (javaArray->length()) - (1));
		//				stack: empty
	}

	Pointer<String> Statics::removePointerWrapper(Pointer<String> wrappedObject)
	{
		//		aload 0
		//				stack[0]: String=wrappedObject
		//		ldc "Pointer<"
		//				stack[0]: String=wrappedObject
		//				stack[1]: String="Pointer<"
		//		invokevirtual java.lang.String.startsWith
		//				stack[0]: bool=wrappedObject->startsWith("Pointer<")
		//		ldc "Pointer<> expected"
		//				stack[0]: bool=wrappedObject->startsWith("Pointer<")
		//				stack[1]: String="Pointer<> expected"
		//		invokestatic org.borium.javarecompiler.Statics.Assert
		Statics::ClassInit();
		Statics::Assert(wrappedObject->startsWith("Pointer<"), "Pointer<> expected");
		//				stack: empty
		//		aload 0
		//				stack[0]: String=wrappedObject
		//		bipush 8
		//				stack[0]: String=wrappedObject
		//				stack[1]: int=8
		//		aload 0
		//				stack[0]: String=wrappedObject
		//				stack[1]: int=8
		//				stack[2]: String=wrappedObject
		//		invokevirtual java.lang.String.length
		//				stack[0]: String=wrappedObject
		//				stack[1]: int=8
		//				stack[2]: int=wrappedObject->length()
		//		iconst 1
		//				stack[0]: String=wrappedObject
		//				stack[1]: int=8
		//				stack[2]: int=wrappedObject->length()
		//				stack[3]: int=1
		//		isub
		//				stack[0]: String=wrappedObject
		//				stack[1]: int=8
		//				stack[2]: int=(wrappedObject->length()) - (1)
		//		invokevirtual java.lang.String.substring
		//				stack[0]: String=wrappedObject->substring(8, (wrappedObject->length()) - (1))
		//		areturn
		return wrappedObject->substring(8, (wrappedObject->length()) - (1));
		//				stack: empty
	}

	void Statics::parseClass(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data)
	{
		Pointer<RuntimeException> temp_0034;
		//		goto L000A
		goto L000A;
		//				stack: empty
	L0003: //
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=0
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=(data->get(0))+(1)
		//		iastore
		data->assign(0, (data->get(0))+(1));
		//				stack: empty
	L000A: //
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=descriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//		bipush 59
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//				stack[1]: int=59
		//		if_icmpeq L0022
		if ((descriptor->charAt(data->get(0))) == (59))
			goto L0022;
		//				stack: empty
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=descriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//		bipush 60
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//				stack[1]: int=60
		//		if_icmpne L0003
		if ((descriptor->charAt(data->get(0))) != (60))
			goto L0003;
		//				stack: empty
	L0022: //
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=descriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//		bipush 60
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//				stack[1]: int=60
		//		if_icmpne L0038
		if ((descriptor->charAt(data->get(0))) != (60))
			goto L0038;
		//				stack: empty
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException=new
		//		dup
		//				stack[0]: RuntimeException=new
		//				stack[1]: RuntimeException=new
		//		ldc "Templates not supported"
		//				stack[0]: RuntimeException=new
		//				stack[1]: RuntimeException=new
		//				stack[2]: String="Templates not supported"
		//		invokespecial java.lang.RuntimeException.<init>
		temp_0034 = new RuntimeException("Templates not supported");
		//				stack[0]: RuntimeException=temp_0034
		//		athrow
		throw temp_0034;
		//				stack: empty
	L0038: //
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=descriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//		bipush 59
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//				stack[1]: int=59
		//		if_icmpne L004B
		if ((descriptor->charAt(data->get(0))) != (59))
			goto L004B;
		//				stack: empty
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=0
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=(data->get(0))+(1)
		//		iastore
		data->assign(0, (data->get(0))+(1));
		//				stack: empty
	L004B: //
		//		return
		return;
		//				stack: empty
	}

	void Statics::parseSingleType(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data)
	{
		//		goto L000A
		goto L000A;
		//				stack: empty
	L0003: //
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=0
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=(data->get(0))+(1)
		//		iastore
		data->assign(0, (data->get(0))+(1));
		//				stack: empty
	L000A: //
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=descriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//		bipush 91
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//				stack[1]: int=91
		//		if_icmpeq L0003
		if ((descriptor->charAt(data->get(0))) == (91))
			goto L0003;
		//				stack: empty
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//				stack[2]: int=0
		//		iaload
		//				stack[0]: String=descriptor
		//				stack[1]: int=data->get(0)
		//		invokevirtual java.lang.String.charAt
		//				stack[0]: char=descriptor->charAt(data->get(0))
		//		tableswitch 25 cases
		switch (descriptor->charAt(data->get(0)))
		{
		case 66:
			goto L0090;
		case 67:
			goto L0090;
		case 68:
			goto L0090;
		case 69:
			goto L00BE;
		case 70:
			goto L0090;
		case 71:
			goto L00BE;
		case 72:
			goto L00BE;
		case 73:
			goto L0090;
		case 74:
			goto L0090;
		case 75:
			goto L00BE;
		case 76:
			goto L00A1;
		case 77:
			goto L00BE;
		case 78:
			goto L00BE;
		case 79:
			goto L00BE;
		case 80:
			goto L00BE;
		case 81:
			goto L00BE;
		case 82:
			goto L00BE;
		case 83:
			goto L0090;
		case 84:
			goto L00BE;
		case 85:
			goto L00BE;
		case 86:
			goto L00B7;
		case 87:
			goto L00BE;
		case 88:
			goto L00BE;
		case 89:
			goto L00BE;
		case 90:
			goto L0090;
		default:
			goto L00BE;
		}
		//				stack: empty
	L0090: //
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=0
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=(data->get(0))+(1)
		//		iastore
		data->assign(0, (data->get(0))+(1));
		//				stack: empty
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=1
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: int=data->get(1)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: int=data->get(1)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: int=(data->get(1))+(1)
		//		iastore
		data->assign(1, (data->get(1))+(1));
		//				stack: empty
		//		goto L00BE
		goto L00BE;
		//				stack: empty
	L00A1: //
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=0
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=(data->get(0))+(1)
		//		iastore
		data->assign(0, (data->get(0))+(1));
		//				stack: empty
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=1
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: int=data->get(1)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: int=data->get(1)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=1
		//				stack[2]: int=(data->get(1))+(1)
		//		iastore
		data->assign(1, (data->get(1))+(1));
		//				stack: empty
		//		aload 0
		//				stack[0]: String=descriptor
		//		aload 1
		//				stack[0]: String=descriptor
		//				stack[1]: JavaRawArray<int>=data
		//		invokestatic org.borium.javarecompiler.Statics.parseClass
		Statics::ClassInit();
		Statics::parseClass(descriptor, data);
		//				stack: empty
		//		goto L00BE
		goto L00BE;
		//				stack: empty
	L00B7: //
		//		aload 1
		//				stack[0]: JavaRawArray<int>=data
		//		iconst 0
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//		dup2
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: JavaRawArray<int>=data
		//				stack[3]: int=0
		//		iaload
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//		iconst 1
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=data->get(0)
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: JavaRawArray<int>=data
		//				stack[1]: int=0
		//				stack[2]: int=(data->get(0))+(1)
		//		iastore
		data->assign(0, (data->get(0))+(1));
		//				stack: empty
	L00BE: //
		//		return
		return;
		//				stack: empty
	}

}
