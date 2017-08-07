#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//ģ��ʵ�֣�strdup
//����ԭ�ͣ�char* strdup(const char* str)
//�������ܣ������������½���λ�ô�
//strdup()���ڲ�������malloc()Ϊ���������ڴ棬����Ҫʹ�÷��ص��ַ���ʱ����Ҫ��free()�ͷ���Ӧ���ڴ�ռ䣬���������ڴ�й©��
//����ֵ������һ��ָ��,ָ��Ϊ�����ַ�������Ŀռ�;�������ռ�ʧ��,�򷵻�NULLֵ��

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
		cout << ret << endl;//��������Helo World!

	char* str1 = "Helo World!";
	char* ret1 = my_strdup(str1);
	if (ret1 != NULL)
		cout << ret1 << endl;//��������Helo World!
}