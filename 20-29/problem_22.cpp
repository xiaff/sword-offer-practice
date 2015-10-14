/*
	面试题22：栈的压入、弹出序列
	输入两个整数序列，第一个序列表示栈的压入顺序，
	请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
	例如序列1,2,3,4,5是某栈的压入顺序，
	序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
	但4,3,5,1,2就不可能是该压栈序列的弹出序列。
*/

#include<stack>

using namespace std;

class Solution
{
public:
	bool isPopOrder(int* push,int* pop,int length){
		if(push==NULL||pop==NULL||length<=0){
			return false;
		}

		int pushIndex=0;
		int popIndex=0;
		stack<int> stackData;

		for(popIndex=0;popIndex<length;popIndex++){
			for(;
				(stackData.empty()||stackData.top()!=pop[popIndex])
				&&(pushIndex<length);
				pushIndex++)
			{
				stackData.push(push[pushIndex]);
			}

			if(stackData.top()!=pop[popIndex]){
				return false;
			}else{
				stackData.pop();
			}
		}

		return stackData.empty();
	}
	
};