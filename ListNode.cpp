#include<vector>
#include<stack>

using namespace std;



#pragma region 从尾到头打印链表  链表 栈 可以递归

//输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

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


#pragma region 删除链表中重复的结点 链表 图 hashmap
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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



#pragma region 链表中环的入口结点 链表 环 快慢指针
//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
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



#pragma region 两个链表的第一个公共结点 链表 公共结点 快慢指针
//输入两个链表，找出它们的第一个公共结点。
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


#pragma region 复杂链表的复制 链表 复制 copy
//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
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




#pragma region 链表中倒数第k个结点 链表 kth
//输入一个链表，输出该链表中倒数第k个结点。

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



#pragma region 合并两个排序的链表 链表 合并 单调 递增
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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



#pragma region 反转链表 
//输入一个链表，反转链表后，输出新链表的表头。

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



#pragma region 孩子们的游戏(圆圈中最后剩下的数) 循环链表 list 
//每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
//HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
//然后,他随机指定一个数m,让编号为0的小朋友开始报数。
//每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
//从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
//请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
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