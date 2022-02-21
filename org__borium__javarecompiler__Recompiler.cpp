#include "stdafx.h"
#include "org__borium__javarecompiler__Recompiler.h"

namespace org::borium::javarecompiler
{

	//bool Recompiler::instructionComments;

	//bool Recompiler::stackComments;

	//void Recompiler::ClassInit()
	//{
	//	Object::ClassInit();
	//	Recompiler::instructionComments = false;
	//	Recompiler::stackComments = false;
	//	return;
	//}

	Recompiler::Recompiler() :
		Object() //
	{
		this->classPaths = new ArrayList<String>();
		//	this->processedClasses = new HashMap<String*, ClassFile*>();
		this->generatedClasses = new ArrayList<CppClass>();
		return;
	}

	void Recompiler::main(Pointer<JavaArray<String>> args)
	{
		Pointer<Recompiler> recompiler;
		int argc = 0;
		if ((args->length) != 0)
			goto L0041;
		{
			Pointer<JavaArray<String>> temp = new JavaArray<String>(10);
			temp->assignString(0, "-classpath");
			temp->assignString(1, "bin");
			temp->assignString(2, "-outputpath");
			temp->assignString(3, "../JrcPortCpp");
			temp->assignString(4, "-mainclass");
			temp->assignString(5, "org.borium.javarecompiler.Recompiler");
			temp->assignString(6, "-vs");
			temp->assignString(7, "2005");
			temp->assignString(8, "-comments");
			temp->assignString(9, "none");
			args = temp;
		}
	L0041: //
		recompiler = new Recompiler();
		argc = 0;
		//	goto L011D;
		//	{
		//		L004E: //
		//		String* local_0052 = args->get(argc);
		//		switch (args->get(argc)->hashCode())
		//		{
		//		case (int) 0xE0528093:
		//			goto L0088;
		//		case (int) 0xE22731D2:
		//			goto L0094;
		//		case (int) 0xEC1F6121:
		//			goto L00A0;
		//		case (int) 0xF0617410:
		//			goto L00AC;
		//		case (int) 0x0000B7AA:
		//			goto L00B8;
		//		default:
		//			goto L0100;
		//		}
		//		L0088: //
		//		if (local_0052->equals("-outputpath"))
		//			goto L00D0;
		//		goto L0100;
		//		L0094: //
		//		if (local_0052->equals("-mainclass"))
		//			goto L00DC;
		//		goto L0100;
		//		L00A0: //
		//		if (local_0052->equals("-comments"))
		//			goto L00F4;
		//		goto L0100;
		//		L00AC: //
		//		if (local_0052->equals("-classpath"))
		//			goto L00C4;
		//		goto L0100;
		//		L00B8: //
		//		if (local_0052->equals("-vs"))
		//			goto L00E8;
		//		goto L0100;
		//		L00C4: //
		//		recompiler->addClassPath(args->get((argc) + (1)));
		//		goto L011A;
		//		L00D0: //
		//		recompiler->setOutputPath(args->get((argc) + (1)));
		//		goto L011A;
		//		L00DC: //
		//		recompiler->setMainClass(args->get((argc) + (1)));
		//		goto L011A;
		//		L00E8: //
		//		recompiler->setVisualStudio(args->get((argc) + (1)));
		//		goto L011A;
		//		L00F4: //
		//		recompiler->setCommentLevel(args->get((argc) + (1)));
		//		goto L011A;
		//		L0100: //
		//		throw new RuntimeException((new StringBuilder("Unsupported argument "))->append(args->get(argc))->toString());
		//		L011A: //
		//		argc += 2;
		//	}
		//	L011D: //
		//	if ((argc) < (args->length))
		//		goto L004E;
		//	recompiler->run();
		//	GetStatic(System::ClassInit, System::out)->println("Done.");
		return;
	}

	//void Recompiler::addClassPath(String *classPath)
	//{
	//	this->classPaths->add(classPath);
	//	return;
	//}

	//void Recompiler::run()
	//{
	//	ClassFile* classFile = nullptr;
	//	List<Object*>* newClassNames = nullptr;
	//	String* newClassName = nullptr;
	//	classFile = this->processClassFile(this->mainClass);
	//	this->processedClasses->put(classFile->getClassName(), classFile);
	//	newClassNames = new ArrayList<Object*>();
	//	this->addReferencedClasses(newClassNames, classFile);
	//	goto L004B;
	//	L0027: //
	//	// ASSERT_KINDOF(String*, newClassNames->remove(0));
	//	newClassName = (String*) newClassNames->remove(0);
	//	classFile = this->processClassFile(newClassName);
	//	this->processedClasses->put(classFile->getClassName(), classFile);
	//	this->addReferencedClasses(newClassNames, classFile);
	//	L004B: //
	//	if ((newClassNames->size()) > 0)
	//		goto L0027;
	//	this->generateClasses();
	//	this->writeClasses();
	//	return;
	//}

	//void Recompiler::setMainClass(String *mainClass)
	//{
	//	if ((this->mainClass) == nullptr)
	//		goto L0030;
	//	throw new RuntimeException((new StringBuilder("Main class already set to '"))->append(this->mainClass)->append("', not setting it to '")->append(mainClass)->append("'")->toString());
	//	L0030: //
	//	this->mainClass = mainClass;
	//	return;
	//}

	//void Recompiler::setOutputPath(String *outputPath)
	//{
	//	if ((this->outputPath) == nullptr)
	//		goto L0030;
	//	throw new RuntimeException((new StringBuilder("Output path already set to '"))->append(this->outputPath)->append("', not setting it to '")->append(outputPath)->append("'")->toString());
	//	L0030: //
	//	this->outputPath = outputPath;
	//	return;
	//}

	//void Recompiler::setVisualStudio(String *visualStudio)
	//{
	//	if ((this->visualStudio) == nullptr)
	//		goto L0030;
	//	throw new RuntimeException((new StringBuilder("Visual Studio already set to '"))->append(this->visualStudio)->append("', not setting it to '")->append(visualStudio)->append("'")->toString());
	//	L0030: //
	//	this->visualStudio = visualStudio;
	//	return;
	//}

	//void Recompiler::addReferencedClasses(List<Object*> *newClassNames, ClassFile *classFile)
	//{
	//	List<Object*>* allReferences = nullptr;
	//	String* reference = nullptr;
	//	allReferences = classFile->getReferencedClasses();
	//	Iterator<Object*>* local_000B = (Iterator<Object*>*) allReferences->iterator();
	//	goto L0050;
	//	L0010: //
	//	// ASSERT_KINDOF(String*, local_000B->next());
	//	reference = (String*) local_000B->next();
	//	if (reference->startsWith("java."))
	//		goto L0050;
	//	if (reference->startsWith("["))
	//		goto L0050;
	//	if (this->processedClasses->containsKey(reference))
	//		goto L0050;
	//	if (newClassNames->contains(reference))
	//		goto L0050;
	//	newClassNames->add(reference);
	//	L0050: //
	//	if (local_000B->hasNext())
	//		goto L0010;
	//	return;
	//}

	//void Recompiler::generateClass(String *className)
	//{
	//	CppClass* cppClass = nullptr;
	//	// ASSERT_KINDOF(ClassFile*, this->processedClasses->get(className));
	//	cppClass = new CppClass(this->processedClasses->get(className));
	//	this->generatedClasses->add(cppClass);
	//	return;
	//}

	//void Recompiler::generateClasses()
	//{
	//	this->generateClass(this->mainClass);
	//	return;
	//}

	//ClassFile* Recompiler::processClassFile(String *classFileName)
	//{
	//	String* classPathFileName = nullptr;
	//	String* fileName = nullptr;
	//	String* classPath = nullptr;
	//	File* file = nullptr;
	//	ClassFile* classFile = nullptr;
	//	if (!(classFileName->startsWith("java.")))
	//		goto L000B;
	//	return nullptr;
	//	L000B: //
	//	String::ClassInit();
	//	classPathFileName = (new StringBuilder(String::valueOf(classFileName->replace(46, 47))))->append(".class")->toString();
	//	fileName = nullptr;
	//	Iterator<Object*>* local_002F = (Iterator<Object*>*) this->classPaths->iterator();
	//	goto L008F;
	//	L0034: //
	//	// ASSERT_KINDOF(String*, local_002F->next());
	//	classPath = (String*) local_002F->next();
	//	String::ClassInit();
	//	file = new File((new StringBuilder(String::valueOf(classPath)))->append("/")->append(classPathFileName)->toString());
	//	if (!(file->exists()))
	//		goto L008F;
	//	if (!(file->isFile()))
	//		goto L008F;
	//	String::ClassInit();
	//	fileName = (new StringBuilder(String::valueOf(classPath)))->append("/")->append(classPathFileName)->toString();
	//	goto L0099;
	//	L008F: //
	//	if (local_002F->hasNext())
	//		goto L0034;
	//	L0099: //
	//	if ((fileName) != nullptr)
	//		goto L00D3;
	//	GetStatic(System::ClassInit, System::out)->println((new StringBuilder("Error: "))->append(classFileName)->toString());
	//	throw new RuntimeException((new StringBuilder("Class "))->append(classFileName)->append(" not found")->toString());
	//	L00D3: //
	//	classFile = new ClassFile();
	//	try
	//	{
	//		L00DC: //
	//		classFile->read(fileName);
	//		L00E2: //
	//		goto L00EC;
	//	}
	//	catch (ClassFormatError* e)
	//	{
	//		e->printStackTrace();
	//	}
	//	catch (IOException* e)
	//	{
	//		e->printStackTrace();
	//	}
	//	L00EC: //
	//	try
	//	{
	//		IndentedOutputStream* stream = nullptr;
	//		String::ClassInit();
	//		stream = new IndentedOutputStream((new StringBuilder(String::valueOf(fileName->substring(0, (fileName->length()) - (5)))))->append("txt")->toString());
	//		classFile->dump(stream);
	//		L011A: //
	//		goto L0124;
	//	}
	//	catch (IOException* e)
	//	{
	//		e->printStackTrace();
	//	}
	//	L0124: //
	//	return classFile;
	//}

	//void Recompiler::setCommentLevel(String *commentLevel)
	//{
	//	String* local_0002 = commentLevel;
	//	switch (commentLevel->hashCode())
	//	{
	//	case (int) 0x000179A1:
	//		goto L0020;
	//	case (int) 0x0033AF38:
	//		goto L002D;
	//	default:
	//		goto L004F;
	//	}
	//	L0020: //
	//	if (local_0002->equals("all"))
	//		goto L0039;
	//	goto L004F;
	//	L002D: //
	//	if (local_0002->equals("none"))
	//		goto L0044;
	//	goto L004F;
	//	L0039: //
	//	Recompiler::ClassInit();
	//	Recompiler::instructionComments = true;
	//	Recompiler::ClassInit();
	//	Recompiler::stackComments = true;
	//	goto L0068;
	//	L0044: //
	//	Recompiler::ClassInit();
	//	Recompiler::instructionComments = false;
	//	Recompiler::ClassInit();
	//	Recompiler::stackComments = false;
	//	goto L0068;
	//	L004F: //
	//	throw new RuntimeException((new StringBuilder("Unsupported comment level "))->append(commentLevel)->toString());
	//	L0068: //
	//	return;
	//}

	//void Recompiler::writeClasses()
	//{
	//	CppClass* cppClass = nullptr;
	//	Iterator<Object*>* local_0007 = (Iterator<Object*>*) this->generatedClasses->iterator();
	//	goto L001D;
	//	L000B: //
	//	// ASSERT_KINDOF(CppClass*, local_0007->next());
	//	cppClass = (CppClass*) local_0007->next();
	//	cppClass->writeClass(this->outputPath);
	//	L001D: //
	//	if (local_0007->hasNext())
	//		goto L000B;
	//	return;
	//}

}
