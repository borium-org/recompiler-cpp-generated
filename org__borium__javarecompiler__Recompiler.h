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
		CountedReference<String*> ref_mainClass;
		ArrayList<String*>* classPaths;
		CountedReference<ArrayList<String*>*> ref_classPaths;
		ArrayList<HashMap<String*, String*>*>* dummy;
		CountedReference<ArrayList<HashMap<String*, String*>*>*> ref_dummy;
		String* outputPath;
		CountedReference<String*> ref_outputPath;
		String* visualStudio;
		CountedReference<String*> ref_visualStudio;
		HashMap<String*, ClassFile*>* processedClasses;
		CountedReference<HashMap<String*, ClassFile*>*> ref_processedClasses;
		ArrayList<CppClass*>* generatedClasses;
		CountedReference<ArrayList<CppClass*>*> ref_generatedClasses;

		Recompiler();
		static void main(JavaArray<String*> *param0);
		virtual void addClassPath(String *param1);
		virtual void run();
		virtual void setMainClass(String *param1);
		virtual void setOutputPath(String *param1);
		virtual void setVisualStudio(String *param1);
		virtual void addReferencedClasses(List *param1, ClassFile *param2);
		virtual void generateClass(String *param1);
		virtual void generateClasses();
		virtual ClassFile* processClassFile(String *param1);
		virtual void writeClasses();
	};

}

#endif
