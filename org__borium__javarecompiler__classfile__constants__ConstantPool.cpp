#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

#include "java__lang__Class.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__util__Iterator.h"
#include "org__borium__javarecompiler__classfile__ByteInputStream.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__classfile__constants__Constant.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantClassInfo.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantUtf8Info.h"

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::classfile::constants;

namespace org::borium::javarecompiler::classfile::constants
{

	ConstantPool::ConstantPool() :
		Object() //
	{
		return;
	}

	void ConstantPool::addReferencedClasses(Pointer<ReferencedClasses> referencedClasses)
	{
		Pointer<Constant> c_0014;
		Pointer<ConstantClassInfo> ci_002F;
		Pointer<Constant>  instanceOfPatternExpressionValue_0017;
		Pointer<String> className_0036;
		Pointer<JavaArray<Constant>> local_0005;
		Pointer<ConstantClassInfo> temp_0021;
		Pointer<ConstantClassInfo> local_0025;
		Pointer<ConstantClassInfo> temp_0029;
		Pointer<StringBuilder> temp_0065;
		local_0005 = (JavaArray<Constant>*)(this->constants.getValue());
		int local_0008 = this->constants->length;
		int local_000B = 0;
		goto L007B;
	L000F: //
		c_0014 = local_0005->get(local_000B);
		 instanceOfPatternExpressionValue_0017 = c_0014;
		if (!( instanceOfPatternExpressionValue_0017->instanceOf(ConstantClassInfo::getClass())))
			goto L0078;
		temp_0021 = (ConstantClassInfo*)(( instanceOfPatternExpressionValue_0017).getValue());
		temp_0021->checkCast(ConstantClassInfo::getClass());
		local_0025 = temp_0021;
		temp_0029 = (ConstantClassInfo*)(( instanceOfPatternExpressionValue_0017).getValue());
		temp_0029->checkCast(ConstantClassInfo::getClass());
		if ((temp_0021) != (temp_0029))
			goto L0078;
		className_0036 = ci_002F->getName();
		if (!(className_0036->startsWith("[")))
			goto L005E;
		goto L004B;
	L0043: //
		className_0036 = className_0036->substring(1);
	L004B: //
		if (className_0036->startsWith("["))
			goto L0043;
		referencedClasses->add(className_0036);
		goto L0078;
	L005E: //
		temp_0065 = new StringBuilder("L");
		referencedClasses->add(temp_0065->append(className_0036)->append(";")->toString());
	L0078: //
		local_000B += 1;
	L007B: //
		if ((local_000B) < (local_0008))
			goto L000F;
		return;
	}

	void ConstantPool::dump(Pointer<IndentedOutputStream> stream)
	{
		int i_000D = 0;
		Pointer<StringBuilder> temp_0022;
		stream->println("Constants:");
		stream->indent(1);
		i_000D = 1;
		goto L0041;
	L0010: //
		if ((this->constants->get(i_000D)) == nullptr)
			goto L003E;
		String::ClassInit();
		temp_0022 = new StringBuilder(String::valueOf(i_000D));
		stream->iprint(temp_0022->append(": ")->toString());
		this->constants->get(i_000D)->dump(stream);
		stream->println();
	L003E: //
		i_000D += 1;
	L0041: //
		if ((i_000D) < (this->constants->length))
			goto L0010;
		stream->indent(-1);
		return;
	}

	Pointer<Constant> ConstantPool::get(int index)
	{
		Pointer<StringBuilder> temp_0017;
		Pointer<ClassFormatError> temp_0030;
		if ((index) < 0)
			goto L000D;
		if ((index) < (this->constants->length))
			goto L0034;
	L000D: //
		temp_0017 = new StringBuilder("Constant index ");
		temp_0030 = new ClassFormatError(temp_0017->append(index)->append(" is out of range 0..")->append((this->constants->length) - (1))->toString());
		throw temp_0030;
	L0034: //
		return this->constants->get(index);
	}

	Pointer<String> ConstantPool::getString(int index)
	{
		Pointer<Constant> constant_0006;
		Pointer<ConstantUtf8Info> utf8_0020;
		Pointer<Constant>  instanceOfPatternExpressionValue_0009;
		Pointer<ConstantUtf8Info> temp_0013;
		Pointer<ConstantUtf8Info> local_0017;
		Pointer<ConstantUtf8Info> temp_001A;
		Pointer<StringBuilder> temp_002F;
		Pointer<ClassFormatError> temp_0048;
		constant_0006 = this->get(index);
		 instanceOfPatternExpressionValue_0009 = constant_0006;
		if (!( instanceOfPatternExpressionValue_0009->instanceOf(ConstantUtf8Info::getClass())))
			goto L0025;
		temp_0013 = (ConstantUtf8Info*)(( instanceOfPatternExpressionValue_0009).getValue());
		temp_0013->checkCast(ConstantUtf8Info::getClass());
		local_0017 = temp_0013;
		temp_001A = (ConstantUtf8Info*)(( instanceOfPatternExpressionValue_0009).getValue());
		temp_001A->checkCast(ConstantUtf8Info::getClass());
		if ((temp_0013) != (temp_001A))
			goto L0025;
		return utf8_0020->string();
	L0025: //
		temp_002F = new StringBuilder("Index ");
		temp_0048 = new ClassFormatError(temp_002F->append(index)->append(" is not a string but ")->append(constant_0006->getClass()->getSimpleName())->toString());
		throw temp_0048;
	}

	void ConstantPool::read(Pointer<ByteInputStream> in)
	{
		int count_0005 = 0;
		int i_000F = 0;
		int tag_0018 = 0;
		Pointer<Constant> constant_001F;
		int i_004D = 0;
		Pointer<JavaArray<Constant>> temp_0007;
		count_0005 = in->u2();
		temp_0007 = new JavaArray<Constant>(count_0005);
		this->constants = (JavaArray<Constant>*)(temp_0007.getValue());
		i_000F = 1;
		goto L0046;
	L0012: //
		tag_0018 = in->u1();
		Constant::ClassInit();
		constant_001F = Constant::create(tag_0018);
		constant_001F->read(in);
		this->constants->assign(i_000F, constant_001F);
		if (constant_001F->is(5))
			goto L0040;
		if (!(constant_001F->is(6)))
			goto L0043;
	L0040: //
		i_000F += 1;
	L0043: //
		i_000F += 1;
	L0046: //
		if ((i_000F) < (count_0005))
			goto L0012;
		i_004D = 1;
		goto L0066;
	L0050: //
		if ((this->constants->get(i_004D)) == nullptr)
			goto L0063;
		this->constants->get(i_004D)->fixup(this);
	L0063: //
		i_004D += 1;
	L0066: //
		if ((i_004D) < (count_0005))
			goto L0050;
		return;
	}

	void ConstantPool::verify(int majorVersion, int minorVersion)
	{
		int i_0002 = 0;
		Pointer<Constant> constant_000D;
		i_0002 = 0;
		goto L001F;
	L0005: //
		constant_000D = this->constants->get(i_0002);
		if ((constant_000D) == nullptr)
			goto L001C;
		constant_000D->verify(majorVersion, minorVersion, this, i_0002);
	L001C: //
		i_0002 += 1;
	L001F: //
		if ((i_0002) < (this->constants->length))
			goto L0005;
		return;
	}

}
