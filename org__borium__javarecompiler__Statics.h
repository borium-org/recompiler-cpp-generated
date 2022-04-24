#pragma once

#include "java__lang__Object.h"

namespace java::lang
{
	class String;
}

namespace java::util
{
	template <class A> class Iterator;
}

namespace org::borium::javarecompiler::classfile
{
	class IndentedOutputStream;
}

using namespace java::lang;
using namespace java::util;
using namespace org::borium::javarecompiler::classfile;

namespace org::borium::javarecompiler
{

	class Statics : public Object
	{
	public:

		Statics();
		static Pointer<String> addPointerIfNeeded(Pointer<String> type);
		static Pointer<String> addPointersIfNeeded(Pointer<String> methodType);
		static void Assert(bool condition, Pointer<String> errorMessage);
		static void Check(Pointer<IndentedOutputStream> stream, bool condition, Pointer<String> errorMessage);
		static Pointer<String> commaSeparatedList(Pointer<JavaArray<String>> values);
		static Pointer<String> dotToNamespace(Pointer<String> dots);
		static int getParameterCount(Pointer<String> javaDescriptor);
		static Pointer<String> hexString(int value, int length);
		static bool isTemplate(Pointer<String> type);
		static Pointer<String> javaToCppClass(Pointer<String> javaClassName);
		static Pointer<String> parseJavaReturnType(Pointer<String> javaMethodSignature);
		static Pointer<String> removeJavaArray(Pointer<String> javaArray);
		static Pointer<String> removePointerWrapper(Pointer<String> wrappedObject);
		static void parseClass(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data);
		static void parseSingleType(Pointer<String> descriptor, Pointer<JavaRawArray<int>> data);
	};

}
