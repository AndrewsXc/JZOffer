#include<queue>
#include <functional>   // std::greater

using namespace std;

#pragma region �������е���λ��  priority_queue ���� ��С��
//��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
//������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ������ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����

#pragma endregion

class Solution {
public:
	priority_queue<int, vector<int>, less<int> > qLess;// ����� ��С��
	priority_queue<int, vector<int>, greater<int> > qGreater; //С���� �����

	void Insert(int num)
	{
		if (qLess.empty() || num < qLess.top())
			qLess.push(num);
		else
			qGreater.push(num);
		if (qLess.size() == qGreater.size() + 2)
			qGreater.push(qLess.top()), qLess.pop();
		if (qLess.size() + 1 == qGreater.size())
			qLess.push(qGreater.top()), qGreater.pop();
	}

	double GetMedian()
	{
		return qLess.size() == qGreater.size() ? (qLess.top() + qGreater.top()) / 2.0 : qLess.top();
	}

};



#pragma region ��С��K����
//����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��

#pragma endregion

#include<set>

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> retVec;
		if (input.size() < 1 || input.size() < k)
			return retVec;
		multiset<int, greater<int>> RBTree;
		for (vector<int>::iterator iter = input.begin(); iter != input.end(); iter++)
		{
			if (RBTree.size() < k)
				RBTree.insert(*iter);
			else
			{
				if (*(RBTree.begin()) >*iter)
				{
					RBTree.erase(RBTree.begin());
					RBTree.insert(*iter);
				}
			}
		}
		multiset<int, greater<int>>::iterator msiter;
		for (msiter = RBTree.begin(); msiter != RBTree.end(); msiter++)
		{
			retVec.push_back(*msiter);
		}
		return retVec;
	}
};