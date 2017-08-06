#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现strncpy函数
//函数原型 char* strncpy(char* dest,const char* src,size_t count)

char* my_strncpy(char* dest, const char* src, size_t count)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (count)
	{
		*dest++ = *src++;
		count--;
	}
	*dest = '\0';
	return ret;
}


void my_strncpyTest()
{
	char dest[10];
	//strncpy(dest, "12345", 7);
	my_strncpy(dest, "12345", 2);

}