#include "org__borium__javarecompiler__Recompiler.h"

namespace org::borium::javarecompiler
{

	Recompiler::Recompiler() :
			// L0000:
			//			aload 0
			//				stack[0]: Recompiler*=this
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
		//				stack[0]: Recompiler*=this
		//		new java.util.ArrayList
		//				stack[0]: Recompiler*=this
		//				stack[1]: ArrayList*=new
		//		dup
		//				stack[0]: Recompiler*=this
		//				stack[1]: ArrayList*=new
		//				stack[2]: ArrayList*=new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]: Recompiler*=this
		//				stack[1]: ArrayList*=new ArrayList()
		//		putfield classPaths Ljava/util/ArrayList;
		this->classPaths = new ArrayList<String*>();
		//				stack: empty
		L000F:
		//		aload 0
		//				stack[0]: Recompiler*=this
		//		new java.util.HashMap
		//				stack[0]: Recompiler*=this
		//				stack[1]: HashMap*=new
		//		dup
		//				stack[0]: Recompiler*=this
		//				stack[1]: HashMap*=new
		//				stack[2]: HashMap*=new
		//		invokespecial java.util.HashMap.<init>
		//				stack[0]: Recompiler*=this
		//				stack[1]: HashMap*=new HashMap()
		//		putfield processedClasses Ljava/util/HashMap;
		this->processedClasses = new HashMap<String*, ClassFile*>();
		//				stack: empty
		L001A:
		//		aload 0
		//				stack[0]: Recompiler*=this
		//		new java.util.ArrayList
		//				stack[0]: Recompiler*=this
		//				stack[1]: ArrayList*=new
		//		dup
		//				stack[0]: Recompiler*=this
		//				stack[1]: ArrayList*=new
		//				stack[2]: ArrayList*=new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]: Recompiler*=this
		//				stack[1]: ArrayList*=new ArrayList()
		//		putfield generatedClasses Ljava/util/ArrayList;
		this->generatedClasses = new ArrayList<CppClass*>();
		//				stack: empty
		L0025:
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::main(JavaArray<String*> *args)
	{
		L0000:
		//		aload 0
		//				stack[0]: JavaArray<String*>*=args
		//		arraylength
		//				stack[0]: int=args->length
		//		ifne L0035
		if ((args->length) != 0)
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
			args = temp;
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
		recompiler = new Recompiler();
		//				stack: empty
		L003D:
		//		iconst 0
		//				stack[0]: int=0
		//		istore 2
		argc = 0;
		//				stack: empty
		L003F:
		//		goto L00F1
		goto L00F1;
		//				stack: empty
		L0042:
		//		aload 0
		//				stack[0]: JavaArray<String*>*=args
		//		iload 2
		//				stack[0]: JavaArray<String*>*=args
		//				stack[1]: int=argc
		//		aaload
		//				stack[0]: String*=args->get(argc)
		//		dup
		//				stack[0]: String*=args->get(argc)
		//				stack[1]: String*=args->get(argc)
		//		astore 3
		local_0046 = args->get(argc);
		//				stack[0]: String*=args->get(argc)
		//		invokevirtual java.lang.String.hashCode
		//				stack[0]: int=args->get(argc)->hashCode()
		//		lookupswitch 4 cases
		switch (args->get(argc)->hashCode())
		{
		case (int) 0xE0528093:
			goto L0074;
		case (int) 0xE22731D2:
			goto L0080;
		case (int) 0xF0617410:
			goto L008C;
		case (int) 0x0000B7AA:
			goto L0098;
		default:
			goto L00D4;
		}
		//				stack: empty
		L0074:
		//		aload 3
		//				stack[0]: String*=local_0046
		//		ldc "-outputpath"
		//				stack[0]: String*=local_0046
		//				stack[1]: String *="-outputpath"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0046->equals("-outputpath")
		//		ifne L00B0
		if (local_0046->equals("-outputpath"))
			goto L00B0;
		//				stack: empty
		L007D:
		//		goto L00D4
		goto L00D4;
		//				stack: empty
		L0080:
		//		aload 3
		//				stack[0]: String*=local_0046
		//		ldc "-mainclass"
		//				stack[0]: String*=local_0046
		//				stack[1]: String *="-mainclass"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0046->equals("-mainclass")
		//		ifne L00BC
		if (local_0046->equals("-mainclass"))
			goto L00BC;
		//				stack: empty
		L0089:
		//		goto L00D4
		goto L00D4;
		//				stack: empty
		L008C:
		//		aload 3
		//				stack[0]: String*=local_0046
		//		ldc "-classpath"
		//				stack[0]: String*=local_0046
		//				stack[1]: String *="-classpath"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0046->equals("-classpath")
		//		ifne L00A4
		if (local_0046->equals("-classpath"))
			goto L00A4;
		//				stack: empty
		L0095:
		//		goto L00D4
		goto L00D4;
		//				stack: empty
		L0098:
		//		aload 3
		//				stack[0]: String*=local_0046
		//		ldc "-vs"
		//				stack[0]: String*=local_0046
		//				stack[1]: String *="-vs"
		//		invokevirtual java.lang.String.equals
		//				stack[0]: bool=local_0046->equals("-vs")
		//		ifne L00C8
		if (local_0046->equals("-vs"))
			goto L00C8;
		//				stack: empty
		L00A1:
		//		goto L00D4
		goto L00D4;
		//				stack: empty
		L00A4:
		//		aload 1
		//				stack[0]: Recompiler*=recompiler
		//		aload 0
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//		iload 2
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//		iconst 1
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=(argc) + (1)
		//		aaload
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: String*=args->get((argc) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.addClassPath
		recompiler->addClassPath(args->get((argc) + (1)));
		//				stack: empty
		L00AD:
		//		goto L00EE
		goto L00EE;
		//				stack: empty
		L00B0:
		//		aload 1
		//				stack[0]: Recompiler*=recompiler
		//		aload 0
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//		iload 2
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//		iconst 1
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=(argc) + (1)
		//		aaload
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: String*=args->get((argc) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setOutputPath
		recompiler->setOutputPath(args->get((argc) + (1)));
		//				stack: empty
		L00B9:
		//		goto L00EE
		goto L00EE;
		//				stack: empty
		L00BC:
		//		aload 1
		//				stack[0]: Recompiler*=recompiler
		//		aload 0
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//		iload 2
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//		iconst 1
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=(argc) + (1)
		//		aaload
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: String*=args->get((argc) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setMainClass
		recompiler->setMainClass(args->get((argc) + (1)));
		//				stack: empty
		L00C5:
		//		goto L00EE
		goto L00EE;
		//				stack: empty
		L00C8:
		//		aload 1
		//				stack[0]: Recompiler*=recompiler
		//		aload 0
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//		iload 2
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//		iconst 1
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=argc
		//				stack[3]: int=1
		//		iadd
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: JavaArray<String*>*=args
		//				stack[2]: int=(argc) + (1)
		//		aaload
		//				stack[0]: Recompiler*=recompiler
		//				stack[1]: String*=args->get((argc) + (1))
		//		invokevirtual org.borium.javarecompiler.Recompiler.setVisualStudio
		recompiler->setVisualStudio(args->get((argc) + (1)));
		//				stack: empty
		L00D1:
		//		goto L00EE
		goto L00EE;
		//				stack: empty
		L00D4:
		//		new java.lang.RuntimeException
		//				stack[0]: RuntimeException*=new
		//		dup
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//		new java.lang.StringBuilder
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new
		//		dup
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//		ldc "Unsupported argument "
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new
		//				stack[3]: StringBuilder*=new
		//				stack[4]: String *="Unsupported argument "
		//		invokespecial java.lang.StringBuilder.<init>
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Unsupported argument ")
		//		aload 0
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Unsupported argument ")
		//				stack[3]: JavaArray<String*>*=args
		//		iload 2
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Unsupported argument ")
		//				stack[3]: JavaArray<String*>*=args
		//				stack[4]: int=argc
		//		aaload
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=new StringBuilder("Unsupported argument ")
		//				stack[3]: String*=args->get(argc)
		//		invokevirtual java.lang.StringBuilder.append
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: StringBuilder*=(new StringBuilder("Unsupported argument "))->append(args->get(argc))
		//		invokevirtual java.lang.StringBuilder.toString
		//				stack[0]: RuntimeException*=new
		//				stack[1]: RuntimeException*=new
		//				stack[2]: String*=(new StringBuilder("Unsupported argument "))->append(args->get(argc))->toString()
		//		invokespecial java.lang.RuntimeException.<init>
		//				stack[0]: RuntimeException*=new RuntimeException((new StringBuilder("Unsupported argument "))->append(args->get(argc))->toString())
		//		athrow
		throw new RuntimeException((new StringBuilder("Unsupported argument "))->append(args->get(argc))->toString());
		//				stack: empty
		L00EE:
		//		iinc 2 2
		local2 += 2;
		//				stack: empty
		L00F1:
		//		iload 2
		//				stack[0]: int=argc
		//		aload 0
		//				stack[0]: int=argc
		//				stack[1]: JavaArray<String*>*=args
		//		arraylength
		//				stack[0]: int=argc
		//				stack[1]: int=args->length
		//		if_icmplt L0042
		if ((argc) < (args->length))
			goto L0042;
		//				stack: empty
		L00F7:
		//		aload 1
		//				stack[0]: Recompiler*=recompiler
		//		invokevirtual org.borium.javarecompiler.Recompiler.run
		recompiler->run();
		//				stack: empty
		L00FB:
		//		getstatic out Ljava/io/PrintStream;
		//				stack[0]: PrintStream*=GetStatic(System::ClassInit, System::out)
		//		ldc "Done."
		//				stack[0]: PrintStream*=GetStatic(System::ClassInit, System::out)
		//				stack[1]: String *="Done."
		//		invokevirtual java.io.PrintStream.println
		GetStatic(System::ClassInit, System::out)->println("Done.");
		//				stack: empty
		L0103:
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::addClassPath(String *classPath)
	{
		L0000:
		//		aload 0
		//				stack[0]: Recompiler*=this
		//		getfield classPaths Ljava/util/ArrayList;
		//				stack[0]: ArrayList*=this->classPaths
		//		aload 1
		//				stack[0]: ArrayList*=this->classPaths
		//				stack[1]: String*=classPath
		//		invokevirtual java.util.ArrayList.add
		//				stack[0]: bool=this->classPaths->add(classPath)
		//		pop
		this->classPaths->add(classPath);
		//				stack: empty
		L0009:
		//		return
		return;
		//				stack: empty
	}

	void Recompiler::run()
	{
		L0000:
		//		aload 0
		//				stack[0]: Recompiler*=this
		//		aload 0
		//				stack[0]: Recompiler*=this
		//				stack[1]: Recompiler*=this
		//		getfield mainClass Ljava/lang/String;
		//				stack[0]: Recompiler*=this
		//				stack[1]: String*=this->mainClass
		//		invokevirtual org.borium.javarecompiler.Recompiler.processClassFile
		//				stack[0]: ClassFile*=this->processClassFile(this->mainClass)
		//		astore 1
		classFile = this->processClassFile(this->mainClass);
		//				stack: empty
		L0009:
		//		aload 0
		//				stack[0]: Recompiler*=this
		//		getfield processedClasses Ljava/util/HashMap;
		//				stack[0]: HashMap*=this->processedClasses
		//		aload 1
		//				stack[0]: HashMap*=this->processedClasses
		//				stack[1]: ClassFile*=classFile
		//		invokevirtual org.borium.javarecompiler.classfile.ClassFile.getClassName
		//				stack[0]: HashMap*=this->processedClasses
		//				stack[1]: String*=classFile->getClassName()
		//		aload 1
		//				stack[0]: HashMap*=this->processedClasses
		//				stack[1]: String*=classFile->getClassName()
		//				stack[2]: ClassFile*=classFile
		//		invokevirtual java.util.HashMap.put
		//				stack[0]: Object*=this->processedClasses->put(classFile->getClassName(), classFile)
		//		pop
		this->processedClasses->put(classFile->getClassName(), classFile);
		//				stack: empty
		L0016:
		//		new java.util.ArrayList
		//				stack[0]: ArrayList*=new
		//		dup
		//				stack[0]: ArrayList*=new
		//				stack[1]: ArrayList*=new
		//		invokespecial java.util.ArrayList.<init>
		//				stack[0]: ArrayList*=new ArrayList()
		//		astore 2
		newClassNames = new ArrayList();
		//				stack: empty
		L001E:
		//		aload 0
		//				stack[0]: Recompiler*=this
		//		aload 2
		//				stack[0]: Recompiler*=this
		//				stack[1]: List*=newClassNames
		//		aload 1
		//				stack[0]: Recompiler*=this
		//				stack[1]: List*=newClassNames
		//				stack[2]: ClassFile*=classFile
		//		invokevirtual org.borium.javarecompiler.Recompiler.addReferencedClasses
		this->addReferencedClasses(newClassNames, classFile);
		//				stack: empty
		L0024:
		//		goto L004B
		goto L004B;
		//				stack: empty
		L0027:
		//		aload 2
		//				stack[0]: List*=newClassNames
		//		iconst 0
		//				stack[0]: List*=newClassNames
		//				stack[1]: int=0
		//		invokeinterface 145 remove count 2
