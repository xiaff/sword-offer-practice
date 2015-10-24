/*
	面试题36：数组中的逆序对
	在数组中的两个数字，如果前面一个数字大于后面的数字，
	则这两个数字组成一个逆序对。
	输入一个数组，求出这个数组中的逆序对的总数。
*/

class Solution
{
public:
	int inversePairs(int* nums, int length) {
		if (nums == NULL || length == 0) {
			return 0;
		}

		int* copyNums = new int[length];
		int count = inversePairsCore(nums, copyNums, 0, length - 1);

		delete[] copyNums;

		return count;
	}

private:
	int inversePairsCore(int* nums, int* copyNums, int start, int end) {
		if (start == end) {
			copyNums[start] = nums[start];
			return 0;
		}

		int mid = (start + end) / 2;
		int leftCount = inversePairsCore(nums, copyNums, start, mid);
		int rightCount = inversePairsCore(nums, copyNums, mid + 1, end);

		int count = 0;
		int pPre = mid;
		int pPost = end;
		int index_copy = end;

		while (pPre >= start&&pPost>mid) {
			if (nums[pPre]>nums[pPost]) {
				count += (pPost - mid);
				copyNums[index_copy] = nums[pPre];
				index_copy--;
				pPre--;
			}
			else {
				copyNums[index_copy] = nums[pPost];
				index_copy--;
				pPost--;
			}
		}

		for (;pPre >= start;pPre--) {
			copyNums[index_copy] = nums[pPre];
			index_copy--;
		}
		for (;pPost > mid;pPost--) {
			copyNums[index_copy] = nums[pPost];
			index_copy--;
		}

		for (int i = start;i <= end;i++) {
			nums[i] = copyNums[i];
		}
		
		return count + leftCount + rightCount;
	}

};