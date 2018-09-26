#include<stack>
#include<vector>

using namespace std;

#pragma region 用两个栈实现队列  栈 队列
//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
#pragma endregion

class Solution
{
public:
	void push(int node) {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		stack1.push(node);
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	int pop() {
		int ret = stack1.top();
		stack1.pop();
		return ret;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};


#pragma region 栈的压入、弹出序列 栈 hash map 
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
//假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
//但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

#pragma endregion

#include<map>
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		map<int, int> vecIndex;
		for (int i = 0; i < pushV.size(); i++)
		{
			vecIndex[pushV[i]] = i;
		}
		int endIndex = -1;
		for (int i = 0; i < popV.size(); i++)
		{
			if (popV[i] == pushV[pushV.size() - 1])
				endIndex = i;
		}
		for (int i = 1; i <= endIndex; i++)
		{
			if (vecIndex[popV[i]] < vecIndex[popV[i - 1]])
				return false;
		}
		for (; endIndex < popV.size() - 1; endIndex++)
		{
			if (vecIndex[popV[endIndex]] < vecIndex[popV[endIndex + 1]])
				return false;
		}
		return endIndex >= 0 ? true : false;
	}
};


#pragma region 包含min函数的栈 栈
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
#pragma endregion


class Solution {
public:
	std::stack<int> dataStack;
	std::stack<int> minStack;
	void push(int value) {
		dataStack.push(value);
		if (!minStack.size())
			minStack.push(value);
		else if (value < minStack.top())
		{
			minStack.push(value);
		}
		else
		{
			minStack.push(minStack.top());
		}
	}
	void pop() {
		dataStack.pop();
		minStack.pop();
	}
	int top() {
		return dataStack.top();
	}
	int min() {
		return minStack.top();
	}
};