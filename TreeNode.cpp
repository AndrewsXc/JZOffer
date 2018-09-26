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


#pragma region ����������һ����� �������
//����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
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



#pragma region �������ľ��� �ݹ�
//���������Ķ�����������任ΪԴ�������ľ���
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




#pragma region �ԳƵĶ����� �ݹ� �Գ� ���� ��ȱ���
//��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�
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



#pragma region �����ӽṹ
//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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

#pragma region �������´�ӡ������ ��ȱ��� ���� queue
//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��

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

#pragma region �Ѷ�������ӡ�ɶ��� ��ȱ��� ���� queue
//���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�

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

#pragma region ��֮����˳���ӡ������ ��ȱ��� stack
//��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�

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
			if (!index)//������˳�� ż��������
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


#pragma region ����������� ��ȱ��� �ݹ�
//����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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


#pragma region ƽ������� ��ȱ��� �ݹ�
//����һ�ö��������жϸö������Ƿ���ƽ���������
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
#pragma region ���л�������  string atoi itoa to_string
//��ʵ�������������ֱ��������л��ͷ����л�������

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



#pragma region �ؽ������� ǰ����� �������
//����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

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




#pragma region �����������ĵ�k����� �������� �ݹ� kth
//����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4��
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



#pragma region ������������˫������ �ݹ�
//����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
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


#pragma region �����������ĺ����������  ���������� �������� �ݹ�
//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
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

#pragma region �������к�Ϊĳһֵ��·��
//����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
//(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
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







#pragma region LeetCode 98 Validate Binary Search Tree ���������� 
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
