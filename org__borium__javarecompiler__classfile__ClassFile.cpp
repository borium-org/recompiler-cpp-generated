#include "stdafx.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"

namespace org::borium::javarecompiler::classfile
{

	ClassFile::ClassFile() :
			Object() //
	{
		this->cp = new ConstantPool();
		this->attributes = new HashMap<String, ClassAttribute>();
		this->attributeList = new ArrayList<ClassAttribute>();
		return;
	}

	int ClassFile::printAccessFlag(Pointer<IndentedOutputStream> stream, int flags, int bit, Pointer<String> string)
	{
		if (((flags) & (bit)) == 0)
			goto L000B;
		stream->print(string);
		L000B: //
		flags = (flags) & ((bit) ^ (-1));
		return flags;
	}

	void ClassFile::dump(Pointer<IndentedOutputStream> stream)
	{
		stream->println((new StringBuilder("Class: "))->append(this->className)->toString());
		stream->println((new StringBuilder("Major Version: "))->append(this->majorVersion)->toString());
		stream->println((new StringBuilder("Minor Version: "))->append(this->minorVersion)->toString());
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 1
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.dump
		this->cp->dump(stream);
		this->dumpClassInfo(stream);
		this->dumpInterfaces(stream);
		this->dumpFields(stream);
		this->dumpMethods(stream);
		this->dumpAttributes(stream);
		return;
	}

	Pointer<String> ClassFile::getClassName()
	{
		return this->className->replace(47, 46);
	}

	Pointer<String> ClassFile::getClassSimpleName()
	{
		return this->className->substring((this->className->lastIndexOf(46)) + (1));
	}

	Pointer<JavaArray<ClassField>> ClassFile::getFields()
	{
		return this->fields;
	}

	Pointer<JavaArray<ClassMethod>> ClassFile::getMethods()
	{
		return this->methods;
	}

	Pointer<String> ClassFile::getParentClassName()
	{
		return this->superClassName;
	}

	Pointer<List<String>> ClassFile::getReferencedClasses()
	{
		Pointer<ArrayList<String>> referencedClasses;
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.getReferencedClasses
		//				stack[0]: ArrayList*=this->cp->getReferencedClasses()
		//		astore 1
		referencedClasses = this->cp->getReferencedClasses();
		return referencedClasses.getValue();
	}

	void ClassFile::read(Pointer<String> fileName)
	{
		Pointer<DataInputStream> dataIn;
		Pointer<JavaArray<byte>> data;
		this->className = fileName->substring(4, (fileName->length()) - (6))->replace(47, 46);
		dataIn = new DataInputStream(new FileInputStream(fileName));
		data = new JavaArray<byte>(dataIn->available());
		dataIn->read(data);
		dataIn->close();
		this->in = new ByteInputStream(data);
		this->readID();
		this->readVersion();
		this->readConstants();
		this->readClassInfo();
		this->readInterfaces();
		this->readFields();
		this->readMethods();
		this->readAttributes();
		this->in->close();
		return;
	}

	void ClassFile::dumpAttributes(Pointer<IndentedOutputStream> stream)
	{
		int i = 0;
		Pointer<ClassAttribute> attribute;
		stream->println((new StringBuilder("Attributes: "))->append(this->attributeList->size())->toString());
		stream->indent(1);
		i = 0;
		goto L004F;
		L0024: //
		String::ClassInit();
		stream->iprint((new StringBuilder(String::valueOf(i)))->append(": ")->toString());
		attribute = this->attributeList->get(i);
		//				stack: empty
		//		aload 3
		//				stack[0]: ClassAttribute*=attribute
		//		aload 1
		//				stack[0]: ClassAttribute*=attribute
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.ClassAttribute.dump
		attribute->dump(stream);
		i += 1;
		L004F: //
		if ((i) < (this->attributeList->size()))
			goto L0024;
		stream->indent(-1);
		return;
	}

	void ClassFile::dumpClassInfo(Pointer<IndentedOutputStream> stream)
	{
		int flags = 0;
		Pointer<ConstantClassInfo> thisClassInfo;
		Pointer<ConstantClassInfo> superClassInfo;
		stream->print("Access Flags: ");
		stream->printHex(this->accessFlags, 4);
		flags = this->accessFlags;
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 32768, " Module");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 16384, " Enum");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 8192, " Annotation");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 4096, " Synthetic");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 1024, " Abstract");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 512, " Interface");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 32, " Super");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 16, " Final");
		ClassFile::ClassInit();
		flags = ClassFile::printAccessFlag(stream, flags, 1, " Public");
		if ((flags) == 0)
			goto L008D;
		stream->print(" Invalid ");
		stream->printHex(flags, 4);
		L008D: //
		stream->println();
		stream->print((new StringBuilder("This Class: "))->append(this->thisClass)->append(" ")->toString());
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ClassFile*=this
		//		getfield thisClass I
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->thisClass
		//		ldc_w org/borium/javarecompiler/classfile/constants/ConstantClassInfo.class
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->thisClass
		//				stack[2]: class=org/borium/javarecompiler/classfile/constants/ConstantClassInfo
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.get
		//				stack[0]: Constant*=this->cp->get(this->thisClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		checkcast org.borium.javarecompiler.classfile.constants.ConstantClassInfo
		// ASSERT_KINDOF(ConstantClassInfo*, this->cp->get(this->thisClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo));
		//				stack[0]: ConstantClassInfo*=this->cp->get(this->thisClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		astore 3
		thisClassInfo = this->cp->get(this->thisClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo);
		//				stack: empty
		//		aload 3
		//				stack[0]: ConstantClassInfo*=thisClassInfo
		//		aload 1
		//				stack[0]: ConstantClassInfo*=thisClassInfo
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantClassInfo.dump
		thisClassInfo->dump(stream);
		stream->println();
		stream->print((new StringBuilder("Super Class: "))->append(this->superClass)->append(" ")->toString());
		if ((this->superClass) != 0)
			goto L00F9;
		stream->print("<None>");
		goto L0112;
		L00F9: //
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ClassFile*=this
		//		getfield superClass I
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->superClass
		//		ldc_w org/borium/javarecompiler/classfile/constants/ConstantClassInfo.class
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->superClass
		//				stack[2]: class=org/borium/javarecompiler/classfile/constants/ConstantClassInfo
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.get
		//				stack[0]: Constant*=this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		checkcast org.borium.javarecompiler.classfile.constants.ConstantClassInfo
		// ASSERT_KINDOF(ConstantClassInfo*, this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo));
		//				stack[0]: ConstantClassInfo*=this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		astore 4
		superClassInfo = this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo);
		//				stack: empty
		//		aload 4
		//				stack[0]: ConstantClassInfo*=superClassInfo
		//		aload 1
		//				stack[0]: ConstantClassInfo*=superClassInfo
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantClassInfo.dump
		superClassInfo->dump(stream);
		L0112: //
		stream->println();
		return;
	}

	void ClassFile::dumpFields(Pointer<IndentedOutputStream> stream)
	{
		int i = 0;
		Pointer<ClassField> field;
		stream->println((new StringBuilder("Fields: "))->append(this->fields->length)->toString());
		stream->indent(1);
		i = 0;
		goto L0049;
		L0023: //
		String::ClassInit();
		stream->iprint((new StringBuilder(String::valueOf(i)))->append(": ")->toString());
		field = this->fields->get(i);
		//				stack: empty
		//		aload 3
		//				stack[0]: ClassField*=field
		//		aload 1
		//				stack[0]: ClassField*=field
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.ClassField.dump
		field->dump(stream);
		i += 1;
		L0049: //
		if ((i) < (this->fields->length))
			goto L0023;
		stream->indent(-1);
		return;
	}

	void ClassFile::dumpInterfaces(Pointer<IndentedOutputStream> stream)
	{
		int i = 0;
		Pointer<ConstantClassInfo> classInfo;
		stream->println((new StringBuilder("Interfaces: "))->append(this->interfaces->length)->toString());
		stream->indent(1);
		i = 0;
		goto L005A;
		L0023: //
		String::ClassInit();
		stream->iprint((new StringBuilder(String::valueOf(i)))->append(": ")->toString());
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ClassFile*=this
		//		getfield interfaces [I
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: JavaArray<int>*=this->interfaces
		//		iload 2
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: JavaArray<int>*=this->interfaces
		//				stack[2]: int=i
		//		iaload
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->interfaces.get(i)
		//		ldc_w org/borium/javarecompiler/classfile/constants/ConstantClassInfo.class
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->interfaces.get(i)
		//				stack[2]: class=org/borium/javarecompiler/classfile/constants/ConstantClassInfo
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.get
		//				stack[0]: Constant*=this->cp->get(this->interfaces.get(i), org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		checkcast org.borium.javarecompiler.classfile.constants.ConstantClassInfo
		// ASSERT_KINDOF(ConstantClassInfo*, this->cp->get(this->interfaces.get(i), org/borium/javarecompiler/classfile/constants/ConstantClassInfo));
		//				stack[0]: ConstantClassInfo*=this->cp->get(this->interfaces.get(i), org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		astore 3
		classInfo = this->cp->get(this->interfaces.get(i), org/borium/javarecompiler/classfile/constants/ConstantClassInfo);
		//				stack: empty
		//		aload 3
		//				stack[0]: ConstantClassInfo*=classInfo
		//		aload 1
		//				stack[0]: ConstantClassInfo*=classInfo
		//				stack[1]: IndentedOutputStream*=stream
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantClassInfo.dump
		classInfo->dump(stream);
		stream->println();
		i += 1;
		L005A: //
		if ((i) < (this->interfaces->length))
			goto L0023;
		stream->indent(-1);
		return;
	}

	void ClassFile::dumpMethods(Pointer<IndentedOutputStream> stream)
	{
		int i = 0;
		Pointer<ClassMethod> method;
		stream->println((new StringBuilder("Methods: "))->append(this->methods->length)->toString());
		stream->indent(1);
		i = 0;
		goto L004D;
		L0023: //
		String::ClassInit();
		stream->iprint((new StringBuilder(String::valueOf(i)))->append(": ")->toString());
		method = this->methods->get(i);
		//				stack: empty
		//		aload 3
		//				stack[0]: ClassMethod*=method
		//		aload 1
		//				stack[0]: ClassMethod*=method
		//				stack[1]: IndentedOutputStream*=stream
		//		aload 0
		//				stack[0]: ClassMethod*=method
		//				stack[1]: IndentedOutputStream*=stream
		//				stack[2]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ClassMethod*=method
		//				stack[1]: IndentedOutputStream*=stream
		//				stack[2]: ConstantPool*=this->cp
		//		invokevirtual org.borium.javarecompiler.classfile.ClassMethod.dump
		method->dump(stream, this->cp);
		i += 1;
		L004D: //
		if ((i) < (this->methods->length))
			goto L0023;
		stream->indent(-1);
		return;
	}

	void ClassFile::readAttributes()
	{
		int attributeCount = 0;
		int i = 0;
		Pointer<ClassAttribute> attribute;
		attributeCount = this->in->u2();
		i = 0;
		goto L0032;
		L000D: //
		ClassAttribute::ClassInit();
		//				stack[0]: ClassAttribute*=ClassAttribute::readAttribute(this->in, this->cp)
		//		astore 3
		attribute = ClassAttribute::readAttribute(this->in, this->cp);
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield attributes Ljava/util/HashMap;
		//				stack[0]: HashMap*=this->attributes
		//		aload 3
		//				stack[0]: HashMap*=this->attributes
		//				stack[1]: ClassAttribute*=attribute
		//		invokevirtual org.borium.javarecompiler.classfile.ClassAttribute.getName
		//				stack[0]: HashMap*=this->attributes
		//				stack[1]: String*=attribute->getName()
		//		aload 3
		//				stack[0]: HashMap*=this->attributes
		//				stack[1]: String*=attribute->getName()
		//				stack[2]: ClassAttribute*=attribute
		//		invokevirtual java.util.HashMap.put
		//				stack[0]: Object*=this->attributes->put(attribute->getName(), attribute)
		//		pop
		this->attributes->put(attribute->getName(), attribute);
		this->attributeList->add(attribute);
		i += 1;
		L0032: //
		if ((i) < (attributeCount))
			goto L000D;
		return;
	}

	void ClassFile::readClassInfo()
	{
		Pointer<ConstantClassInfo> ci;
		this->accessFlags = this->in->u2();
		this->thisClass = this->in->u2();
		this->superClass = this->in->u2();
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ClassFile*=this
		//		getfield superClass I
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->superClass
		//		ldc_w org/borium/javarecompiler/classfile/constants/ConstantClassInfo.class
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->superClass
		//				stack[2]: class=org/borium/javarecompiler/classfile/constants/ConstantClassInfo
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.get
		//				stack[0]: Constant*=this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		checkcast org.borium.javarecompiler.classfile.constants.ConstantClassInfo
		// ASSERT_KINDOF(ConstantClassInfo*, this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo));
		//				stack[0]: ConstantClassInfo*=this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo)
		//		astore 1
		ci = this->cp->get(this->superClass, org/borium/javarecompiler/classfile/constants/ConstantClassInfo);
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		aload 0
		//				stack[0]: ClassFile*=this
		//				stack[1]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ClassFile*=this
		//				stack[1]: ConstantPool*=this->cp
		//		aload 1
		//				stack[0]: ClassFile*=this
		//				stack[1]: ConstantPool*=this->cp
		//				stack[2]: ConstantClassInfo*=ci
		//		getfield nameIndex I
		//				stack[0]: ClassFile*=this
		//				stack[1]: ConstantPool*=this->cp
		//				stack[2]: int=ci->nameIndex
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.getString
		//				stack[0]: ClassFile*=this
		//				stack[1]: String*=this->cp->getString(ci->nameIndex)
		//		bipush 47
		//				stack[0]: ClassFile*=this
		//				stack[1]: String*=this->cp->getString(ci->nameIndex)
		//				stack[2]: int=47
		//		bipush 46
		//				stack[0]: ClassFile*=this
		//				stack[1]: String*=this->cp->getString(ci->nameIndex)
		//				stack[2]: int=47
		//				stack[3]: int=46
		//		invokevirtual java.lang.String.replace
		//				stack[0]: ClassFile*=this
		//				stack[1]: String*=this->cp->getString(ci->nameIndex)->replace(47, 46)
		//		putfield superClassName Ljava/lang/String;
		this->superClassName = this->cp->getString(ci->nameIndex)->replace(47, 46);
		return;
	}

	void ClassFile::readConstants()
	{
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ClassFile*=this
		//		getfield in Lorg/borium/javarecompiler/classfile/ByteInputStream;
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ByteInputStream*=this->in
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.read
		this->cp->read(this->in);
		//				stack: empty
		//		aload 0
		//				stack[0]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ConstantPool*=this->cp
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: ClassFile*=this
		//		getfield majorVersion I
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->majorVersion
		//		aload 0
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->majorVersion
		//				stack[2]: ClassFile*=this
		//		getfield minorVersion I
		//				stack[0]: ConstantPool*=this->cp
		//				stack[1]: int=this->majorVersion
		//				stack[2]: int=this->minorVersion
		//		invokevirtual org.borium.javarecompiler.classfile.constants.ConstantPool.verify
		this->cp->verify(this->majorVersion, this->minorVersion);
		return;
	}

	void ClassFile::readFields()
	{
		int count = 0;
		int i = 0;
		Pointer<ClassField> field;
		count = this->in->u2();
		this->fields = new JavaArray<ClassField>(count);
		i = 0;
		goto L0033;
		L0015: //
		field = new ClassField();
		//				stack: empty
		//		aload 3
		//				stack[0]: ClassField*=field
		//		aload 0
		//				stack[0]: ClassField*=field
		//				stack[1]: ClassFile*=this
		//		getfield in Lorg/borium/javarecompiler/classfile/ByteInputStream;
		//				stack[0]: ClassField*=field
		//				stack[1]: ByteInputStream*=this->in
		//		aload 0
		//				stack[0]: ClassField*=field
		//				stack[1]: ByteInputStream*=this->in
		//				stack[2]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ClassField*=field
		//				stack[1]: ByteInputStream*=this->in
		//				stack[2]: ConstantPool*=this->cp
		//		invokevirtual org.borium.javarecompiler.classfile.ClassField.read
		field->read(this->in, this->cp);
		this->fields->assign(i, field);
		i += 1;
		L0033: //
		if ((i) < (count))
			goto L0015;
		return;
	}

	void ClassFile::readID()
	{
		int magic = 0;
		magic = this->in->u4();
		if ((magic) == (-889275714))
			goto L001A;
		throw new ClassFormatError("CAFEBABE not found");
		L001A: //
		return;
	}

	void ClassFile::readInterfaces()
	{
		int count = 0;
		int i = 0;
		count = this->in->u2();
		this->interfaces = new JavaArray<int>(count);
		i = 0;
		goto L0024;
		L0014: //
		this->interfaces->assign(i, this->in->u2());
		i += 1;
		L0024: //
		if ((i) < (count))
			goto L0014;
		return;
	}

	void ClassFile::readMethods()
	{
		int count = 0;
		int i = 0;
		Pointer<ClassMethod> method;
		count = this->in->u2();
		this->methods = new JavaArray<ClassMethod>(count);
		i = 0;
		goto L0033;
		L0015: //
		method = new ClassMethod();
		//				stack: empty
		//		aload 3
		//				stack[0]: ClassMethod*=method
		//		aload 0
		//				stack[0]: ClassMethod*=method
		//				stack[1]: ClassFile*=this
		//		getfield in Lorg/borium/javarecompiler/classfile/ByteInputStream;
		//				stack[0]: ClassMethod*=method
		//				stack[1]: ByteInputStream*=this->in
		//		aload 0
		//				stack[0]: ClassMethod*=method
		//				stack[1]: ByteInputStream*=this->in
		//				stack[2]: ClassFile*=this
		//		getfield cp Lorg/borium/javarecompiler/classfile/constants/ConstantPool;
		//				stack[0]: ClassMethod*=method
		//				stack[1]: ByteInputStream*=this->in
		//				stack[2]: ConstantPool*=this->cp
		//		invokevirtual org.borium.javarecompiler.classfile.ClassMethod.read
		method->read(this->in, this->cp);
		this->methods->assign(i, method);
		i += 1;
		L0033: //
		if ((i) < (count))
			goto L0015;
		return;
	}

	void ClassFile::readVersion()
	{
		this->minorVersion = this->in->u2();
		this->majorVersion = this->in->u2();
		if ((this->majorVersion) != (60))
			goto L0026;
		if ((this->minorVersion) == 0)
			goto L004F;
		L0026: //
		throw new ClassFormatError((new StringBuilder("Unsupported version "))->append(this->majorVersion)->append(":")->append(this->minorVersion)->toString());
		L004F: //
		return;
	}

}
