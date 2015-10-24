/*
	面试题38：数字在排序数组中出现的次数
	统计一个数字在排序数组中出现的次数。
*/

class Solution
{
public:
	int arrayLength;
	int getNumberOfK(int *nums, int length, int k) {
		if (length <= 0 || nums == NULL) {
			return 0;
		}
		arrayLength = length;

		int firstIndex = getFistIndex(nums, k, 0, length - 1);
		int lastIndex = getLastIndex(nums, k, 0, length - 1);
		if (firstIndex != -1 && lastIndex != -1) {
			cout << "Yes!" << endl;
			return lastIndex - firstIndex + 1;
		}
		else {
			cout << "Oops! firstIndex=" << firstIndex << ", lastIndex=" << lastIndex << endl;
			return 0;
		}
	}

private:
	int getFistIndex(int* nums, int k, int start, int end) {
		if (start>end) {
			return -1;
		}

		int midIndex = (start + end) / 2;
		int midNum = nums[midIndex];

		if (midNum == k) {
			if (midIndex == 0 || (nums[midIndex - 1] != k)) {
				return midIndex;
			}
			else {
				return getFistIndex(nums, k, start, midIndex - 1);
			}
		}
		else if (midNum>k) {
			return getFistIndex(nums, k, start, midIndex - 1);
		}
		else {
			return getFistIndex(nums, k, midIndex + 1, end);
		}
	}

	int getLastIndex(int* nums, int k, int start, int end) {
		if (start>end) {
			return -1;
		}

		int midIndex = (start + end) / 2;
		int midNum = nums[midIndex];

		if (midNum == k) {
			if (midIndex == arrayLength - 1 || (nums[midIndex + 1] != k)) {
				return midIndex;
			}
			else {
				return getLastIndex(nums, k, midIndex + 1, end);
			}
		}
		else if (midNum>k) {
			return getLastIndex(nums, k, start, midIndex - 1);
		}
		else {
			return getLastIndex(nums, k, midIndex + 1, end);
		}
	}

};