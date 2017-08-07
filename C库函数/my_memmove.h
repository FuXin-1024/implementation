#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现：memmove函数
//函数原型：void *memmove( void *dest, const void *src, size_t count );
//memmove的好处是可以处理dest与src发生内存重叠的情况

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	char* pdest = (char*)dest;
	const char* psrc = (const char*) src;

	if (pdest <= psrc || psrc + count <= pdest)//正常情况下，从前往后拷贝
	{
		while (count--)
			*pdest++ = *psrc++;
	}
	else
	{
		while (count--)
			*(pdest + count) = *(psrc + count);
	}

	return dest;
}

void my_memmoveTest()
{
	char arr[10] = "abcdefg";
	char arr0[10] = "abcdefg";
	char arr1[10] = { "123456" };

	my_memmove(arr + 2, arr, 4);
	cout << (arr + 2) << endl;//abcdg

	my_memmove(arr1, arr0, 4);
	cout << arr1 << endl;//abcd56
}