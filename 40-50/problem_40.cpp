/*
	面试题40：数组中只出现一次的数字
	一个整型数组中除了两个数字之外，其他的数字都出现了两次，
	写出程序找出这两个只出现了一次的数字，时间复杂度要求O(n),
	空间复杂度要求O(1)。
*/

class Solution
{
public:
	void findNumsAppearOnce(int* nums,int length,int& num1,int& num2){
		if(nums==NULL||length<1){
			return;
		}

		int resultXOR=0;
		for(int i=0;i<length;i++){
			resultXOR^=nums[i];
		}

		int firstBit1Index=findFirstBit1(resultXOR);
		int resXOR1=0;
		int resXOR2=0;

		for(int i=0;i<length;i++){
			if(isBit1(nums[i],firstBit1Index)){
				resXOR1^=nums[i];
			}else{
				resXOR2^=nums[i];
			}
		}
		num1=resXOR1;
		num2=resXOR2;
	}

private:
	int findFirstBit1(int num){
		int count=0;
		while(num%2==0){
			num>>=1;
			count++;
		}
		return count;
	}

	bool isBit1(int num,int bit1Index){
		num>>=bit1Index;
		return (num%2)==1;
	}
	
};