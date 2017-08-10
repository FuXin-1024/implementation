#include<iostream>
using namespace std;

//shared_ptr->采用了引用计数，优点是功能强大，但是也有缺点，缺点是过于复杂，而且会引起循环引用。 
template<class T>
class Sharedptr
{
public:
	Sharedptr(T* ptr = NULL)
		:_ptr(ptr)
		, pcount(0)
	{
		if (_ptr != NULL)
			pcount = new int(1);
	}

	Sharedptr(const Sharedptr<T>& sp)
	{
		_ptr = sp._ptr;
		pcount = sp.pcount;
		++(*pcount);
	}

	Sharedptr<T>& operator=(const Sharedptr<T>& sp)
	{
		if (this != &sp)
		{
			if (_ptr && --(*pcount) == 0)
			{
				delete pcount;
				delete _ptr;
			}
			pcount = sp.pcount;
			_ptr = sp._ptr;
			++(*pcount);
		}

		return *this;
	}

	~Sharedptr()
	{
		if (_ptr && --(*pcount) == 0)
		{
			delete _ptr;
			delete pcount;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T Getpcount()
	{
		return *(pcount);
	}

	void Realease()
	{
		if (--(*pcount) == 0)
		{
			delete _pcount;
			delete _ptr;
		}
	}

	void Reset(T* ptr, int* pcount)
	{
		if (_ptr != ptr)
		{
			delete _ptr;
			delete _pcount;
		}

		_ptr = ptr;
		_pcount = pcount;
	}
private:
	T* _ptr;
	int* pcount;
};

void Test()
{
	Sharedptr<int> s1(new int(10));
	cout << "s1 = " << *s1 << endl;
	cout << "pcount = " << s1.Getpcount() << endl;

	Sharedptr<int> s2(s1);
	cout << "s2 = " << *s2 << endl;
	cout << "pcount = " << s2.Getpcount() << endl;

	Sharedptr<int> s3;
	s3 = s1;
	cout << "s3 = " << *s3 << endl;
	cout << "pcount = " << s3.Getpcount() << endl;
}