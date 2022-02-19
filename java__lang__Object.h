#ifndef JAVA__LANG__OBJECT
#define JAVA__LANG__OBJECT

namespace java::lang
{
	template<class T> class Pointer;

	class Object
	{
		template<class T> friend class Pointer;
	public:
		Object()
		{
			usageCounter = 0;
		}
		virtual ~Object()
		{
			ASSERT(usageCounter == 0);
		}
		//static void ClassInit();
		//virtual int hashCode();
		//virtual bool equals(Object *other);
	private:
		int usageCounter;
	};

	template<class T> T GetStatic(void(*classInit)(), T field);

	template<class T>
	class Pointer
	{
	public:
		Pointer()
		{
			pointer = nullptr;
			TRACE("Pointer::Pointer(%p): pointer = %p\n", this, pointer);
		}
		Pointer(T* data)
		{
			pointer = nullptr;
			assign(data);
		}
		~Pointer()
		{
			assign(nullptr);
		}
		void operator=(T* data)
		{
			return assign(data);
		}
		void assign(T *data)
		{
			if (pointer != nullptr)
			{
				pointer->usageCounter--;
				TRACE("Pointer::=(%p): decrement pointer = %p value = %d\n", this, pointer, pointer->usageCounter);
				ASSERT(pointer->usageCounter >= 0);
				if (pointer->usageCounter == 0)
					delete pointer;
			}
			pointer = data;
			if (pointer != nullptr)
			{
				pointer->usageCounter++;
				TRACE("Pointer::=(%p): increment pointer = %p value = %d\n", this, pointer, pointer->usageCounter);
			}
		}
	private:
		Object* pointer;
	};

	template<class T>
	class JavaArray
	{
	public:
		JavaArray(int length)
		{
			this->length = length;
			data.SetSize(length);
			T *ptr = (T*)data.GetData();
			for (int index = 0; index < length; index++)
			{
				new(ptr)Pointer<T*>();
				ptr++;
			}
		}
		//void assignString(int index, const char *value);
		//T get(int index);
	private:
		int length;
		CArray<Pointer<T>, Pointer<T>&> data;
	};
}

#endif
