

using namespace std;
#pragma region 쳲��������� �ݹ� ѭ��
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
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



#pragma region ��̨�� 쳲����� �ݹ� ѭ��

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������

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


#pragma region ��̨�� 쳲����� �ݹ� ѭ��
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

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


#pragma region ���θ��� 쳲�����

//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

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