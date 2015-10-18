/*
	面试题29：数组中出现次数超过一半的数字
	数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
	例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
	由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
*/

class Solution
{
public:
	bool g_bInputInvalid=false;

	int moreThanHalfNum(int* numbers,int length){
		if(numbers==NULL||length<=0){
			g_bInputInvalid=true;
			return 0;
		}

		int result=numbers[0];
		int count=1;

		for(int i=1;i<length;i++){
			if(numbers[i]==result){
				count++;
			}else{
				if(count==0){
					result=numbers[i];
					count=1;
				}else{
					count--;
				}
			}
		}

		g_bInputInvalid=checkIsMoreThanHalf(numbers,length,result);

		return result;
	}
	
private:
	bool checkIsMoreThanHalf(int* numbers,int length,int num){
		int count=0;
		for(int i=0;i<length;i++){
			if(numbers[i]==num){
				count++;
			}
		}

		return count>(length/2);
	}

};