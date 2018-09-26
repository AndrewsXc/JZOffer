

using namespace std;
#pragma region 斐波那契数列 递归 循环
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
#pragma endregion


class Solution {
public:
	int Fibonacci(int n) {
		if (n<2)
			return n;
		int a = 0, b = 1, result = 0;
		for (int i = 1; i<n; i++)
		{
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};



#pragma region 跳台阶 斐波那契 递归 循环

//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

#pragma endregion

class Solution {
public:
	int jumpFloor(int number) {
		if (number < 2)
			return number;
		int j2 = 1, j1 = 1, result;
		for (int i = 1; i < number; i++)
		{
			result = j2 + j1;
			j2 = j1;
			j1 = result;
		}
		return result;
	}
};


#pragma region 跳台阶 斐波那契 递归 循环
//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

#pragma endregion

#include<math.h>

class Solution {
public:
	int jumpFloorII(int number) {
		if (number < 1)
			return 0;
		else
			return pow(2, number - 1);
	}
};


#pragma region 矩形覆盖 斐波那契

//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

#pragma endregion

class Solution {
public:
	int rectCover(int number) {
		if (number < 2)
			return number;
		int r2 = 1, r1 = 1, result;
		for (int i = 1; i < number; i++)
		{
			result = r2 + r1;
			r2 = r1;
			r1 = result;
		}
		return result;
	}
};