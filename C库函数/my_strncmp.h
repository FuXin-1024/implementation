#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现strncmp  
//函数原型：int strncmp(const char* string1,const char* string2,size_t count)

//str1>str2,返回正数；  
//str1<str2,返回负数；  
//str1=str2,返回0；  
//逐个字符比较ASCII值  

int my_strncmp(const char* str1, const char* str2, size_t count)
{
	assert(str1);
	assert(str2);
	
	while (count)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			return *str1 - *str2;
		}
		count--;
	}
	return 0;
}
void my_strncmpTest()
{
	char arr1[] = "123456";
	char arr2[] = "1243";
	cout << strncmp(arr1, arr2, 2) << endl;
	cout << strncmp(arr1, arr2, 3) << endl;	
	cout << my_strncmp(arr1, arr2, 2) << endl;
	cout << my_strncmp(arr1, arr2, 3) << endl;
}