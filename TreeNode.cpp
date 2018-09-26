#include<vector>
using namespace std;


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


#pragma region 二叉树的下一个结点 中序遍历
//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
#pragma endregion

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;
		TreeLinkNode* pRet = nullptr;
		if (pNode->right != nullptr)
		{
			pRet = pNode->right;
			while (pRet->left != nullptr)
			{
				pRet = pRet->left;
			}
		}
		else
		{
			if (pNode->next == nullptr)
			{
				pRet = nullptr;
			}
			else if (pNode == pNode->next->left)
			{
				pRet = pNode->next;
			}
			else if (pNode == pNode->next->right)
			{
				pRet = pNode->next;
				while (pRet->next != nullptr && pRet == pRet->next->right)
				{
					pRet = pRet->next;
				}
				pRet = pRet->next;
			}
		}
		return pRet;
	}
};



#pragma region 二叉树的镜像 递归
//操作给定的二叉树，将其变换为源二叉树的镜像。
#pragma endregion

class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
			return;
		swap(pRoot->left, pRoot->right);
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};




#pragma region 对称的二叉树 递归 对称 遍历 深度遍历
//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
#pragma endregion

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		else
			return isSymmetricalLeftAndRight(pRoot->left, pRoot->right);

	}
	bool isSymmetricalLeftAndRight(TreeNode* pLeft, TreeNode* pRight)
	{
		if (pLeft == nullptr && pRight == nullptr)
			return true;
		else if (pLeft == nullptr || pRight == nullptr || pLeft->val != pRight->val)
			return false;
		return isSymmetricalLeftAndRight(pLeft->right, pRight->left) &&
			isSymmetricalLeftAndRight(pLeft->left, pRight->right);
	}

};



#pragma region 树的子结构
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
#pragma endregion

class Solution {
public:
	bool HasSubtreeNotNull(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot2)
			return true;
		if (!pRoot1)
			return false;
		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}
		else
		{
			return HasSubtreeNotNull(pRoot1->left, pRoot2->left) && HasSubtreeNotNull(pRoot1->right, pRoot2->right);
		}
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1 || !pRoot2)
			return false;
		return HasSubtreeNotNull(pRoot1, pRoot2)
			|| HasSubtree(pRoot1->left, pRoot2)
			|| HasSubtree(pRoot1->right, pRoot2);
	}
};





#include<queue>

#pragma region 从上往下打印二叉树 深度遍历 队列 queue
//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#pragma endregion

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> vecRet;
		queue<TreeNode*> queueTreeNode;
		queueTreeNode.push(root);
		while (!queueTreeNode.empty())
		{
			TreeNode* front = queueTreeNode.front();
			queueTreeNode.pop();
			if (!front)
				continue;
			vecRet.push_back(front->val);
			queueTreeNode.push(front->left);
			queueTreeNode.push(front->right);
		}
		return vecRet;
	}
};

#pragma region 把二叉树打印成多行 深度遍历 队列 queue
//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。

#pragma endregion

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		std::queue<TreeNode*> treeQueue[2];
		int index = 0;
		vector<int> line;
		vector<vector<int>> all;
		if (pRoot == nullptr)
			return all;
		treeQueue[index].push(pRoot);
		while (!treeQueue[index].empty())
		{
			TreeNode* pTem = treeQueue[index].front();
			if (pTem->left != nullptr)
				treeQueue[index ^ 0x1].push(pTem->left);
			if (pTem->right != nullptr)
				treeQueue[index ^ 0x1].push(pTem->right);
			line.push_back(pTem->val);
			treeQueue[index].pop();
			if (treeQueue[index].empty())
			{
				index ^= 0x1;
				all.push_back(line);
				line.clear();
			}
		}
		return all;
	}
};

#pragma region 按之字形顺序打印二叉树 深度遍历 stack
//请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

#pragma endregion

#include<stack>
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		std::stack<TreeNode*> treeStack[2];
		int index = 0;
		vector<int> line;
		vector<vector<int>> all;
		if (pRoot == nullptr)
			return all;
		treeStack[index].push(pRoot);
		while (!treeStack[index].empty())
		{
			TreeNode* pTem = treeStack[index].top();
			if (!index)//奇数行顺序 偶数行逆序
			{
				if (pTem->left != nullptr)
					treeStack[1].push(pTem->left);
				if (pTem->right != nullptr)
					treeStack[1].push(pTem->right);
			}
			else
			{
				if (pTem->right != nullptr)
					treeStack[0].push(pTem->right);
				if (pTem->left != nullptr)
					treeStack[0].push(pTem->left);
			}
			line.push_back(pTem->val);
			treeStack[index].pop();
			if (treeStack[index].empty())
			{
				index ^= 0x1;
				all.push_back(line);
				line.clear();
			}
		}
		return all;
	}

};


#pragma region 二叉树的深度 深度遍历 递归
//输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
#pragma endregion

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);

		return left > right ? left + 1 : right + 1;
	}
};


#pragma region 平衡二叉树 深度遍历 递归
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
#pragma endregion


class Solution {
public:
	bool IsBalanced(TreeNode* pRoot, int &depth)
	{
		if (pRoot == NULL)
			return true;
		int leftDep = 0, rightDep = 0;
		if (IsBalanced(pRoot->left, leftDep) && IsBalanced(pRoot->right, rightDep))
		{
			if (leftDep > rightDep + 1 || rightDep > leftDep + 1)
				return false;
			else
			{
				depth = leftDep > rightDep ? leftDep + 1 : rightDep + 1;
				return true;
			}
		}
		return false;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		int dep = 0;
		return IsBalanced(pRoot, dep);
	}
};



#include<string>
#pragma region 序列化二叉树  string atoi itoa to_string
//请实现两个函数，分别用来序列化和反序列化二叉树

#pragma endregion

class Solution {
public:
	void Serialize(TreeNode *root, string &str)
	{
		if (root == NULL)
		{
			str += '#'; str += ',';
		}
		else
		{
			str += to_string(root->val);
			str += ',';
			Serialize(root->left, str);
			Serialize(root->right, str);
		}
	}
	char* Serialize(TreeNode *root) {
		if (root == NULL)
			return NULL;
		string str;
		Serialize(root, str);
		char* result = new char[str.length() + 1];
		int i = 0;
		for (; i < str.length(); ++i)
		{
			result[i] = str[i];
		}
		result[i] = '\0';
		return result;
	}


	int ReadNumber(string str, int &start)
	{
		string temp;
		int number = 0;
		while (str[start] != ',')
		{
			temp += str[start];
			start++;
		}
		start++;
		number = stoi(temp);
		return number;
	}
	TreeNode* Deserialize(string str, int &start)
	{
		if (start >= str.length())
			return NULL;
		if (str[start] == '#')
		{
			start += 2; return NULL;
		}
		else {
			int number = ReadNumber(str, start);
			TreeNode* root = new TreeNode(number);

			TreeNode* left = Deserialize(str, start);
			TreeNode* right = Deserialize(str, start);
			root->left = left;
			root->right = right;
			return root;
		}
	}
	TreeNode* Deserialize(char *str) {
		if (str == NULL)
			return NULL;
		string source = str;
		int start = 0;
		return Deserialize(source, start);
	}
};



#pragma region 重建二叉树 前序遍历 中序遍历
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#pragma endregion

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0)
		{
			return nullptr;
		}
		vector<int> temLeftPre;
		vector<int> temLeftVin;
		vector<int> temRightPre;
		vector<int> temRightVin;
		int i = 0;
		while (vin[i] != pre[0])
		{
			temLeftPre.push_back(pre[i + 1]);
			temLeftVin.push_back(vin[i]);
			i++;
		}
		for (int j = i + 1; j < (int)pre.size(); j++)
		{
			temRightPre.push_back(pre[j]);
			temRightVin.push_back(vin[j]);
		}
		TreeNode* node = new TreeNode(pre[0]);
		node->left = reConstructBinaryTree(temLeftPre, temLeftVin);
		node->right = reConstructBinaryTree(temRightPre, temRightVin);
		return node;
	}
};




#pragma region 二叉搜索树的第k个结点 二叉搜索 递归 kth
//给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
#pragma endregion

class Solution {
public:

	TreeNode* KthNodeRecursive(TreeNode* pRoot, int &k)
	{
		TreeNode* pTarget = nullptr;
		if (pRoot->left != nullptr)
			pTarget = KthNodeRecursive(pRoot->left, k);
		if (pTarget == nullptr)
		{
			k--;
			if (k == 0)
			{
				pTarget = pRoot;
			}
		}
		if (pTarget == nullptr && pRoot->right != nullptr)
			pTarget = KthNodeRecursive(pRoot->right, k);
		return pTarget;
	}
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == nullptr || k <= 0)
			return nullptr;
		return KthNodeRecursive(pRoot, k);
	}


};



#pragma region 二叉搜索树与双向链表 递归
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
#pragma endregion

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree)
			return nullptr;
		if (!pRootOfTree->left && !pRootOfTree->right)
			return pRootOfTree;
		TreeNode* leftNode = pRootOfTree;
		if (pRootOfTree->left)
		{
			leftNode = Convert(pRootOfTree->left);
			TreeNode* leftNodeEnd = leftNode;
			while (leftNodeEnd->right)
			{
				leftNodeEnd = leftNodeEnd->right;
			}
			leftNodeEnd->right = pRootOfTree;
			pRootOfTree->left = leftNodeEnd;
		}

		TreeNode* rightNode;
		if (pRootOfTree->right)
		{
			rightNode = Convert(pRootOfTree->right);
			rightNode->left = pRootOfTree;
			pRootOfTree->right = rightNode;
		}
		return leftNode;
	}
};


#pragma region 二叉搜索树的后序遍历序列  二叉搜索树 后续遍历 递归
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
#pragma endregion


class Solution {
public:
	bool VerifySquenceOfBSTIter(vector<int> sequence, int begin, int end) {
		int seg = begin;
		for (; seg < end; seg++)
		{
			if (sequence[seg] > sequence[end])
				break;
		}
		for (int latter = seg + 1; latter < end - 1; latter++)
		{
			if (sequence[latter] < sequence[end])
				return false;
		}
		bool formerBool = true;
		bool latterBool = true;
		if (begin < seg - 1)
			formerBool = VerifySquenceOfBSTIter(sequence, begin, seg - 1);
		if (seg < end - 1)
			latterBool = VerifySquenceOfBSTIter(sequence, seg, end - 1);
		return formerBool && latterBool;
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() <= 0)
			return false;
		return VerifySquenceOfBSTIter(sequence, 0, sequence.size() - 1);
	}
};

#pragma region 二叉树中和为某一值的路径
//输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
//(注意: 在返回值的list中，数组长度大的数组靠前)
#pragma endregion


class Solution {
public:
	vector<vector<int>> paths;
	void FindPath(TreeNode* root, vector <int> path, int expectNumber)
	{
		if (!root)
			return;
		if (root->val == expectNumber && !root->left && !root->right)
		{
			path.push_back(root->val);
			paths.push_back(path);
		}
		else if (root->val < expectNumber)
		{
			path.push_back(root->val);
			FindPath(root->left, path, expectNumber - root->val);
			FindPath(root->right, path, expectNumber - root->val);
		}
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<int> path;
		FindPath(root, path, expectNumber);
		return paths;
	}
};







#pragma region LeetCode 98 Validate Binary Search Tree 二叉搜索树 
//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.
class Solution {
public:
	bool isValidBST(TreeNode *root) {
		return recurBST(root, LLONG_MIN, LLONG_MAX);
	}

	bool recurBST(TreeNode* root, long long lowBound, long long highBound) {
		if (!root) return true;
		if (root->val <= lowBound || root->val >= highBound) return false;
		return recurBST(root->left, lowBound, root->val) && recurBST(root->right, root->val, highBound);
	}
};
#pragma endregion
