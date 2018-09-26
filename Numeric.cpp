#include<vector>

using namespace std;




#pragma region ��������1�ĸ��� ������
//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
#pragma endregion

class Solution {
public:
	int  NumberOf1(int n) {
		int sum = 0;
		unsigned int flag = 1;
		for (int i = 0; i < 32; i++)
		{
			if (n & flag)
				sum++;
			flag = flag << 1;
		}
		return sum;
	}
};



#pragma region ��1+2+3+...+n
//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
#pragma endregion

class Temp {
public:
	static int Sum;
	static int N;
	Temp()
	{
		++N;
		Sum += N;
	}
	static int GetSum() {
		return Sum;
	}
	static void Reset()
	{
		Sum = 0;
		N = 0;
	}
};
int Temp::Sum = 0;
int Temp::N = 0;

class Solution {
public:
	friend class Temp;
	int Sum_Solution(int n) {
		Temp::Reset();
		Temp *t = new Temp[n];
		delete[]t;
		t = nullptr;
		return Temp::GetSum();
	}
};




#pragma region ���üӼ��˳����ӷ� ^ ���
//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

#pragma endregion

class Solution {
public:
	int Add(int num1, int num2)
	{
		while (num1 & num2)
		{
			int temNum1 = num1 ^ num2;
			num2 = (num1 & num2) << 1;
			num1 = temNum1;
		}
		return num1 | num2;
	}
};



#pragma region ��ֵ�������η� 
//����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
#pragma endregion

class Solution {
public:
	double Power(double base, int exponent) {
		if (base == 0 && exponent <= 0)
			return 0;
		else if (exponent < 0)
		{
			unsigned int absExponent = (unsigned int)(-exponent);
			return 1.0 / PowerUnsigned(base, absExponent);
		}
		return PowerUnsigned(base, exponent);
	}
	double PowerUnsigned(double unsignedBase, int exponent)
	{
		if (exponent == 0)
			return 1;
		else if (exponent == 1)
			return unsignedBase;
		double result = PowerUnsigned(unsignedBase, exponent >> 1);
		result *= result;
		if (exponent & 0x1)
			result *= unsignedBase;
		return result;
	}
};



#pragma region ������1���ֵĴ��� 
//���1~13��������1���ֵĴ���, �����100~1300��������1���ֵĴ�����
//Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��, ���Ƕ��ں�����������û���ˡ�
//ACMerϣ�����ǰ����, ������������ձ黯, ���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������

#pragma endregion

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 1)
			return 0;
		//12045
		int divisor = 10;
		int remainder = 0;
		vector<int> numOfOneInTenPower;
		vector<int> numOfDigit;
		vector<int> numOfRemainder;
		numOfOneInTenPower.push_back(1);
		int nCopy = n;
		int digitNumber = 0;
		while (nCopy > 0) // 5��
		{
			//���� 5 45 045 2045 12045
			remainder = n % divisor;
			numOfRemainder.push_back(remainder);
			//ÿһλ 5 4 0 2 1
			digitNumber = nCopy % 10;
			numOfDigit.push_back(digitNumber);
			nCopy /= 10;

			// 1 20 300 xxxx xxxxx xxxxx
			numOfOneInTenPower.push_back(numOfOneInTenPower[numOfOneInTenPower.size() - 1] * 10 + divisor);
			divisor *= 10;
		}
		int ret = 0;
		int powerOften = 10;
		if (numOfDigit[0] > 0)
			++ret;
		for (int i = 1; i < numOfDigit.size(); ++i)
		{
			if (numOfDigit[i] > 1)
			{
				ret += numOfDigit[i] * numOfOneInTenPower[i - 1] + powerOften;
			}
			else if (numOfDigit[i] == 1)
			{
				ret += numOfOneInTenPower[i - 1] + numOfRemainder[i - 1] + 1;
			}
			powerOften *= 10;
		}
		return ret;
	}
};





#pragma region ���� ���� ���϶��� ���¶���
//��ֻ����������2��3��5��������������Ugly Number����
//����6��8���ǳ�������14���ǣ���Ϊ������������7�� 
//ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
#pragma endregion

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index < 1)
			return 0;
		vector<int> vec;
		vec.push_back(1);
		int index2, index3, index5;
		index2 = index3 = index5 = 0;
		for (int i = 0; i < index - 1; i++)
		{
			int vecNext2 = vec[index2] * 2;
			int vecNext3 = vec[index3] * 3;
			int vecNext5 = vec[index5] * 5;
			int next = vecNext2 < vecNext3 ? vecNext2 : vecNext3;
			next = next < vecNext5 ? next : vecNext5;
			vec.push_back(next);
			while (vec[index2] * 2 <= vec[vec.size() - 1])
				index2++;
			while (vec[index3] * 3 <= vec[vec.size() - 1])
				index3++;
			while (vec[index5] * 5 <= vec[vec.size() - 1])
				index5++;

		}
		return vec[index - 1];
	}
};


#pragma region ֻ����һ�ε���  

//������ֻ������һ�� �ҳ���
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
int main(int argc, char** argv)
{
	vector<int> a = { 2,4,3,6,3,2,5,5 };
	Solution sl;
	int x = 0, y = 0;
	sl.FindNumsAppearOnce(a, &x, &y);
}
