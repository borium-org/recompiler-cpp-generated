#pragma once

class ConstantUtf8Info : public Constant
{
public:
	virtual Pointer<String> string();
};
