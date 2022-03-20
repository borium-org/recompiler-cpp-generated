#pragma once

#include "java__io__FileInputStream.h"

class DataInputStream : public FileInputStream
{
public:
	DataInputStream(Pointer<FileInputStream> stream);
};
