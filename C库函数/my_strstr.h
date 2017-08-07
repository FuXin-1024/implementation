#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现：strstr函数
//函数原型：char *strstr( const char *string, const char *strCharSet );
//函数功能：搜索一个字符串在另一个字符串中的第一次出现。
//返回值：若strCharSet是string的子串，则返回strCharSet在string的首次出现的地址；如果strCharSet不是string的子串，则返回NULL。

char* my_strstr(const char* string, const char* str)
{
	assert(string);
	assert(str);
	char* str1 = (char*)string;
	char* str2 = (char*)str;
	char* ret = NULL;
	if (*str2 == '\0')
		return str1;
	while (*str1)
	{
		ret = str1;
		while ((*str1) && (*str2) && (*str1 == *str2))
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return ret;
		}
		str1 = ret + 1;
		str2 = (char*)str;
	}
	return NULL;
}

void my_strstrTest()
{
	char str[] = "1234xyz";
	char *ret = strstr(str, "34");
	cout << ret << endl;//输出结果：34xyz

	char str1[] = "1234xyz";
	char *ret1 = my_strstr(str1, "34");
	cout << ret1 << endl;
}