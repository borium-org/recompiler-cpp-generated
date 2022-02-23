#include "stdafx.h"
#include "JrcPortCpp.h"
#include "org__borium__javarecompiler__Recompiler.h"

using namespace java::lang;

using namespace org::borium::javarecompiler;

int main(int argc, char** argv)
{
	int nRetCode = 0;
	Pointer<JavaArray<String>> args = new JavaArray<String>(argc - 1);
	for (int i = 1; i < argc; i++)
		args[i - 1] = new String(argv[i]);
	Recompiler::ClassInit();
	Recompiler::main(args);
	return nRetCode;
}
