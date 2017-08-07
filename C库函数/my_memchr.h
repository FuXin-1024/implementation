#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现memchr
//函数原型：void *memchr( const void *buf, int c, size_t count );
//函数功能：从buf所指内存区域的前count个字节查找字符c。
//返回值：如果成功，返回该字符以及其后面的字符，如果失败，则返回 NULL。

void* my_memchr(const void* str, int c, size_t count)
{
	assert(str);
	char* ret = (char*)str;

	while (count--)
	{
		if ((char)c == *ret)
			return ret;
		else
			ret++;
	}
	return NULL;
}

void my_memchrTest()
{
	char arr[] = "asdfgazxcv";
	void* ret = memchr(arr, 'd',6);
	printf("%s\n", ret);//输出结果：dfgazxcv

	char arr1[] = "asdfgazxcv";
	void* ret1 = my_memchr(arr1, 'd', 6);
	printf("%s\n", ret1);//输出结果：dfgazxcv
}