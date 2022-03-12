#pragma once

class FileInputStream
{
public:
	FileInputStream(Pointer<String> fileName);
	virtual int available();
	virtual void read(Pointer<JavaArray<byte>> data);
	virtual void close();
};
