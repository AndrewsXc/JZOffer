#include<vector>

using namespace std;




#pragma region 二进制中1的个数 二进制
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
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



#pragma region 求1+2+3+...+n
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
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




#pragma region 不用加减乘除做加法 ^ 异或
//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

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



#pragma region 数值的整数次方 
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
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



#pragma region 整数中1出现的次数 
//求出1~13的整数中1出现的次数, 并算出100~1300的整数中1出现的次数？
//为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次, 但是对于后面问题他就没辙了。
//ACMer希望你们帮帮他, 并把问题更加普遍化, 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。

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
		while (nCopy > 0) // 5次
		{
			//余数 5 45 045 2045 12045
			remainder = n % divisor;
			numOfRemainder.push_back(remainder);
			//每一位 5 4 0 2 1
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





#pragma region 丑数 数组 自上而下 自下而上
//把只包含质因子2、3和5的数称作丑数（Ugly Number）。
//例如6、8都是丑数，但14不是，因为它包含质因子7。 
//习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
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


#pragma region 只出现一次的数  

//两个数只出现了一次 找出来
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
