#include "stdafx.h"
#include "java__lang__Object.h"

namespace java::lang
{

	bool Object::classInitialized = false;

	void Object::ClassInit()
	{
		if (!classInitialized)
		{
			classInitialized = true;
		}
		return;
	}

}
