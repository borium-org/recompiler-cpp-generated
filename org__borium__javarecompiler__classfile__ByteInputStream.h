#pragma once

class ByteInputStream
{
public:
	ByteInputStream(Pointer<JavaArray<byte>> data);
	virtual void close();
	virtual int u1();
	virtual int u2();
	virtual int u4();
	virtual int s1();
	virtual int s2();
	virtual int s4();
};
