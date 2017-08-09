#include<iostream>
#include<stdlib.h>
#include<assert.h>
using namespace std;

enum
{
	valid = 1,
	invalid = 0
};
int flag = valid;

int my_atoi(const char* str)
{
	assert(str);
	long long ret = 0;
	int symbol = 0;//用于判断符号

	//判断是否为空字符串
	if (*str == '\0')
	{
		flag = invalid;
		return 0;
	}

	//去掉空格
	while (isspace(*str))
	{
		str++;
	}

	//判断符号
	if ((*str == '-'))
	{
		symbol = -1;
		str++;
		if (((*str<'0') || (*str > '9')))
		{
			flag = invalid;
			return 0;
		}
	}
	else if (*str == '+')
	{
		str++;
	}
	else if (((*str<'0') || (*str>'9')))
	{
		flag = invalid;
		return 0;
	}

	//处理完异常，开始转换
	while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	//加上符号位
	ret *= symbol;

	//检测结果是否溢出  
	//int 0111 1111 1111 1111 1111 1111 1111 1111 正溢出  
	//     7     f    f   f     f    f    f    f  
	//    1000 0000 0000 0000 0000 0000 0000 0000 负溢出  
	//      8    0    0   0     0    0    0    0  
	if (((ret > 0x7fffffff) && (symbol == 1)) ||
		(ret < (signed int)0x80000000) && (symbol == -1))
	{
		flag = invalid;
		return 0;
	}
	//合法
	flag = valid;
	return ret;
}

//打印输出是否异常  
void PrintState()
{
	if (flag)
		printf("正常\n");
	else
		printf("异常\n");
}

void my_atoiTest()
{
	char* str1 = "   0123"; //123
	cout << atoi(str1) << endl;

	char* str2 = "   -0123";//-123
	cout << atoi(str2) << endl;

	char* str3 = "   as0123";//0
	cout << atoi(str3) << endl;

	char* str4 = "as   0123";//0
	cout << atoi(str4) << endl;

	char* str5 = "456   0123";//456
	cout << atoi(str5) << endl;

	char* str6 = "";//0
	cout << atoi(str6) << endl;

	char* str7 = "121 asd";//121
	cout << atoi(str7) << endl;

	char* str8 = "asd";//0
	cout << atoi(str8) << endl;

	char* str9 = "123456789123456789123456789";//0
	cout << atoi(str8) << endl;
}