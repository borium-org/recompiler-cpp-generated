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

	bool Recompiler::dumpInstructions;

	bool Recompiler::dumpStatements;

	void Recompiler::ClassInit()
	{
		Object::ClassInit();
		Recompiler::instructionComments = false;
		Recompiler::stackComments = false;
		Recompiler::dumpInstructions = true;
		Recompiler::dumpStatements = true;
		return;
	}

	Recompiler::Recompiler() :
		Object() //
	{
		Pointer<ArrayList<Object>> temp_0009;
		Pointer<HashMap<Object, Object>> temp_0014;
		Pointer<ArrayList<Object>> temp_001F;
		temp_0009 = new ArrayList<Object>();
		this->classPaths = (ArrayList<String>*)(temp_0009.getValue());
		temp_0014 = new HashMap<Object, Object>();
		this->processedClasses = (HashMap<String, ClassFile>*)(temp_0014.getValue());
		temp_001F = new ArrayList<Object>();
		this->generatedClasses = (ArrayList<CppClass>*)(temp_001F.getValue());
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
		args = (JavaArray<String>*)(temp_0007.getValue());
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
		Pointer<List<String>> newClassNames;
		Pointer<ArrayList<Object>> temp_001A;
		classFile = this->processClassFile(this->mainClass);
		this->processedClasses->put(classFile->getClassName(), classFile);
		temp_001A = new ArrayList<Object>();
		newClassNames = (List<String>*)(temp_001A.getValue());
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
		Pointer<Iterator<Object>> local_0009;
		Pointer<String> temp_0015;
		allReferences = classFile->getReferencedClasses();
		local_0009 = (Iterator<Object>*)(allReferences->iterator().getValue());
		goto L004E;
	L000E: //
		temp_0015 = (String*)((local_0009->next()).getValue());
		temp_0015->checkCast(String::getClass());
		reference = temp_0015;
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
		Pointer<ClassFile> temp_000C;
		Pointer<CppClass> temp_000F;
		temp_000C = (ClassFile*)((this->processedClasses->get(className)).getValue());
		temp_000C->checkCast(ClassFile::getClass());
		temp_000F = new CppClass(temp_000C);
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
		Pointer<Iterator<Object>> local_0030;
		Pointer<String> temp_003C;
		Pointer<StringBuilder> temp_004E;
		Pointer<File> temp_005E;
		Pointer<StringBuilder> temp_007C;
		Pointer<StringBuilder> temp_00A8;
		Pointer<StringBuilder> temp_00C0;
		Pointer<RuntimeException> temp_00D0;
		Pointer<ClassFile> temp_00D8;
		Pointer<StringBuilder> temp_0103;
		Pointer<IndentedOutputStream> temp_010F;
		if (!(classFileName->startsWith("java.")))
			goto L000B;
		// ARETURN: Type mismatch
		return nullptr;
	L000B: //
		String::ClassInit();
		temp_001A = new StringBuilder(String::valueOf(classFileName->replace(46, 47)));
		classPathFileName = temp_001A->append(".class")->toString();
		fileName = nullptr;
		local_0030 = (Iterator<Object>*)(this->classPaths->iterator().getValue());
		goto L0090;
	L0035: //
		temp_003C = (String*)((local_0030->next()).getValue());
		temp_003C->checkCast(String::getClass());
		classPath = temp_003C;
		String::ClassInit();
		temp_004E = new StringBuilder(String::valueOf(classPath));
		temp_005E = new File(temp_004E->append("/")->append(classPathFileName)->toString());
		file = temp_005E;
		if (!(file->exists()))
			goto L0090;
		if (!(file->isFile()))
			goto L0090;
		String::ClassInit();
		temp_007C = new StringBuilder(String::valueOf(classPath));
		fileName = temp_007C->append("/")->append(classPathFileName)->toString();
		goto L009A;
	L0090: //
		if (local_0030->hasNext())
			goto L0035;
	L009A: //
		if ((fileName) != nullptr)
			goto L00D4;
		temp_00A8 = new StringBuilder("Error: ");
		GetStatic(System::ClassInit, System::out)->println(temp_00A8->append(classFileName)->toString());
		temp_00C0 = new StringBuilder("Class ");
		temp_00D0 = new RuntimeException(temp_00C0->append(classFileName)->append(" not found")->toString());
		throw temp_00D0;
	L00D4: //
		temp_00D8 = new ClassFile();
		classFile = temp_00D8;
	L00DD: //
		try
		{
			classFile->read(fileName);
		L00E3: //
			goto L00ED;
		}
		catch (ClassFormatError* e)
		{
			e->printStackTrace();
		}
		catch (IOException* e)
		{
			e->printStackTrace();
		}
	L00ED: //
		try
		{
			Pointer<IndentedOutputStream> stream;
			String::ClassInit();
			temp_0103 = new StringBuilder(String::valueOf(fileName->substring(0, (fileName->length()) - (5))));
			temp_010F = new IndentedOutputStream(temp_0103->append("txt")->toString());
			stream = temp_010F;
			classFile->dump(stream);
			stream->close();
		L0120: //
			goto L012A;
		}
		catch (IOException* e)
		{
			e->printStackTrace();
		}
	L012A: //
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
		Pointer<Iterator<Object>> local_0007;
		Pointer<CppClass> temp_0011;
		local_0007 = (Iterator<Object>*)(this->generatedClasses->iterator().getValue());
		goto L001D;
	L000B: //
		temp_0011 = (CppClass*)((local_0007->next()).getValue());
		temp_0011->checkCast(CppClass::getClass());
		cppClass = temp_0011;
		cppClass->writeClass(this->outputPath);
	L001D: //
		if (local_0007->hasNext())
			goto L000B;
		return;
	}

}
