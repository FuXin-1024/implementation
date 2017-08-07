#pragma warning(disable:4996)
#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//ģ��ʵ�֣�memmove����
//����ԭ�ͣ�void *memmove( void *dest, const void *src, size_t count );
//memmove�ĺô��ǿ��Դ���dest��src�����ڴ��ص������

void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest);
	assert(src);
	char* pdest = (char*)dest;
	const char* psrc = (const char*) src;

	if (pdest <= psrc || psrc + count <= pdest)//��������£���ǰ���󿽱�
	{
		while (count--)
			*pdest++ = *psrc++;
	}
	else
	{
		while (count--)
			*(pdest + count) = *(psrc + count);
	}

	return dest;
}

void my_memmoveTest()
{
	char arr[10] = "abcdefg";
	char arr0[10] = "abcdefg";
	char arr1[10] = { "123456" };

	my_memmove(arr + 2, arr, 4);
	cout << (arr + 2) << endl;//abcdg

	my_memmove(arr1, arr0, 4);
	cout << arr1 << endl;//abcd56
}