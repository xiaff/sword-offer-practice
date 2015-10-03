/*
	面试题8：旋转数组的最小数字
	把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
	输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
	例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
*/

class Solution
{
public:
	int getMin(int* nums,int length){
		if(num==NULL||length<=0){
			throw new exception("Invalid parameters!")
		}

		int index1=0;
		int index2=length-1;
		int indexMid=0;
		while(nums[index1]>=nums[index2]){
			if(index2-index1==1){
				indexMid=index2;
				break;
			}

			indexMid=(index1+index2)/2;

			if(nums[index1]==nums[index2]
				&&nums[index1]==nums[indexMid]){
				return minInOrder(nums,index1,index2);
			}

			if(nums[index1]<=nums[indexMid]){
				index1=indexMid;
			}else if(nums[indexMid]<=nums[index2]){
				index2=indexMid;
			}
		}
		return nums[indexMid];
	}

private:
	int minInOrder(int* nums,int start,int end){
		int result=nums[start];
		for(int i=start+1;i<=end;i++){
			if(nums[i]<result){
				result=nums[i];
			}
		}
		return result;
	}	
};