/*
	面试题10:二进制中1的个数
	请实现一个函数,输入一个函数,输出该数二进制表示中1的个数。
	例如把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。
*/

class Solution
{
public:
	int numberOfOne(int number){
		int count=0;
		while(number){
			//将number中最右的1改为0
			number=(number-1)&number;
			count++;
		}
		return count;
	}
	
};