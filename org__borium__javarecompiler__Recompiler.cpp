#include "org__borium__javarecompiler__Recompiler.h"

namespace org::borium::javarecompiler
{

	Recompiler::Recompiler() :
			// L0000:
			//			aload 0
			//				stack[0]: org::borium::javarecompiler::Recompiler=this
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
		L0004:
		//		aload 0
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//		new java.util.ArrayList
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: ArrayList*=new
		//		dup
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: ArrayList*=new
		//				stack[2]: ArrayList*=new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: ArrayList*=new ArrayList()
		//		putfield classPaths Ljava/util/ArrayList;
		this->classPaths = new ArrayList<String*>();
		//				stack: empty
		L000F:
		//		aload 0
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//		new java.util.HashMap
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: HashMap*=new
		//		dup
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: HashMap*=new
		//				stack[2]: HashMap*=new
		//		invokespecial java.util.HashMap.<init>
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: HashMap*=new HashMap()
		//		putfield processedClasses Ljava/util/HashMap;
		this->processedClasses = new HashMap<String*, ClassFile*>();
		//				stack: empty
		L001A:
		//		aload 0
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//		new java.util.ArrayList
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: ArrayList*=new
		//		dup
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: ArrayList*=new
		//				stack[2]: ArrayList*=new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]: org::borium::javarecompiler::Recompiler=this
		//				stack[1]: ArrayList*=new ArrayList()
		//		putfield generatedClasses Ljava/util/ArrayList;
		this->generatedClasses = new ArrayList<CppClass*>();
		//				stack: empty
		L0025:
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::main(JavaArray<String*> *param0)
	{
		L0000:
		//		aload 0
		//				stack[0]: JavaArray<String*>*=param0
		//		arraylength
		//				stack[0]: int=param0->length
		//		ifne L0035
		if ((param0->length) != 0)
			goto L0035;
		//				stack: empty
		L0005:
		//		bipush 8
		//				stack[0]: int=8
		//		anewarray java.lang.String
		{
			JavaArray<String*>* temp = new JavaArray<String*>(8);
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			iconst 0
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=0
			//			ldc "-classpath"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=0
			//				stack[3]: String *="-classpath"
			//			aastore
			temp->assignString(0, "-classpath");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			iconst 1
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=1
			//			ldc "bin"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=1
			//				stack[3]: String *="bin"
			//			aastore
			temp->assignString(1, "bin");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			iconst 2
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=2
			//			ldc "-outputpath"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=2
			//				stack[3]: String *="-outputpath"
			//			aastore
			temp->assignString(2, "-outputpath");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			iconst 3
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=3
			//			ldc "../JrcPortCpp"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=3
			//				stack[3]: String *="../JrcPortCpp"
			//			aastore
			temp->assignString(3, "../JrcPortCpp");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			iconst 4
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=4
			//			ldc "-mainclass"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=4
			//				stack[3]: String *="-mainclass"
			//			aastore
			temp->assignString(4, "-mainclass");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			iconst 5
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=5
			//			ldc "org.borium.javarecompiler.Recompiler"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=5
			//				stack[3]: String *="org.borium.javarecompiler.Recompiler"
			//			aastore
			temp->assignString(5, "org.borium.javarecompiler.Recompiler");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			bipush 6
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=6
			//			ldc "-vs"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=6
			//				stack[3]: String *="-vs"
			//			aastore
			temp->assignString(6, "-vs");
			//				stack[0]: JavaArray<String*>*=temp
			//			dup
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//			bipush 7
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=7
			//			ldc "2005"
			//				stack[0]: JavaArray<String*>*=temp
			//				stack[1]: JavaArray<String*>*=temp
			//				stack[2]: int=7
			//				stack[3]: String *="2005"
			//			aastore
			temp->assignString(7, "2005");
			//				stack[0]: JavaArray<String*>*=temp
			//			astore 0
			param0 = temp;
		}
		//				stack: empty
		L0035:
		//		new org.borium.javarecompiler.Recompiler
		//				stack[0]: Recompiler*=new
		//		dup
		//				stack[0]: Recompiler*=new
		//				stack[1]: Recompiler*=new
		//		invokespecial org.borium.javarecompiler.Recompiler.<init>
		//				stack[0]: Recompiler*=new Recompiler()
		//		astore 1
		Recompiler* local1 = new Recompiler();
		//				stack: empty
		L003D:
		//		iconst 0
		//				stack[0]: int=0
		//		istore 2
		int local2 = 0;
		//				stack: empty
		L003F:
		//		goto L00F1
		goto L00F1;
		//				stack: empty
		L0042:
		//		aload 0
		//				stack[0]: JavaArray<String*>*=param0
		//		iload 2
		//				stack[0]: JavaArray<String*>*=param0
		//				stack[1]: int=local2
		//		aaload
		//				stack[0]: String*=param0[local2]
		//		dup
		//				stack[0]: String*=param0[local2]
		//				stack[1]: String*=param0[local2]
		//		astore 3
		String* local3 = param0[local2];
		//				stack[0]: String*=param0[local2]
		//		invokevirtual java.lang.String.hashCode
		{
		}
	}
}
