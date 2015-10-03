/*
	面试题7：用两个栈实现队列
	用两个栈实现一个队列。
	实现它的两个函数appendTail和deleteHead,
	分别完成在队列尾部插入结点和在队列头部删除结点的功能。
*/

#include<stack>

using namespace std;

template<typename T> class CQueue
{
public:
	CQueue();
	~CQueue();

	void appendTail(const T& node){
		stack1.push(node);
	}

	T deleteHead(){
		if(stack2.empty()){
			while(!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if(stack2.empty()){
			throw new exception("Queue is empty!");
		}
		
		T temp=stack2.top();
		stack2.pop();

		return T;
	}
	
private:
	stack<T> stack1;
	stack<T> stack2;
};