/*
	面试题21：包含min函数的栈
	定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
	在该栈中，调用min、push及pop的时间复杂度都是O(1)。	
*/

#include<stack>

using namespace std;

template <typename T>
class StackWithMin
{
public:
	void push(T data);
	void pop();
	const T& top();
	const T& min();
private:
	stack<T> dataStack;
	stack<T> minStack;
	T minData;
};

template<typename T>
void StackWithMin<T>::push(T data) {
	if (dataStack.empty()) {
		minData = data;
	}
	else if (data < minData) {
		minData = data;
	}
	dataStack.push(data);
	minStack.push(minData);	
}

template<typename T>
void StackWithMin<T>::pop() {
	if (!dataStack.empty()) {
		dataStack.pop();
		minStack.pop();
		minData = minStack.top();
	}
}

template<typename T>
const T& StackWithMin<T>::top() {
	return dataStack.top();
}

template<typename T>
const T& StackWithMin<T>::min() {
	return minStack.top();
}