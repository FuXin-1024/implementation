#include<iostream>
using namespace std;

//scopedptr中对拷贝构造函数和赋值运算符的重载函数只是进行了声明，并没有去定义这两个函数，而且声明为protected或者是private，这是防止别人在类外对这两个函数进行定义。防止拷贝，所以说scopedptr是一种简单粗暴的方式。
template<class T>
class  Scopedptr
{
public:
	Scopedptr(T* ptr = NULL)
		:_ptr(ptr)
	{}

	T* operator->()
	{
		return _ptr;
	}

	T operator*()
	{
		return *_ptr;
	}

	~Scopedptr()
	{
		delete _ptr;
		_ptr = NULL;
	}

protected:
	Scopedptr(Scopedptr<T>& sp);
	Scopedptr<T>& operator=(const Scopedptr<T>& p);
private:
	T* _ptr;
};

void SPTest()
{
	Scopedptr<int> sp(new int(10));
	cout << "sp = " << *sp << endl;
}