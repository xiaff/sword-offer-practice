/*
	面试题18：树的子结构
	输入两棵二叉树A和B，判断B是不是A的子结构。
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
	bool hasSubTree(TreeNode* root1,TreeNode* root2){
		bool result=false;

		if(root1!=NULL&&root2!=NULL){
			if(root1->val==root2->val){
				result=doesTree1HaveTree2(root1,root2);
			}
			if(!result){
				result=hasSubTree(root1->left,root2);
			}
			if(!result){
				result=hasSubTree(root1->right,root2);
			}
		}

		return result;
	}

private:
	bool doesTree1HaveTree2(TreeNode* root1,TreeNode* root2){
		if(root2==NULL){
			return true;
		}
		if(root1==NULL){
			return false;
		}

		if(root1->val!=root2->val){
			return false;
		}

		return doesTree1HaveTree2(root1->left,root2->left)&&doesTree1HaveTree2(root1->right,root2->right);
	}
	
};