/*
	面试题9：斐波那契数列
	现在要求输入一个整数n，请你输出斐波那契（Fibonacci）数列的第n项。  
	斐波那契数列的定义：  
	f(0)=0;f(1)=1;  
	f(n)=f(n-1)+f(n-2)。
*/

class Solution
{
public:
	long long Fibonacci(unsigned n){
		if(n==0){
			return 0;
		}
		if(n==1){
			return 1;
		}

		long long fibN_one=1;
		long long fibN_two=0;
		long long fibN=1;
		for(unsigned i=2;i<=n;i++){
			fibN=fibN_one+fibN_two;
			fibN_two=fibN_one;
			fibN_one=fibN;
		}
		return fibN;
	}
	
};