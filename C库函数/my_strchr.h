#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现：strchr函数
//函数原型：char* strchr(const char* string,int c);
//功  能 : 在字符串中查找指定字符的第一一个出现
//返回值：如果成功，返回该字符以及其后面的字符，如果失败，则返回 NULL。
//与之相对应的是strrchr()函数，它查找字符串中首次出现指定字符以及其后面的字符。

char* my_strchr(const char* str, int c)
{
	assert(str);
	char* ret = (char*)str;
	while (*str && *str!=(char)c)
	{
		str++;
	}
	if ((char)c == *str)    //包含了*str和c都为0的情况。  
		return (char *)str;

	return NULL;
}
void my_strchrTest()
{
	char arr[] = "0asdfgqwqefgf";
	char* ret = strchr(arr, 'f');
	cout << ret << endl;//输出结果：fgqwqefgf

	char arr1[] = "0asdfgqwqefgf";
	char* ret1 = my_strchr(arr1, 'f');
	cout << ret1 << endl;//输出结果：fgqwqefgf
}