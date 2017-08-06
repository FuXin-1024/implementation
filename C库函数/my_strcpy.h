#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模式实现strcpy
//函数原型：char* strcpy(char* des,const char* src)

char* my_strcpy(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest++ = *src++)
	{
	}
	return ret;
}

void strcpyTest()
{
	char dest[10];
	strcpy(dest, "");
	my_strcpy(dest, "");
}