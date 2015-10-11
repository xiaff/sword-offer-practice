/*
	面试题16：反转链表
	定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
*/

struct ListNode{
    int val;
    ListNode* next;
};

class Solution
{
public:
	ListNode* reverseNode(ListNode* listHead){
		ListNode* reversedHead=NULL;
		ListNode* pNode=listHead;
		ListNode* pPre=NULL;

		while(pNode!=NULL){
			ListNode* pNext=pNode->next;
			if(pNext==NULL){
				reversedHead=pNode;
			}
			pNode->next=pPre;
			pPre=pNode;
			pNode=pNext;
		}
		return reversedHead;
	}
	
};