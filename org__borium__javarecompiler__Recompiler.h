#ifndef ORG__BORIUM__JAVARECOMPILER__RECOMPILER
#define ORG__BORIUM__JAVARECOMPILER__RECOMPILER

#include "java__io__File.h"
#include "java__io__IOException.h"
#include "java__io__PrintStream.h"
#include "java__lang__ClassFormatError.h"
#include "java__lang__Object.h"
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
#include "org__borium__javarecompiler__cplusplus__CppClass.h"

using namespace java::io;
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
		//	virtual void addReferencedClasses(List<Object*> *newClassNames, ClassFile *classFile);
		//	virtual void generateClass(String *className);
		//	virtual void generateClasses();
		virtual Pointer<ClassFile> processClassFile(Pointer<String> classFileName);
		virtual void setCommentLevel(Pointer<String> commentLevel);
		//	virtual void writeClasses();
	private:
		static bool classInitialized;
	};

}

#endif
