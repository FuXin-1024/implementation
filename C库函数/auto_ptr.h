#include<iostream>
using namespace std;

//auto_ptr的本质是管理权的转移，即ap1将自己所指向的空间交给ap2来管理，析构也是由ap2来完成。

template<class T>
class Autoptr
{
public:
	Autoptr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	Autoptr(Autoptr<T>& ap)
	{
		_ptr = ap._ptr;
		ap._ptr = NULL;
	}

	Autoptr<T>& operator=(Autoptr<T>& ap)
	{
		if (this != &ap)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
		}
		
		return *this;
	}

	T* operator->()
	{
		return _ptr;
	}

	T operator*()
	{
		return *_ptr;
	}

	~Autoptr()
	{
		delete _ptr;
		_ptr = NULL;
	}

	void Reset(T* ptr = 0)
	{
		if (_ptr != ptr)
		{
			delete _ptr;
		}
		_ptr = ptr;
	}
protected:
	T* _ptr;
};

void APTest()
{
	Autoptr<int> ap1(new int(10));
	cout << *ap1 << endl;

	Autoptr<int> ap2(ap1);
	cout << *ap2 << endl;

	Autoptr<int> ap3(new int(20));
	ap3 = ap2;
	cout << *ap3 << endl;

	//cout << *ap1 << endl;

	int *pi = new int(20);
	auto_ptr<int>_auto_ptr(pi);
	cout << "_auto_ptr = " << *pi << endl;

	int *pi2 = new int(30);
	_auto_ptr.reset(pi2);
	cout << "pi->" << *pi << endl;
	cout << "pi2->" << *pi2 << endl;
}