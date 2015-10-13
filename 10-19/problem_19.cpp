/*
	面试题19：二叉树的镜像
	操作给定的二叉树，将其变换为源二叉树的镜像。
*/

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
	void mirrorTree(TreeNode* root){
		if(root==NULL){
			return;
		}

		if(root->left==NULL&&root->right==NULL){
			return;
		}

		TreeNode* temp=root->left;
		root->left=root->right;
		root->right=temp;

		if(root->left!=NULL){
			mirrorTree(root->left);
		}
		if(root->right!=NULL){
			mirrorTree(root->right);
		}
	}
	
};