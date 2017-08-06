#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现strcat函数
//函数原型char* stract(char* dest,const *src)

char* my_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ret = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest++ = *src++;
	}

	return ret;
}

void my_strcatTest()
{
	char dest[50] = { 0 };
	/*strcat(dest, "123456789");
	strcat(dest, "asd");*/
	my_strcat(dest, "123456789");
	my_strcat(dest, "asd");
}