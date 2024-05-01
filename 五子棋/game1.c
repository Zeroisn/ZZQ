#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

void Initboard1(char board1[row][col], int Row, int Col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < Row;i++)
	{
		for (j = 0;j < Col;j++)
		{
			board1[i][j] = ' ';
		}
	}
}
void printboard1(char board1[row][col], int Row, int Col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < Row;i++)
	{
		for (j = 0;j < Col;j++)
		{
			printf(" %c ", board1[i][j]);
			if (j < Col - 1)
				printf("|");
		}
		printf("\n");
		if (i < Row - 1)
		{
			for (j = 0;j < Col;j++)
			{
				printf("---");
				if (j < Col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void playerboard1(char board1[row][col], int Row, int Col)
{
	int x = 0;
	int y = 0;
	printf("黑棋方，请输入坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= Row && y >= 1 && y <= Col)
		{
			if (board1[x - 1][y - 1] == ' ')
			{
				board1[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("落子失败，请重新输入:>");
			}
		}
	}
}
void otherplayerboard(char board1[row][col], int Row, int Col)
{
	int x = 0;
	int y = 0;
	printf("白棋方，请输入坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= Row && y >= 1 && y <= Col)
		{
			if (board1[x - 1][y - 1] == ' ')
			{
				board1[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("落子失败，请重新输入:>");
			}
		}
	}
}
int is_full1(char board1[row][col], int ROW, int COL)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (board1[i][j] == ' ')
			{
				return 0;
			}
		}
	}

}
char is_win1(char board1[row][col], int Row, int Col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	//判断横向的输赢
	for (i = 0;i < Row;i++)
	{
		int count = 0;
		for (j = 0;j < Col;j++)
		{
			if (board1[i][j] != ' ' && board1[i][j] == board1[i][j + 1])
			{
				count++;
			}
			if ((board1[i][j]) != (board1[i][j + 1]))
			{
				count = 0;
			}

			if (count == 4)
			{
				return board1[i][j];
			}
		}
	}

	//判断纵向的输赢
	for (j = 0;j < Col;j++)
	{
		count = 0;
		for (i = 0;i < Row;i++)
		{
			if (board1[i][j] != ' ' && board1[i][j] == board1[i + 1][j])
			{
				count++;
			}
			if (board1[i][j] != board1[i + 1][j])
			{
				count = 0;
			}
			if (count == 4)
			{
				return board1[i][j];
			}
		}
	}

	//判断从左上到右下的斜向的输赢
	for (i = 0;i < Row;i++)
	{
		//k = i;
		for (j = 0;j < Col;j++)
		{
			if (board1[i][j] == board1[i + 1][j + 1] && board1[i + 1][j + 1] == board1[i + 2][j + 2] && board1[i + 2][j + 2] == board1[i + 3][j + 3] && board1[i + 3][j + 3] == board1[i + 4][j + 4] && board1[i][j] != ' ')
			{
				return board1[i][j];
			}
		}
	}

	//判断右上到左下的斜向的输赢
	for (i = 0;i < Row;i++)
	{
		//k = i;
		for (j = 0;j < Col;j++)
		{
			if (board1[i][j] == board1[i + 1][j - 1] && board1[i + 1][j - 1] == board1[i + 2][j - 2] && board1[i + 2][j - 2] == board1[i + 3][j - 3] && board1[i + 3][j - 3] == board1[i + 4][j - 4] && board1[i][j] != ' ')
			{
				return board1[i][j];
			}
		}
	}
	int ret1 = is_full1(board1, Row, Col);

	if (ret1 == 0)
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}
