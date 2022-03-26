#include "stdafx.h"
#include "org__borium__javarecompiler__Recompiler.h"

#include "java__io__File.h"
#include "java__io__IOException.h"
#include "java__io__PrintStream.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__RuntimeException.h"
#include "java__lang__String.h"
#include "java__lang__StringBuilder.h"
#include "java__lang__System.h"
#include "java__lang__Throwable.h"
#include "java__util__ArrayList.h"
#include "java__util__HashMap.h"
#include "java__util__Iterator.h"
#include "java__util__List.h"
#include "org__borium__javarecompiler__classfile__ClassFile.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"
#include "org__borium__javarecompiler__classfile__ReferencedClasses.h"
#include "org__borium__javarecompiler__cplusplus__CppClass.h"

using namespace java::io;
using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler
{

	bool Recompiler::instructionComments;

	bool Recompiler::stackComments;

	void Recompiler::ClassInit()
	{
		Object::ClassInit();
		Recompiler::instructionComments = false;
		Recompiler::stackComments = false;
		return;
	}

	Recompiler::Recompiler() :
		Object() //
	{
		Pointer<ArrayList> temp_0009;
		Pointer<HashMap> temp_0014;
		Pointer<ArrayList> temp_001F;
		temp_0009 = new ArrayList();
		this->classPaths = temp_0009;
		temp_0014 = new HashMap();
		this->processedClasses = temp_0014;
		temp_001F = new ArrayList();
		this->generatedClasses = temp_001F;
		return;
	}

	void Recompiler::main(Pointer<JavaArray<String>> args)
	{
		Pointer<Recompiler> recompiler;
		int argc = 0;
		Pointer<JavaArray<String>> temp_0007;
		Pointer<Recompiler> temp_0045;
		Pointer<String> local_0052;
		Pointer<StringBuilder> temp_010A;
		Pointer<RuntimeException> temp_0116;
		if ((args->length) != 0)
			goto L0041;
		temp_0007 = new JavaArray<String>(10);
		temp_0007->assignString(0, "-classpath");
		temp_0007->assignString(1, "bin");
		temp_0007->assignString(2, "-outputpath");
		temp_0007->assignString(3, "../JrcPortCpp");
		temp_0007->assignString(4, "-mainclass");
		temp_0007->assignString(5, "org.borium.javarecompiler.Recompiler");
		temp_0007->assignString(6, "-vs");
		temp_0007->assignString(7, "2005");
		temp_0007->assignString(8, "-comments");
		temp_0007->assignString(9, "none");
		args = temp_0007;
	L0041: //
		temp_0045 = new Recompiler();
		recompiler = temp_0045;
		argc = 0;
		goto L011D;
	L004E: //
		local_0052 = args->get(argc);
		switch (args->get(argc)->hashCode())
		{
		case (int)0xE0528093:
			goto L0088;
		case (int)0xE22731D2:
			goto L0094;
		case (int)0xEC1F6121:
			goto L00A0;
		case (int)0xF0617410:
			goto L00AC;
		case (int)0x0000B7AA:
			goto L00B8;
		default:
			goto L0100;
		}
	L0088: //
		if (local_0052->equals("-outputpath"))
			goto L00D0;
		goto L0100;
	L0094: //
		if (local_0052->equals("-mainclass"))
			goto L00DC;
		goto L0100;
	L00A0: //
		if (local_0052->equals("-comments"))
			goto L00F4;
		goto L0100;
	L00AC: //
		if (local_0052->equals("-classpath"))
			goto L00C4;
		goto L0100;
	L00B8: //
		if (local_0052->equals("-vs"))
			goto L00E8;
		goto L0100;
	L00C4: //
		recompiler->addClassPath(args->get((argc)+(1)));
		goto L011A;
	L00D0: //
		recompiler->setOutputPath(args->get((argc)+(1)));
		goto L011A;
	L00DC: //
		recompiler->setMainClass(args->get((argc)+(1)));
		goto L011A;
	L00E8: //
		recompiler->setVisualStudio(args->get((argc)+(1)));
		goto L011A;
	L00F4: //
		recompiler->setCommentLevel(args->get((argc)+(1)));
		goto L011A;
	L0100: //
		temp_010A = new StringBuilder("Unsupported argument ");
		temp_0116 = new RuntimeException(temp_010A->append(args->get(argc))->toString());
		throw temp_0116;
	L011A: //
		argc += 2;
	L011D: //
		if ((argc) < (args->length))
			goto L004E;
		recompiler->run();
		GetStatic(System::ClassInit, System::out)->println("Done.");
		return;
	}

	void Recompiler::addClassPath(Pointer<String> classPath)
	{
		this->classPaths->add(classPath);
		return;
	}

	void Recompiler::run()
	{
		Pointer<ClassFile> classFile;
		Pointer<List> newClassNames;
		Pointer<ArrayList> temp_001A;
		classFile = this->processClassFile(this->mainClass);
		this->processedClasses->put(classFile->getClassName(), classFile);
		temp_001A = new ArrayList();
		newClassNames = temp_001A;
		this->addReferencedClasses(newClassNames, classFile);
		this->generateClasses();
		this->writeClasses();
		return;
	}

	void Recompiler::setMainClass(Pointer<String> mainClass)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		if ((this->mainClass) == nullptr)
			goto L0030;
		temp_0011 = new StringBuilder("Main class already set to '");
		temp_002C = new RuntimeException(temp_0011->append(this->mainClass)->append("', not setting it to '")->append(mainClass)->append("'")->toString());
		throw temp_002C;
	L0030: //
		this->mainClass = mainClass;
		return;
	}

	void Recompiler::setOutputPath(Pointer<String> outputPath)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		if ((this->outputPath) == nullptr)
			goto L0030;
		temp_0011 = new StringBuilder("Output path already set to '");
		temp_002C = new RuntimeException(temp_0011->append(this->outputPath)->append("', not setting it to '")->append(outputPath)->append("'")->toString());
		throw temp_002C;
	L0030: //
		this->outputPath = outputPath;
		return;
	}

	void Recompiler::setVisualStudio(Pointer<String> visualStudio)
	{
		Pointer<StringBuilder> temp_0011;
		Pointer<RuntimeException> temp_002C;
		if ((this->visualStudio) == nullptr)
			goto L0030;
		temp_0011 = new StringBuilder("Visual Studio already set to '");
		temp_002C = new RuntimeException(temp_0011->append(this->visualStudio)->append("', not setting it to '")->append(visualStudio)->append("'")->toString());
		throw temp_002C;
	L0030: //
		this->visualStudio = visualStudio;
		return;
	}

	void Recompiler::addReferencedClasses(Pointer<List<String>> newClassNames, Pointer<ClassFile> classFile)
	{
		Pointer<ReferencedClasses> allReferences;
		Pointer<String> reference;
		Pointer<Iterator> local_0009;
		allReferences = classFile->getReferencedClasses();
		local_0009 = allReferences->iterator();
		goto L004E;
	L000E: //
		local_0009->next()->checkCast(String::getClass());
		reference = local_0009->next();
		if (reference->startsWith("java."))
			goto L004E;
		if (reference->startsWith("["))
			goto L004E;
		if (this->processedClasses->containsKey(reference))
			goto L004E;
		if (newClassNames->contains(reference))
			goto L004E;
		newClassNames->add(reference);
	L004E: //
		if (local_0009->hasNext())
			goto L000E;
		return;
	}

	void Recompiler::generateClass(Pointer<String> className)
	{
		Pointer<CppClass> cppClass;
		Pointer<CppClass> temp_000F;
		this->processedClasses->get(className)->checkCast(ClassFile::getClass());
		temp_000F = new CppClass(this->processedClasses->get(className));
		cppClass = temp_000F;
		this->generatedClasses->add(cppClass);
		return;
	}

	void Recompiler::generateClasses()
	{
		this->generateClass(this->mainClass);
		return;
	}

	Pointer<ClassFile> Recompiler::processClassFile(Pointer<String> classFileName)
	{
		Pointer<String> classPathFileName;
		Pointer<String> fileName;
		Pointer<String> classPath;
		Pointer<File> file;
		Pointer<ClassFile> classFile;
		Pointer<StringBuilder> temp_001A;
		Pointer<Iterator> local_002F;
		Pointer<StringBuilder> temp_004D;
		Pointer<File> temp_005C;
		Pointer<StringBuilder> temp_007A;
		Pointer<StringBuilder> temp_00A5;
		Pointer<StringBuilder> temp_00BD;
		Pointer<RuntimeException> temp_00CD;
		Pointer<ClassFile> temp_00D5;
		Pointer<StringBuilder> temp_0100;
		Pointer<IndentedOutputStream> temp_010C;
		if (!(classFileName->startsWith("java.")))
			goto L000B;
		// ARETURN: Type mismatch
		return nullptr;
	L000B: //
		String::ClassInit();
		temp_001A = new StringBuilder(String::valueOf(classFileName->replace(46, 47)));
		classPathFileName = temp_001A->append(".class")->toString();
		// ASTORE: Type mismatch
		fileName = nullptr;
		local_002F = this->classPaths->iterator();
		goto L008D;
	L0034: //
		local_002F->next()->checkCast(String::getClass());
		classPath = local_002F->next();
		String::ClassInit();
		temp_004D = new StringBuilder(String::valueOf(classPath));
		temp_005C = new File(temp_004D->append("/")->append(classPathFileName)->toString());
		file = temp_005C;
		if (!(file->exists()))
			goto L008D;
		if (!(file->isFile()))
			goto L008D;
		String::ClassInit();
		temp_007A = new StringBuilder(String::valueOf(classPath));
		fileName = temp_007A->append("/")->append(classPathFileName)->toString();
		goto L0097;
	L008D: //
		if (local_002F->hasNext())
			goto L0034;
	L0097: //
		if ((fileName) != nullptr)
			goto L00D1;
		temp_00A5 = new StringBuilder("Error: ");
		GetStatic(System::ClassInit, System::out)->println(temp_00A5->append(classFileName)->toString());
		temp_00BD = new StringBuilder("Class ");
		temp_00CD = new RuntimeException(temp_00BD->append(classFileName)->append(" not found")->toString());
		throw temp_00CD;
	L00D1: //
		temp_00D5 = new ClassFile();
		classFile = temp_00D5;
	L00DA: //
		try
		{
			classFile->read(fileName);
		L00E0: //
			goto L00EA;
		}
		catch (ClassFormatError* e)
		{
			e->printStackTrace();
		}
		catch (IOException* e)
		{
			e->printStackTrace();
		}
	L00EA: //
		try
		{
			Pointer<IndentedOutputStream> stream;
			String::ClassInit();
			temp_0100 = new StringBuilder(String::valueOf(fileName->substring(0, (fileName->length()) - (5))));
			temp_010C = new IndentedOutputStream(temp_0100->append("txt")->toString());
			stream = temp_010C;
			classFile->dump(stream);
			stream->close();
		L011D: //
			goto L0127;
		}
		catch (IOException* e)
		{
			e->printStackTrace();
		}
	L0127: //
		return classFile;
	}

	void Recompiler::setCommentLevel(Pointer<String> commentLevel)
	{
		Pointer<String> local_0002;
		Pointer<StringBuilder> temp_005A;
		Pointer<RuntimeException> temp_0064;
		local_0002 = commentLevel;
		switch (commentLevel->hashCode())
		{
		case (int)0x000179A1:
			goto L0020;
		case (int)0x0033AF38:
			goto L002D;
		default:
			goto L004F;
		}
	L0020: //
		if (local_0002->equals("all"))
			goto L0039;
		goto L004F;
	L002D: //
		if (local_0002->equals("none"))
			goto L0044;
		goto L004F;
	L0039: //
		Recompiler::ClassInit();
		Recompiler::instructionComments = true;
		Recompiler::ClassInit();
		Recompiler::stackComments = true;
		goto L0068;
	L0044: //
		Recompiler::ClassInit();
		Recompiler::instructionComments = false;
		Recompiler::ClassInit();
		Recompiler::stackComments = false;
		goto L0068;
	L004F: //
		temp_005A = new StringBuilder("Unsupported comment level ");
		temp_0064 = new RuntimeException(temp_005A->append(commentLevel)->toString());
		throw temp_0064;
	L0068: //
		return;
	}

	void Recompiler::writeClasses()
	{
		Pointer<CppClass> cppClass;
		Pointer<Iterator> local_0007;
		local_0007 = this->generatedClasses->iterator();
		goto L001D;
	L000B: //
		local_0007->next()->checkCast(CppClass::getClass());
		cppClass = local_0007->next();
		cppClass->writeClass(this->outputPath);
	L001D: //
		if (local_0007->hasNext())
			goto L000B;
		return;
	}

}
