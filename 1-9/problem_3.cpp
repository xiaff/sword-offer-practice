/*
面试题3：二维数组中的查找
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include<vector>

using namespace std;

class Solution
{
public:
	bool findInPartiallySortedMatrix(vector<vector<int>> matrix, int number) {
		int rowNumber = matrix.size();
		if (rowNumber == 0) {
			return false;
		}
		int colNumber = matrix[0].size();
		if (colNumber == 0) {
			return false;
		}

		for (int row = 0, col = colNumber - 1;row<rowNumber&&col >= 0;) {
			int current = matrix[row][col];
			if (number == current) {
				return true;
			}
			else if (number<current) {
				col--;
			}
			else {
				row++;
			}
		}
		return false;
	}
};