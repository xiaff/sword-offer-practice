/*
	面试题5：从尾到头打印链表
	输入一个链表的头结点，从尾到头发过来打印出每个结点的值。
*/

#include<stack>
#include<iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int value) :val(value), next(NULL) {}
};

class Solution
{
public:
	void printListReversely(ListNode* head){
		stack<ListNode*> nodesStack;
		ListNode* pNode=head;

		while(pNode!=NULL){
			nodesStack.push(pNode);
			pNode=pNode->next;
		}

		while(!nodesStack.empty()){
			pNode=nodesStack.top();
			nodesStack.pop();
			cout<<pNode->val<<"\t";
		}
	}
	
};