#include<vector>

using namespace std;


#pragma region ��ά�����еĲ���  ��ά����
//��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
//ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
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


#pragma region ˳ʱ���ӡ���� ��ά���� ��ӡ
//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
//���磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
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


#pragma region ��������˳��ʹ����λ��ż��ǰ��
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
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



#pragma region �������ظ������� ����
//��һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
//Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{2,3,1,0,2,5,3}����ô��Ӧ������ǵ�һ���ظ�������2��
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

#pragma region �����˻����� ����

//����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����

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





#pragma region ������ֻ����һ�ε����� ���� ���� ^ ���
//һ�����������������������֮�⣬���������ֶ�������ż���Ρ���д�����ҳ�������ֻ����һ�ε����֡�
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



#pragma region ��ת�������С����  ���� O(n)
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
//����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
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


#pragma region �����г��ִ�������һ������� ���� O(n)
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
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


#pragma region �˿���˳��  ���� sort ƥ��
//LL���������ر��, ��Ϊ��ȥ����һ���˿���, ���������Ȼ��2������, 2��С��(һ����ԭ����54��^_^)...
//��������г����5����, �����Լ�������, �����ܲ��ܳ鵽˳��, ����鵽�Ļ�, ������ȥ��������Ʊ, �ٺ٣���
//������A, ����3, С��, ����, ��Ƭ5��, ��Oh My God!������˳��.....LL��������, ��������, ������\С �����Կ����κ�����, 
//����A����1, JΪ11, QΪ12, KΪ13�������5���ƾͿ��Ա�ɡ�1, 2, 3, 4, 5��(��С���ֱ���2��4), ��So Lucky!����LL����ȥ��������Ʊ���� 
//����, Ҫ����ʹ�������ģ������Ĺ���, Ȼ���������LL��������Σ� ����������˳�Ӿ����true����������false��Ϊ�˷������, �������Ϊ��С����0��

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




#pragma region ��ΪS�������������� �������� ͷβָ��
//С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
//���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
//û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!

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

#pragma region ��ΪS���������� �������� ͷβָ��
//����һ����������������һ������S���������в�����������ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
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


#pragma region ��������������� ����
//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ��
//��������鿪����, ���ַ�����:�ڹ��ϵ�һάģʽʶ����, ������Ҫ��������������������, ������ȫΪ������ʱ��, ����ܺý����
//����, ��������а�������, �Ƿ�Ӧ�ð���ĳ������, �������Աߵ��������ֲ����أ�
//���� : {6, -3, -2, 7, -15, 1, 2, 2}, ����������������Ϊ8(�ӵ�0����ʼ, ����3��Ϊֹ)��
//��һ�����飬��������������������еĺͣ���᲻�ᱻ������ס��(�������ĳ���������1)
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

#pragma region �������ڵ����ֵ ���� ���� deque
//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
//���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� 
//�������{2,3,4,2,6,2,5,1}�Ļ�������������6���� {[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
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








#pragma region �����е������ ���� �鲢����
//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
//����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007

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












#pragma region ���������������г��ֵĴ��� �������� ���� ���ֲ���
//ͳ��һ�����������������г��ֵĴ�����

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