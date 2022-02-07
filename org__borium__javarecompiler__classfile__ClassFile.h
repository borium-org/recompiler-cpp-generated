#ifndef ORG__BORIUM__JAVARECOMPILER__CLASSFILE__CLASSFILE
#define ORG__BORIUM__JAVARECOMPILER__CLASSFILE__CLASSFILE

#include "java__lang__Object.h"

using namespace java::lang;

namespace org::borium::javarecompiler::classfile
{
	class ClassFile: public Object
	{
	public:
		virtual String* getClassName();
	};
}

#endif
