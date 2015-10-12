/*
	面试题17：合并两个排序的链表
	输入两个递增排顺序的链表，合并这两个链表并使合并后的链表仍是递增排序的。
*/

struct ListNode{
    int val;
    ListNode* next;
};

class Solution
{
public:
	ListNode* merge(ListNode* head1,ListNode* head2){
		if(head1==NULL){
			return head2;
		}
		if(head2==NULL){
			return head1;
		}

		ListNode* mergedHead=NULL;
		
		if(head1->val<head2->val){
			mergedHead=head1;
			mergedHead->next=merge(head1->next,head2);
		}else{
			mergedHead=head2;
			mergedHead->next=merge(head1,head2->next);
		}

		return mergedHead;
	}
	
};