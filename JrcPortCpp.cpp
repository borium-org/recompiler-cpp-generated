#include "stdafx.h"
#include "JrcPortCpp.h"
#include "org__borium__javarecompiler__Recompiler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace java::lang;

using namespace org::borium::javarecompiler;

int main(int argc, char * argv)
{
	int nRetCode = 0;
	Pointer<JavaArray<String>> args = new JavaArray<String>(10);
	//JavaArray<String> & array = args.get();
	//for (int i = 0; i < argc - 1; i++)
	//	args[i] = argv[i + 1];
	Recompiler::main(args);
	return nRetCode;
}
