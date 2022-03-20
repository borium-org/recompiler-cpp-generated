#pragma once

namespace org::borium::javarecompiler::classfile::constants
{

	class ConstantPool: public Object
	{
	public:
		JavaArray<Constant*>* constants;

		ConstantPool();
		virtual void dump(IndentedOutputStream *stream);
		virtual Constant* get(int index);
		virtual Constant* get(int index, Class *clazz);
		virtual String* getString(int index);
		virtual void read(ByteInputStream *in);
		virtual void verify(int majorVersion, int minorVersion);
	};

}
