/*
	面试题28：字符串的排列
	输入一个字符串，打印出该字符串中字符的所有排列。
	例如输入字符串abc,则打印出由字符a,b,c所能排列出来的
	所有字符串abc,acb,bac,bca,cab和cba。 
*/

#include<stdio.h>

class Solution
{
public:
	void permutation(char* pStr){
		if(pStr==NULL){
			return;
		}
		permutation(pStr, pStr);
	}

private:
	void permutation(char* pStr,char* pBegin){
		if(*pBegin=='\0'){
			printf("%s\n", pStr);
			return;
		}

		for(char* pCh=pBegin;*pCh!='\0';pCh++){
			char temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;

			permutation(pStr,pBegin+1);

			temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
		}
	}
	
};