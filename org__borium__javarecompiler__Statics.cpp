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
		Object() //
	{
		return;
	}

	Pointer<String> Statics::addPointerIfNeeded(Pointer<String> type)
	{
		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_00CC;
		local_0002 = type;
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
	L0058: //
		if (local_0002->equals("double"))
			goto L00C4;
		goto L00C6;
	L0064: //
		if (local_0002->equals("int"))
			goto L00C4;
		goto L00C6;
	L0070: //
		if (local_0002->equals("bool"))
			goto L00C4;
		goto L00C6;
	L007C: //
		if (local_0002->equals("byte"))
			goto L00C4;
		goto L00C6;
	L0088: //
		if (local_0002->equals("char"))
			goto L00C4;
		goto L00C6;
	L0094: //
		if (local_0002->equals("long"))
			goto L00C4;
		goto L00C6;
	L00A0: //
		if (local_0002->equals("void"))
			goto L00C4;
		goto L00C6;
	L00AC: //
		if (local_0002->equals("float"))
			goto L00C4;
		goto L00C6;
	L00B8: //
		if (local_0002->equals("short"))
			goto L00C4;
		goto L00C6;
	L00C4: //
		return type;
	L00C6: //
		temp_00CC = new StringBuilder("Pointer<");
		return temp_00CC->append(type)->append(">")->toString();
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
		signature = methodType;
		Statics::ClassInit();
		Statics::Assert(signature->startsWith("("), "Method type: Method() expected");
		result = "(";
		signature = signature->substring(1);
		goto L00B2;
	L0019: //
		pos = signature->indexOf(32);
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert((((pos) > 0) ? (1) : (0)), "Method type: Space between type and name not found");
		type = signature->substring(0, pos);
		String::ClassInit();
		temp_003E = new StringBuilder(String::valueOf(result));
		Statics::ClassInit();
		result = temp_003E->append(Statics::addPointerIfNeeded(type))->append(" ")->toString();
		signature = signature->substring((pos)+(1));
		goto L007B;
	L005D: //
		String::ClassInit();
		temp_0065 = new StringBuilder(String::valueOf(result));
		result = temp_0065->append(signature->substring(0, 1))->toString();
		signature = signature->substring(1);
	L007B: //
		if ((signature->charAt(0)) == (44))
			goto L008F;
		if ((signature->charAt(0)) != (41))
			goto L005D;
	L008F: //
		if (!(signature->startsWith(", ")))
			goto L00B2;
		String::ClassInit();
		temp_00A0 = new StringBuilder(String::valueOf(result));
		result = temp_00A0->append(", ")->toString();
		signature = signature->substring(2);
	L00B2: //
		if (!(signature->startsWith(")")))
			goto L0019;
		String::ClassInit();
		temp_00C3 = new StringBuilder(String::valueOf(result));
		result = temp_00C3->append(41)->toString();
		signature = signature->substring(1);
		if ((signature->length()) <= 0)
			goto L00F2;
		String::ClassInit();
		temp_00E4 = new StringBuilder(String::valueOf(result));
		Statics::ClassInit();
		result = temp_00E4->append(Statics::addPointerIfNeeded(signature))->toString();
	L00F2: //
		return result;
	}

	void Statics::Assert(bool condition, Pointer<String> errorMessage)
	{
		Pointer<RuntimeException> temp_0009;
		if (condition)
			goto L000D;
		temp_0009 = new RuntimeException(errorMessage);
		throw temp_0009;
	L000D: //
		return;
	}

	void Statics::Check(Pointer<IndentedOutputStream> stream, bool condition, Pointer<String> errorMessage)
	{
		Pointer<StringBuilder> temp_000B;
		if (condition)
			goto L0018;
		temp_000B = new StringBuilder("// ");
		stream->iprintln(temp_000B->append(errorMessage)->toString());
	L0018: //
		return;
	}

	Pointer<String> Statics::commaSeparatedList(Pointer<JavaArray<String>> values)
	{
		Pointer<String> result;
		Pointer<String> separator;
		Pointer<String> param;
		Pointer<JavaArray<String>> local_0008;
		Pointer<StringBuilder> temp_0021;
		result = "";
		separator = "";
		local_0008 = (JavaArray<String>*)(values.getValue());
		int local_000B = values->length;
		int local_000E = 0;
		goto L0036;
	L0013: //
		param = local_0008->get(local_000E);
		String::ClassInit();
		temp_0021 = new StringBuilder(String::valueOf(result));
		result = temp_0021->append(separator)->append(param)->toString();
		separator = ", ";
		local_000E += 1;
	L0036: //
		if ((local_000E) < (local_000B))
			goto L0013;
		return result;
	}

	Pointer<String> Statics::dotToNamespace(Pointer<String> dots)
	{
		String::ClassInit();
		// Parameter type mismatch
		// Parameter type mismatch
		return String::join("::", dots->split("[.]"));
	}

	int Statics::getParameterCount(Pointer<String> javaDescriptor)
	{
		Pointer<JavaRawArray<int>> data;
		Pointer<RuntimeException> temp_000F;
		Pointer<JavaRawArray<int>> temp_0014;
		if (javaDescriptor->startsWith("("))
			goto L0013;
		temp_000F = new RuntimeException("Get parameter count for non-method");
		throw temp_000F;
	L0013: //
		temp_0014 = new JavaRawArray<int>(2);
		temp_0014->assign(0, 1);
		data = (JavaRawArray<int>*)(temp_0014.getValue());
		goto L0023;
	L001E: //
		Statics::ClassInit();
		Statics::parseSingleType(javaDescriptor, data);
	L0023: //
		if ((javaDescriptor->charAt(data->get(0))) != (41))
			goto L001E;
		return data->get(1);
	}

	Pointer<String> Statics::hexString(int value, int length)
	{
		Pointer<String> result;
		Pointer<StringBuilder> temp_0006;
		temp_0006 = new StringBuilder("00000000");
		Integer::ClassInit();
		result = temp_0006->append(Integer::toHexString(value))->toString();
		result = result->substring((result->length()) - (length));
		return result->toUpperCase();
	}

	bool Statics::isTemplate(Pointer<String> type)
	{
		int index = 0;
		index = type->indexOf(60);
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert((((index) != 0) ? (1) : (0)), "Template: Starts with '<'");
		if ((index) <= 0)
			goto L001B;
		return 1;
	L001B: //
		return 0;
	}

	Pointer<String> Statics::javaToCppClass(Pointer<String> javaClassName)
	{
		Pointer<JavaArray<String>> split;
		split = (JavaArray<String>*)(javaClassName->split("[.]").getValue());
		String::ClassInit();
		// Parameter type mismatch
		return String::join("::", split);
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
		pos = javaMethodSignature->indexOf(41);
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert((((pos) >= (1)) ? (1) : (0)), "Method with no return type");
		type = javaMethodSignature->substring((pos)+(1));
		dimensions = 0;
		goto L002C;
	L0023: //
		dimensions += 1;
		type = type->substring(1);
	L002C: //
		if ((type->charAt(0)) == (91))
			goto L0023;
		returnType = "";
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
	L00B0: //
		returnType = "byte";
		goto L0130;
	L00B7: //
		returnType = "char";
		goto L0130;
	L00BE: //
		returnType = "double";
		goto L0130;
	L00C5: //
		returnType = "float";
		goto L0130;
	L00CC: //
		returnType = "int";
		goto L0130;
	L00D3: //
		returnType = "long";
		goto L0130;
	L00DA: //
		returnType = "short";
		goto L0130;
	L00E1: //
		returnType = "bool";
		goto L0130;
	L00E8: //
		// Parameter type mismatch
		// Parameter type mismatch
		temp_00EE = new JavaTypeConverter(type, 0);
		returnType = temp_00EE->getCppType();
		goto L0130;
	L00F9: //
		returnType = "void";
		goto L0130;
	L0100: //
		temp_0107 = new StringBuilder("Unhandled type ");
		Statics::ClassInit();
		// Parameter type mismatch
		Statics::Assert(0, temp_0107->append(type)->toString());
		goto L0130;
	L0117: //
		String::ClassInit();
		temp_0120 = new StringBuilder(String::valueOf(returnType));
		returnType = temp_0120->append("[]")->toString();
		dimensions += -1;
	L0130: //
		if ((dimensions) > 0)
			goto L0117;
		return returnType;
	}

	Pointer<String> Statics::removeJavaArray(Pointer<String> javaArray)
	{
		Statics::ClassInit();
		Statics::Assert(javaArray->startsWith("JavaArray<"), "JavaArray<> expected");
		return javaArray->substring(10, (javaArray->length()) - (1));
	}

	Pointer<String> Statics::removePointerWrapper(Pointer<String> wrappedObject)
	{
		Statics::ClassInit();
		Statics::Assert(wrappedObject->startsWith("Pointer<"), "Pointer<> expected");
		return wrappedObject->substring(8, (wrappedObject->length()) - (1));
	}

	void Statics::parseClass(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data)
	{
		Pointer<RuntimeException> temp_0034;
		goto L000A;
	L0003: //
		data->assign(0, (data->get(0))+(1));
	L000A: //
		if ((descriptor->charAt(data->get(0))) == (59))
			goto L0022;
		if ((descriptor->charAt(data->get(0))) != (60))
			goto L0003;
	L0022: //
		if ((descriptor->charAt(data->get(0))) != (60))
			goto L0038;
		temp_0034 = new RuntimeException("Templates not supported");
		throw temp_0034;
	L0038: //
		if ((descriptor->charAt(data->get(0))) != (59))
			goto L004B;
		data->assign(0, (data->get(0))+(1));
	L004B: //
		return;
	}

	void Statics::parseSingleType(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data)
	{
		goto L000A;
	L0003: //
		data->assign(0, (data->get(0))+(1));
	L000A: //
		if ((descriptor->charAt(data->get(0))) == (91))
			goto L0003;
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
	L0090: //
		data->assign(0, (data->get(0))+(1));
		data->assign(1, (data->get(1))+(1));
		goto L00BE;
	L00A1: //
		data->assign(0, (data->get(0))+(1));
		data->assign(1, (data->get(1))+(1));
		Statics::ClassInit();
		Statics::parseClass(descriptor, data);
		goto L00BE;
	L00B7: //
		data->assign(0, (data->get(0))+(1));
	L00BE: //
		return;
	}

}
