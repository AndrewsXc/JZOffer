#include<vector>
using namespace std;

#pragma region 插入排序
//O(n ^ 2) O(1) 稳定
#pragma endregion

void InsertSort(int arr[], int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}



#pragma region 冒泡排序
//O(n ^ 2) O(1) 稳定
#pragma endregion

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void BubbleSort(int arr[], int len) {
	int i, temp;
	//记录位置，当前所在位置和最后发生交换的地方
	int current, last = len - 1;
	while (last > 0) {
		for (i = current = 0; i < last; ++i) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				//记录当前的位置，如果没有发生交换current值即for循环初始化的0
				current = i;
			}
		}
		//若current = 0即已经没有可以交换的元素了，即已经有序了
		last = current;
	}
}





#pragma region 快速排序 partition
//O(nlog2n) O(nlog2n) 
#pragma endregion

class Solution {
public:
	int Partition(vector<int>& input, int begin, int end)
	{
		//int low = begin;
		//int high = end;

		//int pivot = input[low];
		//while (low < high)
		//{
		//	while (low < high&&pivot <= input[high])
		//		high--;
		//	input[low] = input[high];
		//	while (low < high&&pivot >= input[low])
		//		low++;
		//	input[high] = input[low];
		//}
		//input[low] = pivot;
		//return low;

		swap(input[begin], input[end]);
		int index = begin;
		int small = begin - 1;
		for (; index < end; ++index)
		{
			if (input[index] < input[end])
			{
				++small;//第一次small与 index不同时， small指向input中第一个大于input[end]的数，而index指向small后面 第一个小于input[index]的数
				if (small != index)
					swap(input[index], input[small]);
			}
		}
		++small;
		swap(input[small], input[end]);

		return small;
	}
	void QuickSort(vector<int>& input, int begin, int end)
	{
		if (begin > end)
			return;

		int index = Partition(input, begin, end);
		if (index > begin)
			QuickSort(input, begin, index - 1);
		if (index < end)
			QuickSort(input, index + 1, end);
	}
};




#pragma region 堆排序 线性数组
//O(nlog2n) O(1) 不稳定
#pragma endregion

//堆排序
void HeapSort(int arr[], int len) {
	int i;
	//初始化堆，从最后一个父节点开始
	for (i = len / 2 - 1; i >= 0; --i) {
		Heapify(arr, i, len);
	}
	//从堆中的取出最大的元素再调整堆
	for (i = len - 1; i > 0; --i) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//调整成堆
		Heapify(arr, 0, i);
	}
}
void Heapify(int arr[], int first, int end) {
	int father = first;
	int son = father * 2 + 1;
	while (son < end) {
		if (son + 1 < end && arr[son] < arr[son + 1]) ++son;
		//如果父节点大于子节点则表示调整完毕
		if (arr[father] > arr[son]) break;
		else {
			//不然就交换父节点和子节点的元素
			int temp = arr[father];
			arr[father] = arr[son];
			arr[son] = temp;
			//父和子节点变成下一个要比较的位置
			father = son;
			son = 2 * father + 1;
		}
	}
}





#pragma region 归并排序
//O(nlog2n) O(1) 稳定
#pragma endregion

void Merge(int arr[], int reg[], int start, int end) {
	if (start >= end)return;
	int len = end - start, mid = (len >> 1) + start;

	//分成两部分
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	//然后合并
	Merge(arr, reg, start1, end1);
	Merge(arr, reg, start2, end2);


	int k = start;
	//两个序列一一比较,哪的序列的元素小就放进reg序列里面,然后位置+1再与另一个序列原来位置的元素比较
	//如此反复,可以把两个有序的序列合并成一个有序的序列
	while (start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

	//然后这里是分情况,如果arr2序列的已经全部都放进reg序列了然后跳出了循环
	//那就表示arr序列还有更大的元素(一个或多个)没有放进reg序列,所以这一步就是接着放
	while (start1 <= end1)
		reg[k++] = arr[start1++];

	//这一步和上面一样
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	//把已经有序的reg序列放回arr序列中
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}

void MergeSort(int arr[], const int len) {
	//创建一个同样长度的序列,用于临时存放
	int  *reg = new int[len];
	Merge(arr, reg, 0, len - 1);
	delete[]reg;
}




#pragma region 二分查找
//O(log2n)
#pragma endregion

#include<iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
	int left = 0;   //数组的首位置，即arr[0]处
	int right = n - 1;//数组的最后一个位置，即arr[n-1],数组大小为n

					  //循环条件一定要注意
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);//此处的mid的计算一定要放在while循环内部，否则mid无法正确更新;并且此处用移位代替除以2可以提高效率，而且可以防止溢出。
		if (arr[mid] > key)//数组中间的位置得数大于要查找的数，那么我们就在中间数的左区间找
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)//数组中间的位置得数小于要查找的数，那么我们就在中间数的右区间找
		{
			left = mid + 1;
		}
		else
		{
			return mid;//中间数刚好是要查找的数字。
		}
	}

	//执行流如果走到此处说明没有找到要查找的数字。
	return -1;
}



#pragma region 看毛片KMP
//O(log2n)
#pragma endregion

#include <iostream>
#include <string>

using namespace std;

//优化版本
/* P 为模式串，下标从 0 开始 */
void GetNextval(string P, int nextval[])
{
	int p_len = P.size();
	int i = 0;   // P 的下标
	int j = -1;
	nextval[0] = -1;

	while (i < p_len - 1)
	{
		if (j == -1 || P[i] == P[j])
		{
			i++;
			j++;

			if (P[i] != P[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];  // 既然相同就继续往前找真前缀
		}
		else
			j = nextval[j];
	}
}


/* P 为模式串，下标从 0 开始 */
//未优化 可计算模式串中最长重复子串
void GetNext(string P, int next[])
{
	int p_len = P.size();
	int i = 0;   // P 的下标
	int j = -1;
	next[0] = -1;

	while (i < p_len - 1)
	{
		if (j == -1 || P[i] == P[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

/* 在 S 中找到 P 第一次出现的位置 */
int KMP(string S, string P, int next[])
{
	//未优化
	//GetNext(P, next);
	//优化
	//GetNextval(P, next);

	int i = 0;  // S 的下标
	int j = 0;  // P 的下标
	int s_len = S.size();
	int p_len = P.size();

	while (i < s_len && j < p_len)
	{
		if (j == -1 || S[i] == P[j])  // P 的第一个字符不匹配或 S[i] == P[j]
		{
			i++;
			j++;
		}
		else
			j = next[j];  // 当前字符匹配失败，进行跳转
	}

	if (j == p_len)  // 匹配成功
		return i - j;

	return -1;
}

int main()
{
	int next[100] = { 0 };

	cout << KMP("bbc abcdab abcdabcdabde", "abcdabd", next) << endl; // 15

	return 0;
}