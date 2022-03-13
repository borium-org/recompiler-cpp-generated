#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

namespace org::borium::javarecompiler::classfile::constants
{

	ConstantPool::ConstantPool() :
		Object() //
	{
		return;
	}

	void ConstantPool::dump(Pointer<IndentedOutputStream> stream)
	{
		int i;
		stream->println("Constants:");
		stream->indent(1);
		i = 1;
		goto L0041;
	L0010: //
		if ((this->constants->get(i)) == nullptr)
			goto L003E;
		String::ClassInit();
		stream->iprint((new StringBuilder(String::valueOf(i)))->append(": ")->toString());
		this->constants->get(i)->dump(stream);
		stream->println();
	L003E: //
		i += 1;
	L0041: //
		if ((i) < (this->constants->length))
			goto L0010;
		stream->indent(-1);
		return;
	}

	Pointer<Constant> ConstantPool::get(int index)
	{
		if ((index) < 0)
			goto L000D;
		if ((index) < (this->constants->length))
			goto L0034;
	L000D: //
		throw new ClassFormatError((new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")->append((this->constants->length) - (1))->toString());
	L0034: //
		return this->constants->get(index);
	}

	Pointer<Constant> ConstantPool::get(int index, Pointer<Class> clazz)
	{
		Pointer<Constant> c;
		c = this->get(index);
		if (!(clazz->isInstance(c.getValue())))
			goto L0010;
		return c;
	L0010: //
		throw new ClassFormatError((new StringBuilder("Constant "))->append(index)->append(" is not ")->append(clazz->getSimpleName())->toString());
	}

	Pointer<ArrayList<String>> ConstantPool::getReferencedClasses()
	{
		Pointer<ArrayList<String>> referencedClasses;
		Pointer<Constant> c;
		Pointer<ConstantClassInfo> ci;
		Pointer<Constant> instanceOfPatternExpressionValue;
		referencedClasses = new ArrayList<String>();
		Pointer<JavaArray<Constant>> local_000D = this->constants;
		int local_0010 = this->constants->length;
		int local_0013 = 0;
		goto L004F;
	L0017: //
		c = local_000D->get(local_0013);
		instanceOfPatternExpressionValue = c;
		if (!(instanceOfPatternExpressionValue->instanceOf(ConstantClassInfo::getClass())))
			goto L004C;
		instanceOfPatternExpressionValue->checkCast(ConstantClassInfo::getClass());
		Pointer<ConstantClassInfo> local_002D = instanceOfPatternExpressionValue.getValue();
		instanceOfPatternExpressionValue->checkCast(ConstantClassInfo::getClass());
		if ((instanceOfPatternExpressionValue) != (instanceOfPatternExpressionValue))
			goto L004C;
		referencedClasses->add(this->getString(ci->nameIndex)->replace(47, 46));
	L004C: //
		local_0013 += 1;
	L004F: //
		if ((local_0013) < (local_0010))
			goto L0017;
		return referencedClasses;
	}

	Pointer<String> ConstantPool::getString(int index)
	{
		Pointer<Constant> constant;
		Pointer<ConstantUtf8Info> utf8;
		Pointer<Constant> instanceOfPatternExpressionValue;
		constant = this->get(index);
		instanceOfPatternExpressionValue = constant;
		if (!(instanceOfPatternExpressionValue->instanceOf(ConstantUtf8Info::getClass())))
			goto L0025;
		instanceOfPatternExpressionValue->checkCast(ConstantUtf8Info::getClass());
		Pointer<ConstantUtf8Info> local_0017 = instanceOfPatternExpressionValue;
		instanceOfPatternExpressionValue->checkCast(ConstantUtf8Info::getClass());
		if ((instanceOfPatternExpressionValue) != (instanceOfPatternExpressionValue))
			goto L0025;
		return utf8->string();
	L0025: //
		throw new ClassFormatError((new StringBuilder("Index "))->append(index)->append(" is not a string but ")->append(constant->getClass()->getSimpleName())->toString());
	}

	void ConstantPool::read(Pointer<ByteInputStream> in)
	{
		int count;
		int i;
		int tag;
		Pointer<Constant> constant;
		int i;
		count = in->u2();
		this->constants = new JavaArray<Constant>(count);
		i = 1;
		goto L0046;
	L0012: //
		tag = in->u1();
		Constant::ClassInit();
		constant = Constant::create(tag);
		constant->read(in);
		this->constants->assign(i, constant);
		if (constant->is(5))
			goto L0040;
		if (!(constant->is(6)))
			goto L0043;
	L0040: //
		i += 1;
	L0043: //
		i += 1;
	L0046: //
		if ((i) < (count))
			goto L0012;
		i = 1;
		goto L0066;
	L0050: //
		if ((this->constants->get(i)) == nullptr)
			goto L0063;
		this->constants->get(i)->fixup(this);
	L0063: //
		i += 1;
	L0066: //
		if ((i) < (count))
			goto L0050;
		return;
	}

	void ConstantPool::verify(int majorVersion, int minorVersion)
	{
		int i;
		Pointer<Constant> constant;
		i = 0;
		goto L001F;
	L0005: //
		constant = this->constants->get(i);
		if ((constant) == nullptr)
			goto L001C;
		constant->verify(majorVersion, minorVersion, this, i);
	L001C: //
		i += 1;
	L001F: //
		if ((i) < (this->constants->length))
			goto L0005;
		return;
	}

}
