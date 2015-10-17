/*
	面试题27：二叉搜索树与双向链表
	输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
	要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode* convert(TreeNode* pRootOfTree){
		if(pRootOfTree==NULL){
			return NULL;
		}

		TreeNode* pLastNodeInList=NULL;
		convert(pRootOfTree,&pLastNodeInList);

		TreeNode* pHead=pRootOfTree;
		while((pHead!=NULL)&&(pHead->left!=NULL)){
			pHead=pHead->left;
		}

		return pHead;
	}

private:
	void convert(TreeNode* pCurrent,TreeNode** pLastNodeInList){
		if(pCurrent==NULL){
			return;
		}

		if(pCurrent->left!=NULL){
			convert(pCurrent->left,pLastNodeInList);
		}

		pCurrent->left=*pLastNodeInList;
		if(*pLastNodeInList!=NULL){
			(*pLastNodeInList)->right=pCurrent;
		}

		*pLastNodeInList=pCurrent;

		if(pCurrent->right!=NULL){
			convert(pCurrent->right,pLastNodeInList);
		}

	}
	
};
