#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现：memset
//函数模型：void *memset( void *dest, int c, size_t count );
//函数功能：将dest中当前位置后面的count个字节,用 c 替换并返回 dest 。

void* my_memset(void *dest, int c, size_t count)
{
	assert(dest);
	char* tmp = (char*)dest;
	while (count--)
	{
		*tmp = (char)c;
		tmp++;
	}
	return dest;
}
void my_memsetTest()
{
	char arr[] = "asdfgh";
	memset(arr, '*', 3);//arr结果-->***fgh

	char arr1[] = "asdfgh";
	memset(arr1, '*', 3);
}