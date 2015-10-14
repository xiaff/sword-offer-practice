/*
	面试题23：从上到下打印二叉树
	从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

#include<deque>
#include<iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution
{
public:
	void printFromTopToBottom(TreeNode* root){
		if(root==NULL){
			return;
		}

		std::deque<TreeNode*> dequeTreeNode;
		dequeTreeNode.push_back(root);

		while(!dequeTreeNode.empty()){
			TreeNode* pNode=dequeTreeNode.front();
			dequeTreeNode.pop_front();

			printTreeNode(pNode);

			if(pNode->left!=NULL){
				dequeTreeNode.push_back(pNode->left);
			}
			if(pNode->right!=NULL){
				dequeTreeNode.push_back(pNode->right);
			}
		}
	}

private:
	void printTreeNode(TreeNode* pNode){
		std::cout<<pNode->val<<" ";
	}
	
};