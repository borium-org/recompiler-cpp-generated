#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class String;
}

namespace java::util
{
	template <class A> class ArrayList;
	template <class A, class B> class HashMap;
	template <class A> class Iterator;
	template <class A> class List;
}

namespace org::borium::javarecompiler::classfile
{
	class ClassFile;
}

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;
using namespace org::borium::javarecompiler::cplusplus;

namespace org::borium::javarecompiler
{

	class Recompiler : public Object
	{
	public:
		static bool instructionComments;
		static bool stackComments;
		Pointer<String> mainClass;
		Pointer<ArrayList<String>> classPaths;
		Pointer<ArrayList<HashMap<String, String>>> dummy;
		Pointer<String> outputPath;
		Pointer<String> visualStudio;
		Pointer<HashMap<String, ClassFile>> processedClasses;
		Pointer<ArrayList<CppClass>> generatedClasses;

		static void ClassInit();
		Recompiler();
		static void main(Pointer<JavaArray<String>> args);
		virtual void addClassPath(Pointer<String> classPath);
		virtual void run();
		virtual void setMainClass(Pointer<String> mainClass);
		virtual void setOutputPath(Pointer<String> outputPath);
		virtual void setVisualStudio(Pointer<String> visualStudio);
		virtual void addReferencedClasses(Pointer<List<String>> newClassNames, Pointer<ClassFile> classFile);
		virtual void generateClass(Pointer<String> className);
		virtual void generateClasses();
		virtual Pointer<ClassFile> processClassFile(Pointer<String> classFileName);
		virtual void setCommentLevel(Pointer<String> commentLevel);
		virtual void writeClasses();
	};

}
