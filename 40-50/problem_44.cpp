/*
	面试题44：扑克牌的顺子
	从扑克牌中随机抽5张牌，判断是不是一个顺子，即这五张牌是不是连续的，
	2~10为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看成任意数字。
*/

int mLess(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

class Solution
{
public:
	bool isContinuous(int* nums, int length) {
		if (nums == NULL || length<1) {
			return false;
		}

		qsort(nums, length, sizeof(nums[0]), mLess);

		int numOfZero = 0;
		int numOfGaps = 0;

		int index = 0;
		for (;(index<length) && (nums[index] == 0);index++) {
			numOfZero++;
		}
		for (;index<length - 1;index++) {
			int diff = nums[index + 1] - nums[index] - 1;
			if (diff>0) {
				numOfGaps += diff;
			}
		}

		return (numOfZero >= numOfGaps);
	}
};