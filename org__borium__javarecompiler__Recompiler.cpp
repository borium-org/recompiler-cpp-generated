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
					, ref_mainClass(mainClass) //
					, classPaths(0) //
					, ref_classPaths(classPaths) //
					, dummy(0) //
					, ref_dummy(dummy) //
					, outputPath(0) //
					, ref_outputPath(outputPath) //
					, visualStudio(0) //
					, ref_visualStudio(visualStudio) //
					, processedClasses(0) //
					, ref_processedClasses(processedClasses) //
					, generatedClasses(0) //
					, ref_generatedClasses(generatedClasses) //
	{
		// L0004:
		//		aload 0
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		new java.util.ArrayList
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=ArrayList*-new
		//		dup
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=ArrayList*-new
		//				stack[2]=ArrayList*-new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=ArrayList*-new ArrayList()
		//		putfield 28 classPaths
		this->classPaths = new ArrayList<String*>();
		//				stack: empty
		// L000F:
		//		aload 0
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		new java.util.HashMap
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=HashMap*-new
		//		dup
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=HashMap*-new
		//				stack[2]=HashMap*-new
		//		invokespecial java.util.HashMap.<init>
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=HashMap*-new HashMap()
		//		putfield 33 processedClasses
		this->processedClasses = new HashMap<String*, ClassFile*>();
		//				stack: empty
		// L001A:
		//		aload 0
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//		new java.util.ArrayList
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=ArrayList*-new
		//		dup
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=ArrayList*-new
		//				stack[2]=ArrayList*-new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]=org::borium::javarecompiler::Recompiler-this
		//				stack[1]=ArrayList*-new ArrayList()
		//		putfield 35 generatedClasses
		this->generatedClasses = new ArrayList<CppClass*>();
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
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//		iconst 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//		ldc "-classpath"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//		iconst 1
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//		ldc "bin"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//		iconst 2
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//		ldc "-outputpath"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//		iconst 3
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//		ldc "../JrcPortCpp"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//		iconst 4
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//		ldc "-mainclass"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//		iconst 5
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//		ldc "org.borium.javarecompiler.Recompiler"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//		bipush 6
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//		ldc "-vs"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//		bipush 7
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//		ldc "2005"
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//		aastore
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//		astore 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		// L0035:
		//		new org.borium.javarecompiler.Recompiler
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new
		//				stack[10]=Recompiler*-new
		//		invokespecial org.borium.javarecompiler.Recompiler.<init>
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//		astore 1
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		// L003D:
		//		iconst 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//		istore 2
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		// L003F:
		//		goto L00F1
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		// L0042:
		//		aload 0
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//		iload 2
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//		aaload
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//		dup
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//				stack[11]=JavaArray<java::lang::String*>*-param0
		//		astore 3
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//				stack[11]=JavaArray<java::lang::String*>*-param0
		//		invokevirtual java.lang.String.hashCode
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//				stack[11]=JavaArray<java::lang::String*>*-param0
		//		lookupswitch 4 cases
		//				stack[0]=JavaArray<java::lang::String*>*-param0
		//				stack[1]=JavaArray<java::lang::String*>*-param0
		//				stack[2]=JavaArray<java::lang::String*>*-param0
		//				stack[3]=JavaArray<java::lang::String*>*-param0
		//				stack[4]=JavaArray<java::lang::String*>*-param0
		//				stack[5]=JavaArray<java::lang::String*>*-param0
		//				stack[6]=JavaArray<java::lang::String*>*-param0
		//				stack[7]=JavaArray<java::lang::String*>*-param0
		//				stack[8]=JavaArray<java::lang::String*>*-param0
		//				stack[9]=Recompiler*-new Recompiler()
		//				stack[10]=JavaArray<java::lang::String*>*-param0
		//				stack[11]=JavaArray<java::lang::String*>*-param0
		// L0074:
		//		aload 3
	}
}
