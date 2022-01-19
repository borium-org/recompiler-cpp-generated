#include "org__borium__javarecompiler__Recompiler.h"

namespace org::borium::javarecompiler
{

	Recompiler::Recompiler() :
			// L0000:
			//			aload 0
			//				stack[0]=org::borium::javarecompiler::Recompiler-this
			//			invokespecial java.lang.Object.<init>
			Object()
			//				stack: empty
			, mainClass(0) //
					, classPaths(0) //
					, dummy(0) //
					, outputPath(0) //
					, visualStudio(0) //
					, processedClasses(0) //
					, generatedClasses(0) //
	{
		// L0004:
		//		aload 0
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		new java.util.ArrayList
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		dup
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		invokespecial java.util.ArrayList.<init>
		//				stack: empty
		//		putfield 28 classPaths
		//				stack: empty
		// L000F:
		//		aload 0
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		new java.util.HashMap
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		dup
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		invokespecial java.util.HashMap.<init>
		//				stack: empty
		//		putfield 33 processedClasses
		//				stack: empty
		// L001A:
		//		aload 0
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		new java.util.ArrayList
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		dup
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		invokespecial java.util.ArrayList.<init>
		//				stack: empty
		//		putfield 35 generatedClasses
		//				stack: empty
		// L0025:
		//		return
		//				stack: empty
	}

	void Recompiler::main(JavaArray<String*> *param0)
	{
		// L0000:
		//		aload 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		arraylength
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ifne L0035
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		// L0005:
		//		bipush 8
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		anewarray java.lang.String
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iconst 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "-classpath"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iconst 1
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "bin"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iconst 2
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "-outputpath"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iconst 3
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "../JrcPortCpp"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iconst 4
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "-mainclass"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iconst 5
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "org.borium.javarecompiler.Recompiler"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		bipush 6
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "-vs"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		bipush 7
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		ldc "2005"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		astore 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		// L0035:
		//		new org.borium.javarecompiler.Recompiler
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		invokespecial org.borium.javarecompiler.Recompiler.<init>
		//				stack: empty
		//		astore 1
		//				stack: empty
		// L003D:
		//		iconst 0
		//				stack: empty
		//		istore 2
		//				stack: empty
		// L003F:
		//		goto L00F1
		//				stack: empty
		// L0042:
		//		aload 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		iload 2
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		aaload
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		astore 3
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		invokevirtual java.lang.String.hashCode
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//		lookupswitch 4 cases
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		// L0074:
		//		aload 3
	}
}
