#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现memcpy
//函数原型：void *memcpy( void *dest, const void *src, size_t count );
//函数说明：memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。
//注意：source和destin所指的内存区域可能重叠，但是如果source和destin所指的内存区域重叠,
//那么这个函数并不能够确保source所在重叠区域在拷贝之前不被覆盖。而使用memmove可以用来处理重叠区域。
//函数返回指向destin的指针。

void* my_memcpy(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	void* ret = dest;
	char* pdest = (char*)dest;
	const char* psrc = (const char*)src;
	while (count--)
	{
		*pdest++ = *psrc++;
	}
	return ret;
}

void my_memcpyTest()
{
	char arr[10] = "abcdefg";
	char arr0[10] = "abcdefg";
	char arr1[10] = { 0 };

	memcpy(arr + 2, arr, 4);
	cout << (arr + 2) << endl;//abcdg

	my_memcpy(arr + 2, arr, 4);
	cout << (arr + 2) << endl;//ababg

	my_memcpy(arr1, arr0, 4);
	cout << arr1 << endl;//abcd
}