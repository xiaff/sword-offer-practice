/*
	面试题24：二叉搜索树的后序遍历序列
	输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果，
	如果是则返回true，否则返回false。
	假设输入的数组的任意两个数字互不相同。
*/

class Solution
{
public:
	bool verifySquenceOfBST(int* sequence,int length){
		if(sequence==NULL||length<=0){
			return false;
		}

		int root=sequence[length-1];

		int leftIndex=0;
		for(;(leftIndex<length-1)&&(sequence[leftIndex]<root);leftIndex++){

		}

		int rightIndex=leftIndex;
		for(;rightIndex<length-1;rightIndex++){
			if(sequence[rightIndex]<root){
				return false;
			}
		}

		bool left=true;
		if(leftIndex>0){
			left=verifySquenceOfBST(sequence,leftIndex);
		}

		bool right=true;
		if(rightIndex<length-1){
			right=verifySquenceOfBST(sequence+leftIndex,rightIndex-leftIndex+1);
		}

		return left&&right;
	}
	
};