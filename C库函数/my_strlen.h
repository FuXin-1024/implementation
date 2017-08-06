#include<iostream>
#include<assert.h>
using namespace std;

//模拟实现strlen函数
//函数原型 unsigned int strlen( const chaar* s)

unsigned int my_strlen(const char* s)
{
	assert(s);
	int count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return count;
}

unsigned int my_strlen1(const char* s)
{
	assert(s);
	const char* p = s;
	while (*p != '\0')
		p++;
	
	return p - s;
}

unsigned int my_strlen2(const char* s)
{
	assert(s);
	if (*s == '\0')
		return 0;
	else
		return 1 + my_strlen2(s + 1);
}
void strlenTest()
{
	char* s = "12345";
	cout << my_strlen2(s) << endl;
}