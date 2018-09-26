#include<vector>

using namespace std;


#pragma region 矩阵中的路径 矩阵 二维数组 回溯
//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
//路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
//如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。
//例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

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



#pragma region 机器人的运动范围 矩阵 二维数组 回溯
//地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
//例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
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