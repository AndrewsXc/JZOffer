#include<vector>

using namespace std;


#pragma region 二维数组中的查找  二维数组
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
//每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
#pragma endregion

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())return false;
		//if (target < array[0][0])return false;
		int _length = array.size();
		for (int i = 0; i < _length; i++)
		{
			if (array[i].empty())continue;
			else if (target >= array[i][0])
			{
				if (target <= array[i][array[i].size() - 1])
				{
					for (int j = array[i].size() - 1; j >= 0; j--)
					{
						if (target == array[i][j])return true;
						else if (target > array[i][j])break;
					}
				}
				else {
					continue;
				}
			}
			else return false;
		}
		return false;
	}
};


#pragma region 顺时针打印矩阵 二维数组 打印
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
#pragma endregion

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int begin = 0;
		int row = matrix.size() - 1;
		int column = matrix[0].size() - 1;
		vector<int> vRet;
		while (begin < row && begin < column)
		{
			for (int i = begin; i < column; i++)
			{
				vRet.push_back(matrix[begin][i]);
			}
			for (int i = begin; i < row; i++)
			{
				vRet.push_back(matrix[i][column]);
			}
			for (int i = column; i > begin; i--)
			{
				vRet.push_back(matrix[row][i]);
			}
			for (int i = row; i > begin; i--)
			{
				vRet.push_back(matrix[i][begin]);
			}
			begin++;
			row--;
			column--;
		}
		if (begin == row)
		{
			for (int i = begin; i <= column; i++)
			{
				vRet.push_back(matrix[begin][i]);
			}
		}
		else if (begin == column)
		{
			for (int i = begin; i <= row; i++)
			{
				vRet.push_back(matrix[i][begin]);
			}
		}
		return vRet;
	}
};


#pragma region 调整数组顺序使奇数位于偶数前面
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
#pragma endregion

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> result;
		int num = array.size();
		for (int i = 0; i<num; i++)
		{
			if (array[i] % 2 == 1)
				result.push_back(array[i]);
		}
		for (int i = 0; i<num; i++)
		{
			if (array[i] % 2 == 0)
				result.push_back(array[i]);
		}
		array = result;
	}
};



#pragma region 数组中重复的数字 数组
//在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
#pragma endregion


class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0)
			return false;
		std::vector<int> compareNums(length);
		bool isDuplicated = false;
		for (int i = 0; i < length; i++)
		{
			if (!compareNums[numbers[i]])
				compareNums[numbers[i]] = 1;
			else
			{
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
};

#pragma region 构建乘积数组 数组

//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。

#pragma endregion

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> FTB(A.size());
		vector<int> BTF(A.size());
		vector<int> Ret(A.size());
		FTB[0] = 1;
		for (int i = 1; i < A.size(); i++)
		{
			FTB[i] = A[i - 1] * FTB[i - 1];
		}
		BTF[A.size() - 1] = 1;
		for (int i = A.size() - 2; i >= 0; i--)
		{
			BTF[i] = A[i + 1] * BTF[i + 1];
		}
		for (int i = 0; i < A.size(); i++)
		{
			Ret[i] = FTB[i] * BTF[i];
		}
		return Ret;
	}
};





#pragma region 数组中只出现一次的数字 数组 单次 ^ 异或
//一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
#pragma endregion

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int xor_one = 0;
		for (int i = 0; i < data.size(); i++)
		{
			xor_one = xor_one ^ data[i];
		}
		unsigned int flag = 1;
		while (!(xor_one & flag))
		{
			flag = flag << 1;
		}
		vector<int> data_partOne;
		vector<int> data_partTwo;
		for (int i = 0; i < data.size(); i++)
		{
			if (flag & data[i])
				data_partOne.push_back(data[i]);
			else
				data_partTwo.push_back(data[i]);
		}
		for (int i = 0; i < data_partOne.size(); i++)
		{
			*num1 = *num1 ^ data_partOne[i];
		}
		for (int i = 0; i < data_partTwo.size(); i++)
		{
			*num2 = *num2 ^ data_partTwo[i];
		}
	}
};



#pragma region 旋转数组的最小数字  遍历 O(n)
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
//输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
#pragma endregion

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0) {
			return 0;
		}
		int min = rotateArray[0];
		for (int i = 1; i<rotateArray.size(); i++) {
			if (rotateArray[i]<min) {
				min = rotateArray[i];
				break;
			}
		}
		return min;
	}
};


#pragma region 数组中出现次数超过一半的数字 遍历 O(n)
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
#pragma endregion

class Solution {
public:
	bool CheckMoreThanHalf(vector<int> numbers, int number)
	{
		int time = 0;
		vector<int>::iterator iter;
		for (iter = numbers.begin(); iter != numbers.end(); iter++)
		{
			if (*iter == number)
				time++;
		}
		return time > numbers.size() / 2;
	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() < 1)
			return 0;
		int time = 1;
		int number = numbers[0];
		vector<int>::iterator iter;
		for (iter = numbers.begin(); iter != numbers.end(); iter++)
		{
			if (time == 0)
			{
				number = *iter;
				time++;
			}
			else if (*iter != number)
				time--;
			else
				time++;
		}
		if (!CheckMoreThanHalf(numbers, number))
			return 0;
		return number;
	}
};


#pragma region 扑克牌顺子  排序 sort 匹配
//LL今天心情特别好, 因为他去买了一副扑克牌, 发现里面居然有2个大王, 2个小王(一副牌原本是54张^_^)...
//他随机从中抽出了5张牌, 想测测自己的手气, 看看能不能抽到顺子, 如果抽到的话, 他决定去买体育彩票, 嘿嘿！！
//“红心A, 黑桃3, 小王, 大王, 方片5”, “Oh My God!”不是顺子.....LL不高兴了, 他想了想, 决定大\小 王可以看成任何数字, 
//并且A看作1, J为11, Q为12, K为13。上面的5张牌就可以变成“1, 2, 3, 4, 5”(大小王分别看作2和4), “So Lucky!”。LL决定去买体育彩票啦。 
//现在, 要求你使用这幅牌模拟上面的过程, 然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见, 你可以认为大小王是0。

#pragma endregion

#include <algorithm>  // std::sort
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5)
			return false;
		sort(numbers.begin(), numbers.end());
		vector<int>::iterator itr = numbers.begin();
		int numberOfZero = 0;
		int numberOfGap = 0;
		int first = 0;
		int next = 0;
		while (itr != numbers.end() && *itr == 0)
		{
			++numberOfZero;
			++itr;
		}
		if (itr != numbers.end())
		{
			first = *itr;
			++itr;
		}
		while (itr != numbers.end())
		{
			next = *itr;
			if (first == next)
				return false;
			numberOfGap += next - first - 1;
			first = next;
			++itr;
		}
		return numberOfZero >= numberOfGap;
	}
};




#pragma region 和为S的连续正数序列 排序数组 头尾指针
//小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
//但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
//没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

#pragma endregion

class Solution {
public:
	inline int sumOfSequence(const int &begin, const int &end)
	{
		return ((begin + end)*(end - begin + 1)) >> 1;
	}
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> ret;
		if (sum <= 0)
			return ret;
		int begin = 1;
		int end = 2;
		while (begin < sum)
		{
			if (sumOfSequence(begin, end) > sum)
				begin++;
			else if (sumOfSequence(begin, end) < sum)
				end++;
			else
			{
				vector<int> line;
				for (int i = begin; i <= end; ++i)
				{
					line.push_back(i);
				}
				ret.push_back(line);
				begin++;
			}
		}
		return ret;
	}
};

#pragma region 和为S的两个数字 排序数组 头尾指针
//输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
#pragma endregion

class Solution {
public:
	inline int sumOfTwo(const int &begin, const int &end)
	{
		return begin + end;
	}
	inline int productOfTwo(const int &begin, const int &end)
	{
		return begin * end;
	}
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> ret;
		int indexBegin = 0;
		int indexEnd = array.size() - 1;
		int product = INT_MAX;
		while (indexBegin < indexEnd)
		{
			if (sumOfTwo(array[indexBegin], array[indexEnd]) > sum)
				--indexEnd;
			else if (sumOfTwo(array[indexBegin], array[indexEnd]) < sum)
				++indexBegin;
			else
			{
				if (productOfTwo(array[indexBegin], array[indexEnd]) < product)
				{
					ret.push_back(array[indexBegin]);
					ret.push_back(array[indexEnd]);
					break;
				}
			}
		}
		return ret;
	}
};


#pragma region 连续子数组的最大和 窗口
//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
//今天测试组开完会后, 他又发话了:在古老的一维模式识别中, 常常需要计算连续子向量的最大和, 当向量全为正数的时候, 问题很好解决。
//但是, 如果向量中包含负数, 是否应该包含某个负数, 并期望旁边的正数会弥补它呢？
//例如 : {6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
#pragma endregion

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = 0;
		int retSum = array[0];
		vector<int>::iterator iter;
		for (iter = array.begin(); iter != array.end(); iter++)
		{
			if (*iter + sum < 0)
			{
				sum = 0;
				retSum = retSum > *iter ? retSum : *iter;
			}
			else
			{
				sum += *iter;
				retSum = retSum > sum ? retSum : sum;
			}
		}
		return retSum;
	}
};

#pragma region 滑动窗口的最大值 窗口 队列 deque
//给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
//例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
//针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
#pragma endregion

#include<deque> 
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> ret;
		if (size == 0)
			return ret;
		deque<int> s;
		for (unsigned int i = 0; i < num.size(); ++i)
		{
			while (s.size() && num[s.back()] <= num[i])
				s.pop_back();
			while (s.size() && i - s.front() + 1 > size)
				s.pop_front();
			s.push_back(i);
			if (i + 1 >= size)
				ret.push_back(num[s.front()]);
		}
		return ret;
	}
};








#pragma region 数组中的逆序对 排序 归并排序
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

#pragma endregion

class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.size() < 1)
			return 0;
		int *a = new int[data.size()];
		int *copy = new int[data.size()];
		for (int i = 0; i < data.size(); ++i)
		{
			a[i] = data[i];
			copy[i] = data[i];
		}

		int ret = InversePairsCore(a, 0, data.size() - 1, copy);
		delete[]a;
		delete[]copy;
		return ret;
	}
	int InversePairsCore(int a[], int begin, int end, int tem[])
	{
		if (begin == end)
		{
			return 0;
		}
		int middle = (begin + end) >> 1;
		long long left = InversePairsCore(tem, begin, middle, a);
		long long right = InversePairsCore(tem, middle + 1, end, a);

		int i = middle;
		int j = end;
		int indexTem = end;
		long long ret = 0;
		while (i >= begin && j >= middle + 1)
		{
			if (a[i] > a[j])
			{
				tem[indexTem--] = a[i--];
				ret += j - middle;
			}
			else
			{
				tem[indexTem--] = a[j--];
			}
		}
		for (; i >= begin; --i)
		{
			tem[indexTem--] = a[i];
		}
		for (; j >= middle + 1; --j)
		{
			tem[indexTem--] = a[j];
		}
		return (left + right + ret) % 1000000007;
	}
};












#pragma region 数字在排序数组中出现的次数 排序数组 序列 二分查找
//统计一个数字在排序数组中出现的次数。

#pragma endregion


class Solution {
public:
	int GetFirstK(vector<int> data, int k, int begin, int end)
	{
		if (begin > end)
			return -1;
		int middle = (begin + end) >> 1;
		if (data[middle] < k)
			begin = middle + 1;
		else if (data[middle] > k || (middle > begin && data[middle - 1] == k))
			end = middle - 1;
		else
			return middle;
		return GetFirstK(data, k, begin, end);
	}
	int GetLastK(vector<int> data, int k, int begin, int end)
	{
		if (begin > end)
			return -1;
		int middle = (begin + end) >> 1;
		if (data[middle] > k)
			end = middle - 1;
		else if (data[middle] < k || (middle < end && data[middle + 1] == k))
			begin = middle + 1;
		else
			return middle;
		return GetLastK(data, k, begin, end);
	}
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		int number = 0;
		int first = GetFirstK(data, k, 0, data.size() - 1);
		int last = GetLastK(data, k, 0, data.size() - 1);
		if (first>-1 && last>-1)
			number = last - first + 1;
		return number;
	}
};

int main(int arcv, char *arcg[])
{
	vector<int> a = { 1,2,4,5,6,8,9 };
	vector<int> b = { 1 };
	vector<int> c = { 1,1,1,1};
	vector<int> d = { 1,2,3,3,3,3,4,5 };

	Solution sl;
	int ka =sl.GetNumberOfK(a, 2);
	int kb = sl.GetNumberOfK(b, 1);
	int kc = sl.GetNumberOfK(c, 1);
	int kd = sl.GetNumberOfK(d, 3);

	 ka = sl.GetFirstK(a, 2 , 0, a.size());
	 kb = sl.GetFirstK(b, 1, 0, b.size());
	 kc = sl.GetFirstK(c, 1, 0, c.size());
	 kd = sl.GetFirstK(c, 3, 0, c.size());
}