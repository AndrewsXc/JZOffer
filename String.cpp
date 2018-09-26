#include<vector>

using namespace std;

//	getline(cin, str); 一行一行输入可输入空格


#pragma region 替换空格 字符串

//请实现一个函数，将一个字符串中的每个空格替换成“%20”。
//例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

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


#pragma region 第一个只出现一次的字符
//在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

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

#pragma region 字符串的排列 字符串 递归 全排列

//输入一个字符串, 按字典序打印出该字符串中字符的所有排列。例如输入字符串abc, 则打印出由字符a, b, c所能排列出来的所有字符串abc, acb, bac, bca, cab和cba。
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


#pragma region 正则表达式匹配 字符串 递归
//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

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


#pragma region 表示数值的字符串 字符串 数字 数值
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

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



//牛客中不要用itoa 	改用		sprintf(char*, "%d", int);

#pragma region 把字符串转换成整数  atoi 
//将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0。
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



#pragma region 字符流中第一个不重复的字符  字符串 流 哈希

//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
//当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

//如果当前字符流没有存在出现一次的字符，返回#字符。
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


#pragma region 左旋转字符串  字符串 翻转 反转 

//汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
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


#pragma region 翻转单词顺序列   字符串 翻转 反转 
//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
//同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
//例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
//Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
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




#pragma region 把数组排成最小的数 字符串 数组 排序 qsort sort
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
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




#pragma region 全排列 九宫格 电话号码 转 字符组合 

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