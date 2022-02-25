#ifndef ORG__BORIUM__JAVARECOMPILER__CLASSFILE__CLASSFILE
#define ORG__BORIUM__JAVARECOMPILER__CLASSFILE__CLASSFILE

#include "java__lang__Object.h"
#include "java__lang__String.h"
#include "java__util__List.h"
#include "org__borium__javarecompiler__classfile__IndentedOutputStream.h"

using namespace java::lang;
using namespace java::util;

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::classfile
{
	class ClassFile : public Object
	{
	public:
		ClassFile();
		virtual ~ClassFile();
		virtual void read(Pointer<String> fileName);
		virtual Pointer<String> getClassName();
		virtual void dump(Pointer<IndentedOutputStream> stream);
		virtual Pointer<List<String>> getReferencedClasses();
	};
}

#endif
