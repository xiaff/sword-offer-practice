/*
	面试题15：倒数第k个结点
	输入一个链表，输出该链表中倒数第k个结点。
*/

struct ListNode{
    int val;
    ListNode* next;
};

class Solution
{
public:
	ListNode* findKthToTail(ListNode* listHead,unsigned int k){
		if(listHead==NULL||k==0){
			return NULL;
		}
		ListNode* pAhead=listHead;
		ListNode* pBehind=NULL;

		for(unsigned int i=0;i<k;i++){
			if(pAhead->next!=NULL){
				pAhead=pAhead->next;
			}else{
				return NULL;
			}
		}

		pBehind=listHead;
		while(pAhead->next!=NULL){
			pAhead=pAhead->next;
			pBehind=pBehind->next;
		}
		return pBehind;
	}
	
};