#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现：strrchr函数
//函数原型：char* strrchr(const char* string,int c);
//功  能 : 在串中查找指定字符的最后一个出现
//返回值：如果成功，返回该字符以及其后面的字符，如果失败，则返回 NULL。
//与之相对应的是strchr()函数，它查找字符串中首次出现指定字符以及其后面的字符。

//方法一，从头往后找
char* my_strrchr(const char* str, int c)
{
	assert(str);
	char* ret = NULL;
	while (*str)
	{
		if (*str == (char)c)//如果存在，ret保存地址
			ret = (char *)str;//强制转换指针类型，赋给ret 
		str++;
	}
	if ((char)c == *str) //考虑str第一个字符为'\0'的情况  
		ret = (char *)str; //强制转换指针类型，赋给ret  

	return ret;
}

// 方法二：从后往前找
char* my_strrchr1(const char* str, int c)
{
	assert(str);
	char* ret = (char*)str;

	while (*str)//指向原str字符串最后一位 
		++str;
	while (*str != (char)c && (str >= ret))
		--str;

	if (str >= ret)
		return (char*)str;
	return NULL;
}

void my_strrchrTest()
{
	char arr[] = "/0asdfgazxcv";
	char* ret = strrchr(arr, 'a');
	cout << ret << endl;//输出结果：azxcv

	char arr1[] = "asdfgazxcv";
	char* ret1 = my_strrchr(arr1, 'a');
	cout << ret1 << endl;//输出结果：azxcv

	char arr2[] = "0asdfgazxcv";
	char* ret2 = my_strrchr1(arr2, 'a');
	cout << ret2 << endl;//输出结果：azxcv
}