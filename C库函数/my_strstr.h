#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//ģ��ʵ�֣�strstr����
//����ԭ�ͣ�char *strstr( const char *string, const char *strCharSet );
//�������ܣ�����һ���ַ�������һ���ַ����еĵ�һ�γ��֡�
//����ֵ����strCharSet��string���Ӵ����򷵻�strCharSet��string���״γ��ֵĵ�ַ�����strCharSet����string���Ӵ����򷵻�NULL��

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
	cout << ret << endl;//��������34xyz

	char str1[] = "1234xyz";
	char *ret1 = my_strstr(str1, "34");
	cout << ret1 << endl;
}