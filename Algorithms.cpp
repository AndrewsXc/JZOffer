#include<vector>
using namespace std;

#pragma region ��������
//O(n ^ 2) O(1) �ȶ�
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



#pragma region ð������
//O(n ^ 2) O(1) �ȶ�
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
	//��¼λ�ã���ǰ����λ�ú�����������ĵط�
	int current, last = len - 1;
	while (last > 0) {
		for (i = current = 0; i < last; ++i) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				//��¼��ǰ��λ�ã����û�з�������currentֵ��forѭ����ʼ����0
				current = i;
			}
		}
		//��current = 0���Ѿ�û�п��Խ�����Ԫ���ˣ����Ѿ�������
		last = current;
	}
}





#pragma region �������� partition
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
				++small;//��һ��small�� index��ͬʱ�� smallָ��input�е�һ������input[end]��������indexָ��small���� ��һ��С��input[index]����
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




#pragma region ������ ��������
//O(nlog2n) O(1) ���ȶ�
#pragma endregion

//������
void HeapSort(int arr[], int len) {
	int i;
	//��ʼ���ѣ������һ�����ڵ㿪ʼ
	for (i = len / 2 - 1; i >= 0; --i) {
		Heapify(arr, i, len);
	}
	//�Ӷ��е�ȡ������Ԫ���ٵ�����
	for (i = len - 1; i > 0; --i) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//�����ɶ�
		Heapify(arr, 0, i);
	}
}
void Heapify(int arr[], int first, int end) {
	int father = first;
	int son = father * 2 + 1;
	while (son < end) {
		if (son + 1 < end && arr[son] < arr[son + 1]) ++son;
		//������ڵ�����ӽڵ����ʾ�������
		if (arr[father] > arr[son]) break;
		else {
			//��Ȼ�ͽ������ڵ���ӽڵ��Ԫ��
			int temp = arr[father];
			arr[father] = arr[son];
			arr[son] = temp;
			//�����ӽڵ�����һ��Ҫ�Ƚϵ�λ��
			father = son;
			son = 2 * father + 1;
		}
	}
}





#pragma region �鲢����
//O(nlog2n) O(1) �ȶ�
#pragma endregion

void Merge(int arr[], int reg[], int start, int end) {
	if (start >= end)return;
	int len = end - start, mid = (len >> 1) + start;

	//�ֳ�������
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	//Ȼ��ϲ�
	Merge(arr, reg, start1, end1);
	Merge(arr, reg, start2, end2);


	int k = start;
	//��������һһ�Ƚ�,�ĵ����е�Ԫ��С�ͷŽ�reg��������,Ȼ��λ��+1������һ������ԭ��λ�õ�Ԫ�رȽ�
	//��˷���,���԰�������������кϲ���һ�����������
	while (start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];

	//Ȼ�������Ƿ����,���arr2���е��Ѿ�ȫ�����Ž�reg������Ȼ��������ѭ��
	//�Ǿͱ�ʾarr���л��и����Ԫ��(һ������)û�зŽ�reg����,������һ�����ǽ��ŷ�
	while (start1 <= end1)
		reg[k++] = arr[start1++];

	//��һ��������һ��
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	//���Ѿ������reg���зŻ�arr������
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}

void MergeSort(int arr[], const int len) {
	//����һ��ͬ�����ȵ�����,������ʱ���
	int  *reg = new int[len];
	Merge(arr, reg, 0, len - 1);
	delete[]reg;
}




#pragma region ���ֲ���
//O(log2n)
#pragma endregion

#include<iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
	int left = 0;   //�������λ�ã���arr[0]��
	int right = n - 1;//��������һ��λ�ã���arr[n-1],�����СΪn

					  //ѭ������һ��Ҫע��
	while (left <= right)
	{
		int mid = left + ((right - left) >> 1);//�˴���mid�ļ���һ��Ҫ����whileѭ���ڲ�������mid�޷���ȷ����;���Ҵ˴�����λ�������2�������Ч�ʣ����ҿ��Է�ֹ�����
		if (arr[mid] > key)//�����м��λ�õ�������Ҫ���ҵ�������ô���Ǿ����м�������������
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)//�����м��λ�õ���С��Ҫ���ҵ�������ô���Ǿ����м�������������
		{
			left = mid + 1;
		}
		else
		{
			return mid;//�м����պ���Ҫ���ҵ����֡�
		}
	}

	//ִ��������ߵ��˴�˵��û���ҵ�Ҫ���ҵ����֡�
	return -1;
}



#pragma region ��ëƬKMP
//O(log2n)
#pragma endregion

#include <iostream>
#include <string>

using namespace std;

//�Ż��汾
/* P Ϊģʽ�����±�� 0 ��ʼ */
void GetNextval(string P, int nextval[])
{
	int p_len = P.size();
	int i = 0;   // P ���±�
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
				nextval[i] = nextval[j];  // ��Ȼ��ͬ�ͼ�����ǰ����ǰ׺
		}
		else
			j = nextval[j];
	}
}


/* P Ϊģʽ�����±�� 0 ��ʼ */
//δ�Ż� �ɼ���ģʽ������ظ��Ӵ�
void GetNext(string P, int next[])
{
	int p_len = P.size();
	int i = 0;   // P ���±�
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

/* �� S ���ҵ� P ��һ�γ��ֵ�λ�� */
int KMP(string S, string P, int next[])
{
	//δ�Ż�
	//GetNext(P, next);
	//�Ż�
	//GetNextval(P, next);

	int i = 0;  // S ���±�
	int j = 0;  // P ���±�
	int s_len = S.size();
	int p_len = P.size();

	while (i < s_len && j < p_len)
	{
		if (j == -1 || S[i] == P[j])  // P �ĵ�һ���ַ���ƥ��� S[i] == P[j]
		{
			i++;
			j++;
		}
		else
			j = next[j];  // ��ǰ�ַ�ƥ��ʧ�ܣ�������ת
	}

	if (j == p_len)  // ƥ��ɹ�
		return i - j;

	return -1;
}

int main()
{
	int next[100] = { 0 };

	cout << KMP("bbc abcdab abcdabcdabde", "abcdabd", next) << endl; // 15

	return 0;
}