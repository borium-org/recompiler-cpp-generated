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

	class Recompiler: public Object
	{
	public:
		String* mainClass;
		ArrayList<String*>* classPaths;
		ArrayList<HashMap<String*, String*>*>* dummy;
		String* outputPath;
		String* visualStudio;
		HashMap<String*, ClassFile*>* processedClasses;
		ArrayList<CppClass*>* generatedClasses;

		Recompiler();
		static void main(JavaArray<String*> *param0);
		void addClassPath(String *param1);
		void run();
		void setMainClass(String *param1);
		void setOutputPath(String *param1);
		void setVisualStudio(String *param1);
		void addReferencedClasses(List *param1, ClassFile *param2);
		void generateClass(String *param1);
		void generateClasses();
		ClassFile* processClassFile(String *param1);
		void writeClasses();
	};

}

#endif
