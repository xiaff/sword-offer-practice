/*
	面试题12:打印 1 到最大的 n 位数
	输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
	比如输入数字 3，则打印出 1、2、3 ··· 999。
*/

#include<iostream>

using namespace std;

class Solution
{
public:
	void printToMaxNDigits(int n){
		if(n<=0){
			return;
		}

		char* number=new char[n+1];
		number[n]='\0';

		for(int i=0;i<10;i++){
			number[0]=i+'0';
			printToMaxNDigits(number,n,0);
		}
	}

private:
	void printToMaxNDigits(char* number,int length,int index){
		if(index==length-1){
			printNumber(number,length);
			return;
		}
		index++;
		for(int i=0;i<10;i++){
			number[index]=i+'0';
			printToMaxNDigits(number,length,index);
		}
	}

	void printNumber(char* number,int length){
		int index=0;
		while((index<length-1)&&(number[index]=='0')){
			index++;
		}
		for(;index<length;index++){
			putchar(number[index]);
		}
		putchar('\n');
	}	
};