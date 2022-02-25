#ifndef JAVA__UTIL__ARRAYLIST
#define JAVA__UTIL__ARRAYLIST

#include "java__lang__Object.h"
#include "java__util__List.h"
#include "java__util__Iterator.h"

using namespace java::lang;

namespace java::util
{
	template<class T>
	class ArrayList : public Object, public List<T>
	{
	public:
		ArrayList()
		{
			allocated = 10;
			_size = 0;
			data = new Pointer<T>[allocated];
		}
		virtual ~ArrayList()
		{
			delete[] data;
		}
		virtual bool add(Pointer<T> element)
		{
			if (_size == allocated)
			{
				allocated += 10;
				Pointer<T>* newData = new Pointer<T>[allocated];
				for (int i = 0; i < _size; i++)
					newData[i] = data[i];
				delete[] data;
				data = newData;
			}
			data[_size] = element;
			_size++;
			return true;
		}
		virtual Pointer<T> remove(int index)
		{
			ASSERT(index >= 0 && index < _size);
			Pointer<T> pointer = data[index];
			for (int i = index + 1; i < _size; i++)
				data[index - 1] = data[index];
			data[_size - 1] = nullptr;
			_size--;
			return pointer;
		}
		virtual bool contains(Pointer<T> element)
		{
			for (int index = 0; index < _size; index++)
				if (data[index] == element)
					return true;
			return false;
		}
		virtual int size()
		{
			return _size;
		}
		virtual Pointer<Iterator<T>> iterator();
	private:
		int _size;
		int allocated;
		Pointer<T>* data;
	};
}

#endif
