#pragma once

#include "java__lang__Object.h"

namespace java::io
{
	class ByteArrayInputStream;
}

namespace java::lang
{
	class String;
}

namespace java::util
{
	template <class A> class Iterator;
}

using namespace java::io;
using namespace java::lang;
using namespace java::util;

namespace org::borium::javarecompiler::classfile
{

	class ByteInputStream : public Object
	{
	public:
		Pointer<ByteArrayInputStream> in;
		int length;

		ByteInputStream(JavaRawArray<byte> data);
		virtual int available();
		virtual void close();
		virtual double f4();
		virtual double f8();
		virtual int getPosition();
		virtual Pointer<JavaRawArray<byte>> read(int length);
		virtual int s1();
		virtual int s2();
		virtual int s4();
		virtual int u1();
		virtual int u2();
		virtual int u4();
		virtual long u8();
		virtual Pointer<String> utf8();
	};

}
