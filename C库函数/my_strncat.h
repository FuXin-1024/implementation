#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
using namespace std;

//ģ��ʵ��strncat����
//����ԭ��:char* strncat(char* dest,const char* src,size_t count)

char* my_strncat(char* dest, const char* src, size_t count)
{
	assert(dest);
	assert(src);

	char* ret = dest;
	while (*dest)
		dest++;
	while (count--)
	{
		*dest++ = *src++;
	}

	return ret;
}

void my_strcatTest()
{
	char dest[50] = { "qwe" };
	my_strncat(dest, "12",10);
	my_strncat(dest, "asd",2);
}