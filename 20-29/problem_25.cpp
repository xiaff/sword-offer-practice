/*
	面试题25：二叉树中和为某一值的路径
	输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
	路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

#include<vector>
#include<iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _val) :val(_val), left(NULL), right(NULL) {}
};

class Solution
{
public:
	void findPath(TreeNode* pRoot, int expectedSum) {
		if (pRoot == NULL) {
			return;
		}
		std::vector<int> vectorPath;
		int currentSum = 0;
		findPath(pRoot, expectedSum, vectorPath, currentSum);

	}

private:
	void findPath(
		TreeNode* pRoot,
		int expectedSum,
		std::vector<int>& vectorPath,
		int& currentSum)
	{
		int val = pRoot->val;
		currentSum += val;
		vectorPath.push_back(val);

		bool isLeaf = (pRoot->left == NULL) && (pRoot->right == NULL);

		if (isLeaf && (currentSum == expectedSum)) {
			printPath(vectorPath);
		}
		else {
			if (pRoot->left != NULL) {
				findPath(pRoot->left, expectedSum, vectorPath, currentSum);
			}
			if (pRoot->right != NULL) {
				findPath(pRoot->right, expectedSum, vectorPath, currentSum);
			}
		}

		currentSum -= val;
		vectorPath.pop_back();
	}

	void printPath(std::vector<int> vectorPath) {
		for (auto val : vectorPath) {
			std::cout << val << " ";
		}
		std::cout << endl;
	}

};