#ifndef JAVA__LANG__OBJECT
#define JAVA__LANG__OBJECT

// We allocate stuff in this header code so let's set up new debugging right here
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

namespace java::lang
{
	class Object
	{
		// https://stackoverflow.com/questions/3736350/how-to-declare-a-template-class-as-a-friend-in-c
		template<class T> friend class Pointer;
		template<class T> friend class JavaArray;
	public:
		Object()
		{
			usageCounter = 0;
			TRACE("Object::Object(%p)\n", this);
		}
		virtual ~Object()
		{
			ASSERT(usageCounter == 0);
			TRACE("Object::~Object(%p)\n", this);
		}
		//static void ClassInit();
		//virtual int hashCode();
		//virtual bool equals(Object *other);
	private:
		int usageCounter;
	};

	template<class T>
	class Pointer
	{
	public:
		Pointer()
		{
			pointer = nullptr;
			TRACE("Pointer::ctor(%p): pointer = %p\n", this, pointer);
		}
		Pointer(T* data)
		{
			pointer = nullptr;
			TRACE("Pointer::Pointer(%p): pointer = %p\n", this, pointer);
			assign(data);
		}
		Pointer(Pointer<T>& other)
		{
			pointer = nullptr;
			assign((T*)other.pointer);
		}
		void operator = (Pointer<T>& other)
		{
			pointer = nullptr;
			assign((T*)other.pointer);
		}
		~Pointer()
		{
			TRACE("Pointer::dtor(%p): pointer = %p\n", this, pointer);
			assign(nullptr);
		}
		Pointer<T>& operator [] (int index)
		{
			TRACE("Object %p Type: %s\n", this, typeid(*pointer).name());
			ASSERT(strncmp(typeid(*pointer).name(), "class java::lang::JavaArray<", 28) == 0);
			JavaArray<T>* array = (JavaArray<T>*)pointer;
			return array->data[index];
		}
		void operator = (Object* object)
		{
			//if (pointer)
			//	TRACE("Object %p %s Type: %s\n", this, typeid(this).name(), typeid(*pointer).name());
			//else
			//	TRACE("Object %p %s Type: nullptr\n", this, typeid(this).name());
			assign((T*)object);
		}
	private:
		void assign(T* data)
		{
			if (pointer != nullptr)
			{
				pointer->usageCounter--;
				TRACE("Pointer::assign(%p): decrement pointer = %p value = %d\n", this, pointer, pointer->usageCounter);
				ASSERT(pointer->usageCounter >= 0);
				if (pointer->usageCounter == 0)
					delete pointer;
			}
			pointer = data;
			if (pointer != nullptr)
			{
				pointer->usageCounter++;
				TRACE("Pointer::assign(%p): increment pointer = %p value = %d\n", this, pointer, pointer->usageCounter);
			}
		}
		Object* pointer;
	};

	template<class T>
	class JavaArray : public Object
	{
		template<class T> friend class Pointer;
	public:
		JavaArray(int length)
		{
			this->length = length;
			data = new Pointer<T>[length];
			TRACE("JavaArray::ctor(%p) data %p\n", this, data);
		}
		~JavaArray()
		{
			TRACE("JavaArray::dtor(%p) data %p\n", this, data);
			delete[]data;
		}
		//void assignString(int index, const char *value);
		//T get(int index);
	private:
		int length;
		Pointer<T>* data;
	};

	template<class T> T GetStatic(void(*classInit)(), T field);
}

#endif
