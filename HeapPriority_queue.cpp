#include<queue>
#include <functional>   // std::greater

using namespace std;

#pragma region 数据流中的中位数  priority_queue 最大堆 最小堆
//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

#pragma endregion

class Solution {
public:
	priority_queue<int, vector<int>, less<int> > qLess;// 大根堆 存小数
	priority_queue<int, vector<int>, greater<int> > qGreater; //小根堆 存大数

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



#pragma region 最小的K个数
//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

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