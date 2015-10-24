/*
	面试题35：第一个只出现一次的字符
	在字符串中找出第一个只出现1次的字符，如输入“abaccdeff”，则输出b。
*/

class Solution
{
public:
	char firstNotRepeatingChar(char* pString) {
		int check[256];
		for (int i = 0;i<256;i++) {
			check[i] = 0;
		}

		char* pChar = pString;
		while (*pChar != '\0') {
			check[*pChar]++;
			pChar++;
		}

		pChar = pString;
		while (*pChar != '\0') {
			if (check[*pChar] == 1) {
				return *pChar;
			}
			pChar++;
		}

		if (*pChar == '\0') {
			return 0;
		}
	}
};