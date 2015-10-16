/*
	面试题26：复杂链表的复制
	请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，
	复制一个复杂链表。
	在复杂链表中，每个结点除了有一个pNext指针指向下一个结点之外，
	还有一个pSibling指向链表中的任意结点或者NULL。
*/

struct ComplexListNode{
    int val;
    ComplexListNode* next;
    ComplexListNode* sibling;
    ComplexListNode(int _val):val(_val),next(NULL),sibling(NULL){}
};

class Solution
{
public:
	ComplexListNode* complexListCopy(ComplexListNode* pHead){
		if(pHead==NULL){
			return NULL;
		}

		ComplexListNode* clonedHead=new ComplexListNode(pHead->val);
		clonedHead->next=pHead->next;
		pHead->next=clonedHead;

		ComplexListNode* clonedNode;
		ComplexListNode* pNode=clonedHead->next;

		while(pNode!=NULL){
			clonedNode=new ComplexListNode(pNode->val);
			clonedNode->next=pNode->next;
			pNode->next=clonedNode;
			pNode=clonedNode->next;
		}

		pNode=pHead;
		while(pNode!=NULL){
			if(pNode->sibling!=NULL){
				(pNode->next)->sibling=(pNode->sibling)->next;
			}
			pNode=(pNode->next)->next;
		}

		pNode=pHead;
		ComplexListNode* pClonedNode=clonedHead;
		while(pNode!=NULL){
			pNode->next=pClonedNode->next;
			pNode=pNode->next;

			if(pNode!=NULL){
				pClonedNode->next=pNode->next;
				pClonedNode=pClonedNode->next;
			}
		}

		return clonedHead;
	}
	
};