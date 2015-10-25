/*
	面试题41：和为s的两个数字
	输入一个递增排序的数组和一个数字s，在数组中查找两个数，
	使得它们的和正好是s，如果有多对数字的和等于s，输出任意一对即可。
*/

class Solution
{
public:
	void findTwoNumWithSum(int* nums,int length,int sum,int& num1,int& num2){
		if(nums==NULL||length<1){
			return;
		}

		int pre=0;
		int post=length-1;
		while(pre<post){
			int currentSum=nums[pre]+nums[post];
			if(currentSum<sum){
				pre++;
			}else if(currentSum>sum){
				post--;
			}else{
				num1=nums[pre];
				num2=nums[post];
				return;
			}
		}
	}
	
};