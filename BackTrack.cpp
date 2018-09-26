#include<vector>

using namespace std;


#pragma region �����е�·�� ���� ��ά���� ����
//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ�
//���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

#pragma endregion

class Solution {
public:
	bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, bool* isVisited)
	{
		if (*str == '\0')
			return true;

		bool hasPath = false;
		if (*str == matrix[cols * row + col]
			&& row >= 0 && row < rows && col >= 0 && col < cols
			&& !isVisited[cols * row + col])
		{
			str++;
			isVisited[cols * row + col] = true;
			hasPath = hasPathCore(matrix, rows, cols, row + 1, col, str, isVisited)
				|| hasPathCore(matrix, rows, cols, row - 1, col, str, isVisited)
				|| hasPathCore(matrix, rows, cols, row, col + 1, str, isVisited)
				|| hasPathCore(matrix, rows, cols, row, col - 1, str, isVisited);
			if (!hasPath)
			{
				str--;
				isVisited[cols * row + col] = false;
			}
		}
		return hasPath;
	}
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		bool* isVisited = (bool*)malloc(sizeof(bool) * rows * cols);
		memset(isVisited, 0, sizeof(bool) * rows * cols);

		bool hasPath = false;
		for (int row = 0; row < rows; row++)
		{
			for (int col = 0; col < cols; col++)
			{
				hasPath = hasPathCore(matrix, rows, cols, row, col, str, isVisited);
				if (hasPath)
					return true;
			}
		}
		free(isVisited);
		return false;
	}
};



#pragma region �����˵��˶���Χ ���� ��ά���� ����
//������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
//���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18�����ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
#pragma endregion

class Solution {
public:
	int DigitalSum(unsigned int num)
	{
		int sum = num % 10;
		while (num / 10)
		{
			num /= 10;
			sum += num % 10;
		}
		return sum;
	}
	bool IsExceeded(const int &threshold, int rowNum, int colNum)
	{
		return DigitalSum(rowNum) + DigitalSum(colNum) > threshold ? 1 : 0;
	}
	int LegalMove(const int &threshold, const int &rows, const int &cols, int rowNum, int colNum, bool* visited)
	{
		if (visited[rowNum * cols + colNum] || rowNum < 0 || colNum < 0
			|| rowNum >= rows || colNum >= cols || IsExceeded(threshold, rowNum, colNum))
			return 0;
		visited[rowNum * cols + colNum] = true;
		return 1 + LegalMove(threshold, rows, cols, rowNum - 1, colNum, visited)
			+ LegalMove(threshold, rows, cols, rowNum + 1, colNum, visited)
			+ LegalMove(threshold, rows, cols, rowNum, colNum - 1, visited)
			+ LegalMove(threshold, rows, cols, rowNum, colNum + 1, visited);
	}
	int movingCount(int threshold, int rows, int cols)
	{
		bool *visited = (bool*)malloc(sizeof(bool) * rows * cols);
		int NUM = 0;
		memset(visited, 0, sizeof(bool) * rows * cols);
		return LegalMove(threshold, rows, cols, 0, 0, visited);;
	}
};