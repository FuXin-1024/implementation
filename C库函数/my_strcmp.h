#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//模拟实现strcmp  
//函数原型：int strcmp(const char* string1,const char* string2)

//str1>str2,返回正数；  
//str1<str2,返回负数；  
//str1=str2,返回0；  
//逐个字符比较ASCII值  

int my_strcmp(const char* string1, const char* string2)
{
	assert(string1);
	assert(string2);
	while (*string1 == *string2)
	{
		if (*string1 == '\0')
			return 0;
		string1++;
		string2++;
	}
	if (*string1 > *string2)
		return 1;
	else
		return -1;
}
void my_strcmpTest()
{
	char arr1[] = "12";
	char arr2[] = "34";

	cout << my_strcmp(arr1, arr2) << endl;
}