/*
	面试题34：丑数
	把只包含因子2、3和5的数称作丑数（Ugly Number）。
	例如6、8都是丑数，但14不是，因为它包含因子7。 
	习惯上我们把1当做是第一个丑数。
	求按从小到大的顺序的第N个丑数。
*/

class Solution
{
public:
	int getUglyNumber(int index) {
		if (index <= 0) {
			return 0;
		}

		int* ugly = new int[index];
		ugly[0] = 1;

		int index2 = 0;
		int index3 = 0;
		int index5 = 0;

		for (int i = 1;i<index;i++) {
			ugly[i] = min_3(ugly[index2] * 2, ugly[index3] * 3, ugly[index5] * 5);

			if (ugly[i] == ugly[index2] * 2) {
				index2++;
			}

			if (ugly[i] == ugly[index3] * 3) {
				index3++;
			}

			if (ugly[i] == ugly[index5] * 5) {
				index5++;
			}
		}

		int ans = ugly[index - 1];
		delete[] ugly;

		return ans;
	}

private:
	int min_3(int a, int b, int c) {
		int temp = a<b ? a : b;
		return temp<c ? temp : c;
	}
};