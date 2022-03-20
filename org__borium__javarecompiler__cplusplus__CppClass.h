#ifndef ORG__BORIUM__JAVARECOMPILER__CPLUSPLUS__CPPCLASS
#define ORG__BORIUM__JAVARECOMPILER__CPLUSPLUS__CPPCLASS

#include "java__lang__Object.h"
#include "java__lang__String.h"

#include "org__borium__javarecompiler__classfile__ClassFile.h"

using namespace java::lang;

using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler::cplusplus
{
	class CppClass : public Object
	{
	public:
		CppClass(Pointer<ClassFile> name);
		virtual ~CppClass();
		virtual void writeClass(Pointer<String> fileName);
	};
}

#endif
