/*
	面试题13：在O(1)时间删除链表结点
	给定单向链表的头指针和某结点指针，实现函数在O(1)时间内删除指定节点。
*/

struct ListNode
{
	int value;
	ListNode* next;
	ListNode(int val):value(val),next(NULL){}	
};

class Solution
{
public:
	void deleteNode(ListNode** pListHead,ListNode* pToDelete){
		if(!pListHead||!pToDelete){
			return;
		}

		if(pToDelete->next!=NULL){
			ListNode* pNext=pToDelete->next;
			pToDelete->value=pNext->value;
			pToDelete->next=pNext->next;

			delete pNext;
			pNext=NULL;
		}else if(*pListHead==pToDelete){
			delete pToDelete;
			pToDelete=NULL;

			*pListHead=NULL;
		}else{
			ListNode* preNode=*pListHead;
			while(preNode->next!=pToDelete){
				preNode=preNode->next;
			}
			preNode->next=NULL;

			delete pToDelete;
			pToDelete=NULL;
		}
	}
	
};