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

	Pointer<ReferencedClasses> ClassFile::getReferencedClasses()
	{
		Pointer<ArrayList<String>> referencedClasses;
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
		thisClassInfo = this->cp->get(this->thisClass, ConstantClassInfo::getClass()).getValue();
		thisClassInfo->dump(stream);
		stream->println();
		stream->print((new StringBuilder("Super Class: "))->append(this->superClass)->append(" ")->toString());
		if ((this->superClass) != 0)
			goto L00F9;
		stream->print("<None>");
		goto L0112;
		L00F9: //
		superClassInfo = this->cp->get(this->superClass, ConstantClassInfo::getClass()).getValue();
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
		classInfo = this->cp->get(this->interfaces.get(i), ConstantClassInfo::getClass()).getValue();
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
		attribute = ClassAttribute::readAttribute(this->in, this->cp);
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
		ci = this->cp->get(this->superClass, ConstantClassInfo::getClass()).getValue();
		this->superClassName = this->cp->getString(ci->nameIndex)->replace(47, 46);
		return;
	}

	void ClassFile::readConstants()
	{
		this->cp->read(this->in);
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
