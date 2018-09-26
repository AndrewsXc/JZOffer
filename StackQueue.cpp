#include<stack>
#include<vector>

using namespace std;

#pragma region ������ջʵ�ֶ���  ջ ����
//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
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


#pragma region ջ��ѹ�롢�������� ջ hash map 
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
//��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�

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


#pragma region ����min������ջ ջ
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������
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