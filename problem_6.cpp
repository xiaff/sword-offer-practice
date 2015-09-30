/*
	面试题6：重建二叉树	
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
	假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
*/

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode(int value):val(value),left(NULL),right(NULL){}
};

class Solution
{
public:
	BinaryTreeNode* construct(int* preOrder,int* inOrder,int length){
		if(preOrder==NULL||inOrder==NULL||length<=0){
			return NULL;
		}

		return constructCore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);

	}
private:
	BinaryTreeNode* constructCore(
		int* startPreOrder,int* endPreOrder,
		int* startInOrder,int* endInOrder){
		int rootValue=startPreOrder[0];
		BinaryTreeNode* root=new BinaryTreeNode(rootValue);

		if(startPreOrder==endPreOrder){
			if(startInOrder==endInOrder&&*startPreOrder==*startInOrder){
				return root;
			}else{
				throw std::exception("Invalid input.")
			}
		}

		int rootInOrder=startInOrder;
		while(rootInOrder<=endInOrder&&*rootInOrder!=rootValue){
			rootInOrder++;
		}

		if(rootInOrder<=endInOrder&&*rootInOrder!=rootValue){
			throw std::exception("Invalid input.")
		}

		int leftLength=rootInOrder-startInOrder;
		int rightLength=endInOrder-rootInOrder;
		int* leftEndPreOrder=startPreOrder+leftLength;
		if(leftLength>0){
			root->left=constructCore(startPreOrder+1,leftEndPreOrder,startInOrder,rootInOrder-1);
		}
		if(rightLength>0){
			root->right=constructCore(leftEndPreOrder+1,endPreOrder,rootInOrder+1,endInOrder);
		}

		return root;
	}
};