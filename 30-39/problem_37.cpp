/*
	面试题37：两个链表的第一个公共结点
	输入两个链表，找出它们的第一个公共结点。
*/

struct ListNode
{    
	int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}	
};

class Solution {
public:
    ListNode* findFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        if(pHead1==NULL||pHead2==NULL){
			return NULL;
		}

		ListNode* p1=pHead1;
		ListNode* p2=pHead2;

		for(int i=0;i<3;i++){
			while(p1!=NULL&&p2!=NULL&&p1!=p2){
				p1=p1->next;
				p2=p2->next;
			}

			if(p1==NULL){
				p1=pHead2;
			}else if(p2==NULL){
				p2=pHead1;
			}else if(p1==p2){
				return p1;
			}
		}
        return NULL;
    }
};