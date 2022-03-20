#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__constants__ConstantPool.h"

namespace org::borium::javarecompiler::classfile::constants
{

	ConstantPool::ConstantPool() :
			//			aload 0
			//				stack[0]: ConstantPool*=this
			//			invokespecial java.lang.Object.<init>
			Object() //
			//				stack: empty
			, constants(0) //
	{
		//		return
		return;
		//				stack: empty
	}

	void ConstantPool::dump(IndentedOutputStream *stream)
	{
		int i = 0;
		//		aload 1
		//				stack[0]: IndentedOutputStream*=stream
		//		ldc "Constants:"
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: String *="Constants:"
		//		invokevirtual org.borium.javarecompiler.classfile.IndentedOutputStream.println
		stream->println("Constants:");
		//				stack: empty
		//		aload 1
		//				stack[0]: IndentedOutputStream*=stream
		//		iconst 1
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: int=1
		//		invokevirtual org.borium.javarecompiler.classfile.IndentedOutputStream.indent
		stream->indent(1);
		//				stack: empty
		//		iconst 1
		//				stack[0]: int=1
		//		istore 2
		i = 1;
		//				stack: empty
		//		goto L0041
		goto L0041;
		//				stack: empty
		L0010: //
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 2
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//		aaload
		//				stack[0]: Constant*=this->constants->get(i)
		//		ifnull L003E
		if ((this->constants->get(i)) == nullptr)
			goto L003E;
		//				stack: empty
		//		aload 1
		//				stack[0]: IndentedOutputStream*=stream
		//		new java.lang.StringBuilder
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=new
		//		dup
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=new
		//				stack[2]: StringBuilder*=new
		//		iload 2
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: int=i
		//		invokestatic java.lang.String.valueOf
		String::ClassInit();
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: String*=String::valueOf(i)
		//		invokespecial java.lang.StringBuilder.<init>
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=new StringBuilder(String::valueOf(i))
		//		ldc ": "
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=new StringBuilder(String::valueOf(i))
		//				stack[2]: String *=": "
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: StringBuilder*=(new StringBuilder(String::valueOf(i)))->append(": ")
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: String*=(new StringBuilder(String::valueOf(i)))->append(": ")->toString()
		//		invokevirtual org.borium.javarecompiler.classfile.IndentedOutputStream.iprint
		stream->iprint((new StringBuilder(String::valueOf(i)))->append(": ")->toString());
		//				stack: empty
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 2
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//		aaload
		//				stack[0]: Constant*=this->constants->get(i)
		//		aload 1
		//				stack[0]: Constant*=this->constants->get(i)
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.constants.Constant.dump
		this->constants->get(i)->dump(stream);
		//				stack: empty
		//		aload 1
		//				stack[0]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.IndentedOutputStream.println
		stream->println();
		//				stack: empty
		L003E: //
		//		iinc 2 1
		i += 1;
		//				stack: empty
		L0041: //
		//		iload 2
		//				stack[0]: int=i
		//		aload 0
		//				stack[0]: int=i
		//				stack[1]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: int=i
		//				stack[1]: JavaArray<Constant*>*=this->constants
		//		arraylength
		//				stack[0]: int=i
		//				stack[1]: int=this->constants->length
		//		if_icmplt L0010
		if ((i) < (this->constants->length))
			goto L0010;
		//				stack: empty
		//		aload 1
		//				stack[0]: IndentedOutputStream*=stream
		//		iconst -1
		//				stack[0]: IndentedOutputStream*=stream
		//				stack[1]: int=-1
		//		invokevirtual org.borium.javarecompiler.classfile.IndentedOutputStream.indent
		stream->indent(-1);
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	Constant* ConstantPool::get(int index)
	{
		//		iload 1
		//				stack[0]: int=index
		//		iflt L000D
		if ((index) < 0)
			goto L000D;
		//				stack: empty
		//		iload 1
		//				stack[0]: int=index
		//		aload 0
		//				stack[0]: int=index
		//				stack[1]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: int=index
		//				stack[1]: JavaArray<Constant*>*=this->constants
		//		arraylength
		//				stack[0]: int=index
		//				stack[1]: int=this->constants->length
		//		if_icmplt L0034
		if ((index) < (this->constants->length))
			goto L0034;
		//				stack: empty
		L000D: //
		//		new java.lang.ClassFormatError
		//				stack[0]: ClassFormatError*=new
		//		dup
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//		new java.lang.StringBuilder
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//		dup
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//		ldc "Constant index "
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//				stack[4]: String *="Constant index "
		//		invokespecial java.lang.StringBuilder.<init>
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Constant index ")
		//		iload 1
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Constant index ")
		//				stack[3]: int=index
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)
		//		ldc " is out of range 0.."
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)
		//				stack[3]: String *=" is out of range 0.."
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")
		//		aload 0
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")
		//				stack[3]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")
		//				stack[3]: JavaArray<Constant*>*=this->constants
		//		arraylength
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")
		//				stack[3]: int=this->constants->length
		//		iconst 1
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")
		//				stack[3]: int=this->constants->length
		//				stack[4]: int=1
		//		isub
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")
		//				stack[3]: int=(this->constants->length) - (1)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")->append((this->constants->length) - (1))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: String*=(new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")->append((this->constants->length) - (1))->toString()
		//		invokespecial java.lang.ClassFormatError.<init>
		//				stack[0]: ClassFormatError*=new ClassFormatError((new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")->append((this->constants->length) - (1))->toString())
		//		athrow
		throw new ClassFormatError((new StringBuilder("Constant index "))->append(index)->append(" is out of range 0..")->append((this->constants->length) - (1))->toString());
		//				stack: empty
		L0034: //
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 1
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=index
		//		aaload
		//				stack[0]: Constant*=this->constants->get(index)
		//		areturn
		return this->constants->get(index);
		//				stack: empty
	}

	Constant* ConstantPool::get(int index, Class *clazz)
	{
		Constant *c = nullptr;
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		iload 1
		//				stack[0]: ConstantPool*=this
		//				stack[1]: int=index
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.get
		//				stack[0]: Constant*=this->get(index)
		//		astore 3
		c = this->get(index);
		//				stack: empty
		//		aload 2
		//				stack[0]: Class*=clazz
		//		aload 3
		//				stack[0]: Class*=clazz
		//				stack[1]: Constant*=c
		//		invokevirtual java.lang.Class.isInstance
		//				stack[0]: bool=clazz->isInstance(c)
		//		ifeq L0010
		if (!(clazz->isInstance(c)))
			goto L0010;
		//				stack: empty
		//		aload 3
		//				stack[0]: Constant*=c
		//		areturn
		return c;
		//				stack: empty
		L0010: //
		//		new java.lang.ClassFormatError
		//				stack[0]: ClassFormatError*=new
		//		dup
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//		new java.lang.StringBuilder
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//		dup
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//		ldc "Constant "
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//				stack[4]: String *="Constant "
		//		invokespecial java.lang.StringBuilder.<init>
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Constant ")
		//		iload 1
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Constant ")
		//				stack[3]: int=index
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant "))->append(index)
		//		ldc " is not "
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant "))->append(index)
		//				stack[3]: String *=" is not "
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant "))->append(index)->append(" is not ")
		//		aload 2
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant "))->append(index)->append(" is not ")
		//				stack[3]: Class*=clazz
		//		invokevirtual java.lang.Class.getSimpleName
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant "))->append(index)->append(" is not ")
		//				stack[3]: String*=clazz->getSimpleName()
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Constant "))->append(index)->append(" is not ")->append(clazz->getSimpleName())
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: String*=(new StringBuilder("Constant "))->append(index)->append(" is not ")->append(clazz->getSimpleName())->toString()
		//		invokespecial java.lang.ClassFormatError.<init>
		//				stack[0]: ClassFormatError*=new ClassFormatError((new StringBuilder("Constant "))->append(index)->append(" is not ")->append(clazz->getSimpleName())->toString())
		//		athrow
		throw new ClassFormatError((new StringBuilder("Constant "))->append(index)->append(" is not ")->append(clazz->getSimpleName())->toString());
		//				stack: empty
	}

	String* ConstantPool::getString(int index)
	{
		Constant *constant = nullptr;
		ConstantUtf8Info *utf8 = nullptr;
		Constant * instanceOfPatternExpressionValue = nullptr;
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		iload 1
		//				stack[0]: ConstantPool*=this
		//				stack[1]: int=index
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.get
		//				stack[0]: Constant*=this->get(index)
		//		astore 2
		constant = this->get(index);
		//				stack: empty
		//		aload 2
		//				stack[0]: Constant*=constant
		//		astore 4
		 instanceOfPatternExpressionValue = constant;
		//				stack: empty
		//		aload 4
		//				stack[0]: Constant*= instanceOfPatternExpressionValue
		//		instanceof org.borium.javarecompiler.classfile.constants.ConstantUtf8Info
		//				stack[0]: bool= instanceOfPatternExpressionValue->instanceOf(ConstantUtf8Info::getClass())
		//		ifeq L0025
		if (!( instanceOfPatternExpressionValue->instanceOf(ConstantUtf8Info::getClass())))
			goto L0025;
		//				stack: empty
		//		aload 4
		//				stack[0]: Constant*= instanceOfPatternExpressionValue
		//		checkcast org.borium.javarecompiler.classfile.constants.ConstantUtf8Info
		 instanceOfPatternExpressionValue->checkCast(ConstantUtf8Info::getClass());
		//				stack[0]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//		dup
		//				stack[0]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//				stack[1]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//		astore 3
		ConstantUtf8Info local_0017 =  instanceOfPatternExpressionValue;
		//				stack[0]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//		aload 4
		//				stack[0]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//				stack[1]: Constant*= instanceOfPatternExpressionValue
		//		checkcast org.borium.javarecompiler.classfile.constants.ConstantUtf8Info
		 instanceOfPatternExpressionValue->checkCast(ConstantUtf8Info::getClass());
		//				stack[0]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//				stack[1]: ConstantUtf8Info= instanceOfPatternExpressionValue
		//		if_acmpne L0025
		if (( instanceOfPatternExpressionValue) != ( instanceOfPatternExpressionValue))
			goto L0025;
		//				stack: empty
		//		aload 3
		//				stack[0]: ConstantUtf8Info*=utf8
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantUtf8Info.string
		//				stack[0]: String*=utf8->string()
		//		areturn
		return utf8->string();
		//				stack: empty
		L0025: //
		//		new java.lang.ClassFormatError
		//				stack[0]: ClassFormatError*=new
		//		dup
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//		new java.lang.StringBuilder
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//		dup
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//		ldc "Index "
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//				stack[4]: String *="Index "
		//		invokespecial java.lang.StringBuilder.<init>
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Index ")
		//		iload 1
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Index ")
		//				stack[3]: int=index
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)
		//		ldc " is not a string but "
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)
		//				stack[3]: String *=" is not a string but "
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)->append(" is not a string but ")
		//		aload 2
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)->append(" is not a string but ")
		//				stack[3]: Constant*=constant
		//		invokevirtual java.lang.Object.getClass
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)->append(" is not a string but ")
		//				stack[3]: Class*=constant->getClass()
		//		invokevirtual java.lang.Class.getSimpleName
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)->append(" is not a string but ")
		//				stack[3]: String*=constant->getClass()->getSimpleName()
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Index "))->append(index)->append(" is not a string but ")->append(constant->getClass()->getSimpleName())
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: ClassFormatError*=new
		//				stack[1]: ClassFormatError*=new
		//				stack[2]: String*=(new StringBuilder("Index "))->append(index)->append(" is not a string but ")->append(constant->getClass()->getSimpleName())->toString()
		//		invokespecial java.lang.ClassFormatError.<init>
		//				stack[0]: ClassFormatError*=new ClassFormatError((new StringBuilder("Index "))->append(index)->append(" is not a string but ")->append(constant->getClass()->getSimpleName())->toString())
		//		athrow
		throw new ClassFormatError((new StringBuilder("Index "))->append(index)->append(" is not a string but ")->append(constant->getClass()->getSimpleName())->toString());
		//				stack: empty
	}

	void ConstantPool::read(ByteInputStream *in)
	{
		int count = 0;
		int i = 0;
		int tag = 0;
		Constant *constant = nullptr;
		int i = 0;
		//		aload 1
		//				stack[0]: ByteInputStream*=in
		//		invokevirtual org.borium.javarecompiler.classfile.ByteInputStream.u2
		//				stack[0]: int=in->u2()
		//		istore 2
		count = in->u2();
		//				stack: empty
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		iload 2
		//				stack[0]: ConstantPool*=this
		//				stack[1]: int=count
		//		anewarray org.borium.javarecompiler.classfile.constants.Constant
		//				stack[0]: ConstantPool*=this
		//				stack[1]: JavaArray<Constant*>*=new JavaArray<Constant*>(count)
		//		putfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		this->constants = new JavaArray<Constant*>(count);
		//				stack: empty
		//		iconst 1
		//				stack[0]: int=1
		//		istore 3
		i = 1;
		//				stack: empty
		//		goto L0046
		goto L0046;
		//				stack: empty
		L0012: //
		//		aload 1
		//				stack[0]: ByteInputStream*=in
		//		invokevirtual org.borium.javarecompiler.classfile.ByteInputStream.u1
		//				stack[0]: int=in->u1()
		//		istore 4
		tag = in->u1();
		//				stack: empty
		//		iload 4
		//				stack[0]: int=tag
		//		invokestatic org.borium.javarecompiler.classfile.constants.Constant.create
		Constant::ClassInit();
		//				stack[0]: Constant*=Constant::create(tag)
		//		astore 5
		constant = Constant::create(tag);
		//				stack: empty
		//		aload 5
		//				stack[0]: Constant*=constant
		//		aload 1
		//				stack[0]: Constant*=constant
		//				stack[1]: ByteInputStream*=in
		//		invokevirtual org.borium.javarecompiler.classfile.constants.Constant.read
		constant->read(in);
		//				stack: empty
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 3
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//		aload 5
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//				stack[2]: Constant*=constant
		//		aastore
		this->constants->assign(i, constant);
		//				stack: empty
		//		aload 5
		//				stack[0]: Constant*=constant
		//		iconst 5
		//				stack[0]: Constant*=constant
		//				stack[1]: int=5
		//		invokevirtual org.borium.javarecompiler.classfile.constants.Constant.is
		//				stack[0]: bool=constant->is(5)
		//		ifne L0040
		if (constant->is(5))
			goto L0040;
		//				stack: empty
		//		aload 5
		//				stack[0]: Constant*=constant
		//		bipush 6
		//				stack[0]: Constant*=constant
		//				stack[1]: int=6
		//		invokevirtual org.borium.javarecompiler.classfile.constants.Constant.is
		//				stack[0]: bool=constant->is(6)
		//		ifeq L0043
		if (!(constant->is(6)))
			goto L0043;
		//				stack: empty
		L0040: //
		//		iinc 3 1
		i += 1;
		//				stack: empty
		L0043: //
		//		iinc 3 1
		i += 1;
		//				stack: empty
		L0046: //
		//		iload 3
		//				stack[0]: int=i
		//		iload 2
		//				stack[0]: int=i
		//				stack[1]: int=count
		//		if_icmplt L0012
		if ((i) < (count))
			goto L0012;
		//				stack: empty
		//		iconst 1
		//				stack[0]: int=1
		//		istore 3
		i = 1;
		//				stack: empty
		//		goto L0066
		goto L0066;
		//				stack: empty
		L0050: //
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 3
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//		aaload
		//				stack[0]: Constant*=this->constants->get(i)
		//		ifnull L0063
		if ((this->constants->get(i)) == nullptr)
			goto L0063;
		//				stack: empty
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 3
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//		aaload
		//				stack[0]: Constant*=this->constants->get(i)
		//		aload 0
		//				stack[0]: Constant*=this->constants->get(i)
		//				stack[1]: ConstantPool*=this
		//		invokevirtual org.borium.javarecompiler.classfile.constants.Constant.fixup
		this->constants->get(i)->fixup(this);
		//				stack: empty
		L0063: //
		//		iinc 3 1
		i += 1;
		//				stack: empty
		L0066: //
		//		iload 3
		//				stack[0]: int=i
		//		iload 2
		//				stack[0]: int=i
		//				stack[1]: int=count
		//		if_icmplt L0050
		if ((i) < (count))
			goto L0050;
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

	void ConstantPool::verify(int majorVersion, int minorVersion)
	{
		int i = 0;
		Constant *constant = nullptr;
		//		iconst 0
		//				stack[0]: int=0
		//		istore 3
		i = 0;
		//				stack: empty
		//		goto L001F
		goto L001F;
		//				stack: empty
		L0005: //
		//		aload 0
		//				stack[0]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//		iload 3
		//				stack[0]: JavaArray<Constant*>*=this->constants
		//				stack[1]: int=i
		//		aaload
		//				stack[0]: Constant*=this->constants->get(i)
		//		astore 4
		constant = this->constants->get(i);
		//				stack: empty
		//		aload 4
		//				stack[0]: Constant*=constant
		//		ifnull L001C
		if ((constant) == nullptr)
			goto L001C;
		//				stack: empty
		//		aload 4
		//				stack[0]: Constant*=constant
		//		iload 1
		//				stack[0]: Constant*=constant
		//				stack[1]: int=majorVersion
		//		iload 2
		//				stack[0]: Constant*=constant
		//				stack[1]: int=majorVersion
		//				stack[2]: int=minorVersion
		//		aload 0
		//				stack[0]: Constant*=constant
		//				stack[1]: int=majorVersion
		//				stack[2]: int=minorVersion
		//				stack[3]: ConstantPool*=this
		//		iload 3
		//				stack[0]: Constant*=constant
		//				stack[1]: int=majorVersion
		//				stack[2]: int=minorVersion
		//				stack[3]: ConstantPool*=this
		//				stack[4]: int=i
		//		invokevirtual org.borium.javarecompiler.classfile.constants.Constant.verify
		//				stack[0]: bool=constant->verify(majorVersion, minorVersion, this, i)
		//		pop
		constant->verify(majorVersion, minorVersion, this, i);
		//				stack: empty
		L001C: //
		//		iinc 3 1
		i += 1;
		//				stack: empty
		L001F: //
		//		iload 3
		//				stack[0]: int=i
		//		aload 0
		//				stack[0]: int=i
		//				stack[1]: ConstantPool*=this
		//		getfield constants [Lorg/borium/javarecompiler/classfile/constants/Constant;
		//				stack[0]: int=i
		//				stack[1]: JavaArray<Constant*>*=this->constants
		//		arraylength
		//				stack[0]: int=i
		//				stack[1]: int=this->constants->length
		//		if_icmplt L0005
		if ((i) < (this->constants->length))
			goto L0005;
		//				stack: empty
		//		return
		return;
		//				stack: empty
	}

}
