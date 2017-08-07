#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现：strdup
//函数原型：char* strdup(const char* str)
//函数功能：将串拷贝到新建的位置处
//strdup()在内部调用了malloc()为变量分配内存，不需要使用返回的字符串时，需要用free()释放相应的内存空间，否则会造成内存泄漏。
//返回值：返回一个指针,指向为复制字符串分配的空间;如果分配空间失败,则返回NULL值。

char* my_strdup(const char* str)
{
	if (str == NULL)
		return NULL;

	char* strat = (char*)str;
	int len = 0;
	while (*str++ != '\0')
		len++;
	char* ret = (char*)malloc(len + 1);
	
	while ((*ret++ = *strat++) != '\0')
	{}
		
	return ret - (len + 1);
}

void my_strdupTest()
{
	char* str = "Helo World!";
	char* ret = strdup(str);
	if (ret != NULL)
		cout << ret << endl;//输出结果：Helo World!

	char* str1 = "Helo World!";
	char* ret1 = my_strdup(str1);
	if (ret1 != NULL)
		cout << ret1 << endl;//输出结果：Helo World!
}