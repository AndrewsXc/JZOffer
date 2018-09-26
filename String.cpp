#include<vector>

using namespace std;

//	getline(cin, str); һ��һ�����������ո�


#pragma region �滻�ո� �ַ���

//��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

#pragma endregion

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int len = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] != ' ')
				len++;
			else
			{
				len += 3;
			}
		}
		char *pStr1 = str + len;
		char *pStr2 = str + length;
		while (pStr2 != pStr1)
		{
			if (*pStr2 == ' ')
			{
				*pStr1-- = '0';
				*pStr1-- = '2';
				*pStr1-- = '%';
			}
			else
			{
				*pStr1-- = *pStr2;
			}
			pStr2--;
		}
	}
};


#pragma region ��һ��ֻ����һ�ε��ַ�
//��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, ���û���򷵻� -1����Ҫ���ִ�Сд��.

#pragma endregion

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int hashTable[255];
		for (int i = 0; i < 256; i++)
		{
			hashTable[i] = 0;
		}
		for (int i = 0; i < str.length(); i++)
		{
			hashTable[str[i]] ++;
		}
		for (int i = 0; i < str.length(); i++)
		{
			if (hashTable[str[i]] == 1)
				return i;
		}
		return -1;
	}
};

#pragma region �ַ��������� �ַ��� �ݹ� ȫ����

//����һ���ַ���, ���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc, ���ӡ�����ַ�a, b, c�������г����������ַ���abc, acb, bac, bca, cab��cba��
#pragma endregion

class Solution {
public:
	vector<string> retStrings;
	void PermutationChar(string str, int i)
	{
		if (i == str.size() - 1)
			retStrings.push_back(str);
		else
		{
			for (int j = i; j < str.size(); j++)
			{
				if (i != j && str[i] == str[j])
					continue;
				else
				{
					swap(str[i], str[j]);
					PermutationChar(str, i + 1);
				}
			}
		}
	}
	vector<string> Permutation(string str) {
		PermutationChar(str, 0);
		return retStrings;
	}
};


#pragma region ������ʽƥ�� �ַ��� �ݹ�
//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��

#pragma endregion

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (str == nullptr || pattern == nullptr)
			return false;
		return matchCore(str, pattern);
	}
	bool matchCore(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;

		if (*str != '\0' && *pattern == '\0')
			return false;

		if (*(pattern + 1) == '*')
		{
			if (*pattern == *str || (*pattern == '.' && *str != '\0'))
				return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
			else
				return matchCore(str, pattern + 2);
		}

		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
			return matchCore(str + 1, pattern + 1);

		return false;
	}
};


#pragma region ��ʾ��ֵ���ַ��� �ַ��� ���� ��ֵ
//��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��
//����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�

#pragma endregion

class Solution {
public:
	bool isNumeric(char* string)
	{
		if (string == nullptr)
			return false;

		bool numeric = isInteger(&string);

		if (*string == '.')
		{
			++string;

			numeric = isUnsignedInteger(&string) || numeric;
		}

		if (*string == 'e' || *string == 'E')
		{
			++string;

			numeric = numeric && isInteger(&string);
		}

		return numeric && *string == '\0';
	}
	bool isUnsignedInteger(char** str)
	{
		const char* tem = *str;
		bool ret = false;
		while (**str != '\0' && **str >= '0' && **str <= '9')
		{
			++(*str);
			ret = true;
		}
		return ret;
	}
	bool isInteger(char** str)
	{
		if (**str == '+' || **str == '-')
			++(*str);
		return isUnsignedInteger(str);
	}

};



//ţ���в�Ҫ��itoa 	����		sprintf(char*, "%d", int);

#pragma region ���ַ���ת��������  atoi 
//��һ���ַ���ת����һ������(ʵ��Integer.valueOf(string)�Ĺ��ܣ�����string����������Ҫ��ʱ����0)��Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0��
#pragma endregion

class Solution {
public:
	int StrToInt(string str) {
		if (str.length() < 1)
			return 0;
		long long num = 0;
		bool isNegtive = false;
		bool isValid = true;
		int ret = 0;
		char* charStr = strdup(str.c_str());
		if (*charStr == '-')
		{
			isNegtive = true;
			++charStr;
		}
		else if (*charStr == '+')
		{
			++charStr;
		}
		while (*charStr != '\0')
		{
			if (*charStr < '0' || *charStr > '9')
			{
				isValid = false;
				return 0;
			}
			else
			{
				ret = ret * 10 + *charStr - '0';
			}
			++charStr;
		}
		if (isNegtive)
		{
			ret = -ret;
			if (ret < INT_MIN)
			{
				isValid = false;
				return 0;
			}
		}
		else
		{
			if (ret > INT_MAX)
			{
				isValid = false;
				return 0;
			}
		}
		int retInt = (int)ret;
		return retInt;
	}
};



#pragma region �ַ����е�һ�����ظ����ַ�  �ַ��� �� ��ϣ

//��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
//���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��

//�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
#pragma endregion

class Solution
{

public:
	int occurence[256] = { 0 };
	string str;
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str += ch;
		++occurence[ch];
	}

	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char ret = '#';
		for (int i = 0; i < str.size(); ++i)
		{
			if (occurence[str[i]] == 1)
			{
				ret = str[i];
				break;
			}
		}
		return ret;
	}
};


#pragma region ����ת�ַ���  �ַ��� ��ת ��ת 

//�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
//����һ���������ַ�����S���������ѭ������Kλ������������
//���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
#pragma endregion

class Solution {
public:
	void ReverseString(char *str, const int &begin, const int &end)
	{
		char  *charStart = str + begin;
		char  *charEnd = str + end;
		while (charStart < charEnd)
		{
			char tem = *charStart;
			*charStart = *charEnd;
			*charEnd = tem;
			++charStart;
			--charEnd;
		}
	}
	string LeftRotateString(string str, int n) {
		if (n < 0 || n > str.length() - 1)
			return str;
		//string.h
		//char * charStr = new char[strlen(str.c_str()) + 1];
		//strcpy(charStr, str.c_str());
		char* charStr = strdup(str.c_str());
		ReverseString(charStr, 0, n - 1);
		ReverseString(charStr, n, str.length() - 1);
		ReverseString(charStr, 0, str.length() - 1);
		string ret;
		ret = charStr;
		return ret;
	}
};


#pragma region ��ת����˳����   �ַ��� ��ת ��ת 
//ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
//ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
//���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����
//Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
#pragma endregion


class Solution {
public:
	void ReverseString(char *str, const int &begin, const int &end)
	{
		char  *charStart = str + begin;
		char  *charEnd = str + end;
		while (charStart < charEnd)
		{
			char tem = *charStart;
			*charStart = *charEnd;
			*charEnd = tem;
			++charStart;
			--charEnd;
		}
	}
	string ReverseSentence(string str) {
		int begin = 0;
		int end = 1;
		char* charStr = strdup(str.c_str());
		while (end <= str.length())
		{
			if (charStr[end] == ' ' || charStr[end] == '\0')
			{
				ReverseString(charStr, begin, end - 1);
				begin = end + 1;
			}
			++end;
		}
		ReverseString(charStr, 0, str.length() - 1);
		string ret;
		ret = charStr;
		return ret;
	}
};




#pragma region �������ų���С���� �ַ��� ���� ���� qsort sort
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
#pragma endregion

class Solution {
public:
	static int compare(const void* strNumber1, const void* strNumber2)
	{
		char* g_StrCombine1 = new char[10 * 2 + 1];
		char* g_StrCombine2 = new char[10 * 2 + 1];
		strcpy(g_StrCombine1, *(const char**)strNumber1);
		strcat(g_StrCombine1, *(const char**)strNumber2);

		strcpy(g_StrCombine2, *(const char**)strNumber2);
		strcat(g_StrCombine2, *(const char**)strNumber1);

		return strcmp(g_StrCombine1, g_StrCombine2);
	}
	string PrintMinNumber(vector<int> numbers) {
		string ret;
		if (numbers.size() < 1)
			return ret;
		char** strNumbers = (char**)malloc(sizeof(char*)* numbers.size());
		for (int i = 0; i < numbers.size(); ++i)
		{
			strNumbers[i] = new char[10 + 1];
			sprintf(strNumbers[i], "%d", numbers[i]);
		}
		qsort(strNumbers, numbers.size(), sizeof(char*), compare);

		for (int i = 0; i < numbers.size(); ++i)
			ret += strNumbers[i];

		free(strNumbers);
		return ret;
	}

};




#pragma region ȫ���� �Ź��� �绰���� ת �ַ���� 

#pragma endregion

class Solution {
public:

	string str[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> retVector;
	vector<string> letterCombinations(string digits) {
		int len = digits.length();
		if (len <= 0)
			return retVector;
		for (int i = 0; i < len; ++i)
		{
			if (digits[i] < '2' || digits[i] > '9')
			{
				return retVector;
			}
		}
		string a;
		letterCombinationsRecursive(digits, 0, len, a);
		return retVector;
	}
	void letterCombinationsRecursive(string &digits, int begin, const int &length, string beforeStr) {
		if (begin == length)
		{
			retVector.push_back(beforeStr);
		}

		for (int i = 0; i < str[digits[begin] - '2'].length(); ++i)
		{
			letterCombinationsRecursive(digits, begin + 1, length, beforeStr + str[digits[begin] - '2'][i]);
		}

	}
};
int main(int argc, char* argv[])
{
	Solution sl;
	vector<string> retVector = sl.letterCombinations("23456");
}