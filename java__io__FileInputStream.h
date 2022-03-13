#pragma once

#include "java__lang__Object.h"
#include "java__lang__String.h"

class FileInputStream : public Object
{
public:
	FileInputStream(Pointer<String> fileName);
	virtual int available();
	virtual void read(Pointer<JavaArray<byte>> data);
	virtual void close();
};
