/*
面试题30：最小的k个数
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

#include<vector>
#include<set>
#include<functional>

using namespace std;


class Solution
{
public:
	vector<int> getLeastNumbers(vector<int> numbers, int k) {
		vector<int> vectorLeastNums;
		if (k <= 0) {
			return vectorLeastNums;
		}

		multiset<int,greater<int>> leastNums;

		for (auto num : numbers) {
			if (leastNums.size() < k) {
				leastNums.insert(num);
			}
			else {
				auto iterMax = leastNums.begin();
				if (num < *iterMax) {
					leastNums.erase(iterMax);
					leastNums.insert(num);
				}
			}
		}


		for (auto num : leastNums) {
			vectorLeastNums.push_back(num);
		}

		return vectorLeastNums;
	}

};