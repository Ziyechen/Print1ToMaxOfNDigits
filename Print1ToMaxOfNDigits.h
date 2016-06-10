#pragma once

#include <assert.h>
#include <string.h>

//输入数字n，按顺序打印从1到最大的n位十进制数。
//比如输入3，打印出1、2、3...到999

//在字符串上模拟数字加1
bool Increment(char *str)
{
	assert(str);

	bool isOverFlow = false;//溢出返回true
	int size = strlen(str);//字符串长度
	int takeOver = 0;//进位

	for (int i = size - 1; i >= 0; i--)
	{
		int sum = str[i] - '0' + takeOver;

		//如果是最低位
		if (i == size - 1)
			sum++;

		//如果sum大于10，就产生进位
		if (sum >= 10)
		{
			//如果i是最高位，溢出
			if (i == 0)
				isOverFlow = true;
			else
			{
				sum -= 10;
				takeOver = 1;
				str[i] = sum + '0';
			}
		}
		else
		{
			str[i] = sum + '0';
			break;
		}
	}

	return isOverFlow;
}

//打印数字
//按阅读习惯打印，如果不过n位，前面补0，但0不打印
void Print(char *str)
{
	assert(str);

	bool isBeginning0 = true;
	int size = strlen(str);

	for (int i = 0; i < size; i++)
	{
		if (isBeginning0 && str[i] != '0')
			isBeginning0 = false;
		
		if (!isBeginning0)
			printf("%c", str[i]);
	}

	printf("\t");
}

void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		Print(number);
	}

	printf("\n");
	delete[] number;
}
