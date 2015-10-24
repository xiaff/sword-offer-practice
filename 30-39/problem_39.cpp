/*
	面试题39：二叉树的深度
	输入一棵二叉树，求该树的深度。
	从根结点到叶结点依次经过的结点（含根、叶结点）
	形成树的一条路径，最长路径的长度为树的深度。
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution
{
public:
	int treeDepth(TreeNode* pRoot){
		if(pRoot==NUll){
			return 0;
		}

		int leftDepth=treeDepth(pRoot->left);
		int rightDepth=treeDepth(pRoot->right);

		return leftDepth>rightDepth?leftDepth:rightDepth;
	}
	
	bool isBalanced(TreeNode* pRoot){
		if(pRoot==NULL){
			return true;
		}

		int c_depth=0;
		return isBalanced(pRoot,c_depth);
	}

private:
	bool isBalanced(TreeNode* pRoot,int& c_depth){
		if(pRoot==NULL){
			c_depth=0;
			return true;
		}

		int left,right;
		if(isBalanced(pRoot->left,left)
			&&isBalanced(pRoot->right,right))
		{
			int diff=right-left;
			if(diff<=1&&diff>=-1){
				c_depth=1+(left>right?left:right);
				return true;
			}
		}
		return false;
	}
};