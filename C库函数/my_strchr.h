#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//ģ��ʵ�֣�strchr����
//����ԭ�ͣ�char* strchr(const char* string,int c);
//��  �� : ���ַ����в���ָ���ַ��ĵ�һһ������
//����ֵ������ɹ������ظ��ַ��Լ��������ַ������ʧ�ܣ��򷵻� NULL��
//��֮���Ӧ����strrchr()�������������ַ������״γ���ָ���ַ��Լ��������ַ���

char* my_strchr(const char* str, int c)
{
	assert(str);
	char* ret = (char*)str;
	while (*str && *str!=(char)c)
	{
		str++;
	}
	if ((char)c == *str)    //������*str��c��Ϊ0�������  
		return (char *)str;

	return NULL;
}
void my_strchrTest()
{
	char arr[] = "0asdfgqwqefgf";
	char* ret = strchr(arr, 'f');
	cout << ret << endl;//��������fgqwqefgf

	char arr1[] = "0asdfgqwqefgf";
	char* ret1 = my_strchr(arr1, 'f');
	cout << ret1 << endl;//��������fgqwqefgf
}