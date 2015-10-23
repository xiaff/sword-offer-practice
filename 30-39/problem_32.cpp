/*
面试题32：从1到n整数中1出现的次数
输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。
例如输入12，从1到12这些整数中包含1的数字有1,10,11和12，一共出现了5次。
*/

#include<iostream>

class Solution
{
public:
	int numberOf1Between1AndN(int n) {
		if (n <= 0)  return 0;

		char s[100];
		sprintf_s(s, "%d", n);
		int length = strlen(s);

		return NumberOf1(s, length);
	}

private:
	int NumberOf1(char *s,int len)
	{
		if (s == NULL || *s<'0' || *s>'9' || *s == '\0') return 0;

		int first = s[0] - '0';

		if (len == 1 && first == 0) {
			return 0;
		}
		if (len == 1 && first > 0) {
			return 1;
		}

		//最高位的1的个数
		//21345: 01346-21345 中最高位的一的个数
		int numFirstDigit = 0;
		if (first > 1) {
			numFirstDigit = (int)pow(10, len - 1);
		}
		else if (first == 1) {
			numFirstDigit = atoi(s + 1) + 1;
		}

		//其他位的1的个数
		int numOtherDigit = 0;
		if (len >= 2) {
			//排列组合
			//01346-21345 中：01346-11345 + 11346-21345
			//2*（4*10^3）
			numOtherDigit = (int)pow(10, len - 2)*first*(len - 1);
		}

		int numRecursive = NumberOf1(s + 1,len-1);//递归求解的1的个数

		return numFirstDigit + numOtherDigit + numRecursive;
	}
};