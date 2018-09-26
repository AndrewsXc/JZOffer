#include<vector>
#include<stack>

using namespace std;



#pragma region ��β��ͷ��ӡ����  ���� ջ ���Եݹ�

//����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��

#pragma endregion

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		std::stack<ListNode*> lStack;
		ListNode* pNode = head;
		while (pNode != nullptr)
		{
			lStack.push(pNode);
			pNode = pNode->next;
		}
		vector<int> ret;
		while (!lStack.empty())
		{
			ListNode *node = lStack.top();
			ret.push_back(node->val);
			lStack.pop();
		}
		return ret;
	}
};


#pragma region ɾ���������ظ��Ľ�� ���� ͼ hashmap
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
#pragma endregion

#include<map>
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		std::map<int, int> nodeMap;
		std::map<int, int>::iterator it;
		ListNode* pTem = pHead;
		while (pTem != nullptr)
		{
			it = nodeMap.find(pTem->val);
			if (it != nodeMap.end())
				(it->second)++;
			else
			{
				nodeMap.insert(std::pair<int, int>(pTem->val, 1));
			}
			pTem = pTem->next;
		}
		ListNode* pRetHead = nullptr;
		ListNode* pRet = nullptr;
		ListNode* pItr = pHead;
		while (pItr != nullptr)
		{
			it = nodeMap.find(pItr->val);
			if (it == nodeMap.end())
				break;
			else
			{
				if (it->second == 1 && pRet == nullptr)
				{
					pRet = pItr;
					pRetHead = pItr;
				}
				else if (it->second == 1 && pRet != nullptr)
				{
					pRet->next = pItr;
					pRet = pRet->next;
				}
				else if (it->second > 1 && pRet != nullptr)
				{
					pRet->next = nullptr;
				}
			}
			pItr = pItr->next;
		}
		return pRetHead;
	}
};



#pragma region �����л�����ڽ�� ���� �� ����ָ��
//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
#pragma endregion

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		ListNode* pFast = pHead;
		ListNode* pSlow = pHead;
		while (pFast != nullptr)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != nullptr)
			{
				pFast = pFast->next;
			}
			if (pSlow == pFast)
				break;
		}
		if (pFast == nullptr)
			return nullptr;
		else {
			ListNode* pNewSlow = pHead;
			while (pNewSlow != pSlow)
			{
				pNewSlow = pNewSlow->next;
				pSlow = pSlow->next;
			}
			return pNewSlow;
		}
	}
};



#pragma region ��������ĵ�һ��������� ���� ������� ����ָ��
//�������������ҳ����ǵĵ�һ��������㡣
#pragma endregion
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		unsigned int length1 = 0;
		unsigned int length2 = 0;
		ListNode* tem_pHead1_1 = pHead1;
		ListNode* tem_pHead2_1 = pHead2;
		while (tem_pHead1_1 != nullptr)
		{
			tem_pHead1_1 = tem_pHead1_1->next;
			length1++;
		}
		while (tem_pHead2_1 != nullptr)
		{
			tem_pHead2_1 = tem_pHead2_1->next;
			length2++;
		}
		ListNode* long_pHead = pHead1;
		ListNode* short_pHead = pHead2;
		int length_Diff = length1 - length2;
		if (length_Diff < 0)
		{
			long_pHead = pHead2;
			short_pHead = pHead1;
			length_Diff = -length_Diff;
		}
		while (length_Diff > 0)
		{
			long_pHead = long_pHead->next;
			length_Diff--;
		}
		while (long_pHead != short_pHead && short_pHead != nullptr && long_pHead != nullptr)
		{
			long_pHead = long_pHead->next;
			short_pHead = short_pHead->next;
		}
		ListNode* retNode = long_pHead;
		return retNode;
	}
};


#pragma region ��������ĸ��� ���� ���� copy
//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
//��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
#pragma endregion

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (!pHead) return nullptr;
		RandomListNode* pNode = pHead;
		while (pNode)
		{
			RandomListNode* temNode = new RandomListNode(pNode->label);
			temNode->next = pNode->next;
			pNode->next = temNode;
			pNode = temNode->next;
		}
		pNode = pHead;
		while (pNode)
		{
			RandomListNode* temNode = pNode->next;
			if (pNode->random)
				temNode->random = pNode->random->next;
			pNode = temNode->next;
		}
		RandomListNode* pRetHead = pHead->next;
		RandomListNode* temNode;
		pNode = pHead;
		while (pNode->next)
		{
			temNode = pNode->next;
			pNode->next = temNode->next;
			pNode = temNode;
		}
		return pRetHead;
	}
};




#pragma region �����е�����k����� ���� kth
//����һ����������������е�����k����㡣

#pragma endregion

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k <= 0)
			return nullptr;
		ListNode* pListOne = pListHead;
		ListNode* pListTwo = pListHead;
		for (int i = 0; i < k - 1; i++)
		{
			pListTwo = pListTwo->next;
			if (pListTwo == nullptr)
				return nullptr;
		}
		while (pListTwo->next != nullptr)
		{
			pListTwo = pListTwo->next;
			pListOne = pListOne->next;
		}
		return pListOne;

	}
};



#pragma region �ϲ�������������� ���� �ϲ� ���� ����
//���������������������������������ϳɺ��������Ȼ������Ҫ�ϳɺ���������㵥����������
#pragma endregion
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (!pHead1)
			return pHead2;
		else if (!pHead2)
			return pHead1;
		ListNode* pRet;
		ListNode* pRetHead;
		if (pHead1->val <= pHead2->val)
		{
			pRetHead = pRet = pHead1;
			pHead1 = pHead1->next;
		}
		else
		{
			pRetHead = pRet = pHead2;
			pHead2 = pHead2->next;
		}
		while (pHead1 || pHead2)
		{
			if (!pHead1)
			{
				pRet->next = pHead2;
				break;
			}
			else if (!pHead2)
			{
				pRet->next = pHead1;
				break;
			}
			else if (pHead1->val <= pHead2->val)
			{
				pRet->next = pHead1;
				pRet = pRet->next;
				pHead1 = pHead1->next;
			}
			else
			{
				pRet->next = pHead2;
				pRet = pRet->next;
				pHead2 = pHead2->next;
			}
		}
		return pRetHead;
	}
};



#pragma region ��ת���� 
//����һ��������ת��������������ı�ͷ��

#pragma endregion


class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead)
			return nullptr;
		ListNode* pBefore = new ListNode(pHead->val);
		while (pHead->next)
		{
			ListNode* pLatter = new ListNode(pHead->next->val);
			pLatter->next = pBefore;
			pBefore = pLatter;
			pHead = pHead->next;
		}
		return pBefore;
	}
};



#pragma region �����ǵ���Ϸ(ԲȦ�����ʣ�µ���) ѭ������ list 
//ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�
//HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��
//Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
//ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,
//��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
//������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)
#pragma endregion

#include<list>
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;
		list<int> circle;
		for (int i = 0; i < n; ++i)
			circle.push_back(i);
		list<int>::iterator itr = circle.begin();
		while (circle.size() > 1)
		{
			for (int i = 1; i < m; ++i)
			{
				++itr;
				if (itr == circle.end())
					itr = circle.begin();
			}
			list<int>::iterator next = ++itr;
			if (next == circle.end())
				next = circle.begin();
			circle.erase(--itr);
			itr = next;
		}
		return *itr;
	}
};