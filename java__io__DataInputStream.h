#pragma once

class DataInputStream : public FileInputStream
{
public:
	DataInputStream(Pointer<FileInputStream> stream);
};
