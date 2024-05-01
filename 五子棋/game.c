#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

void Initboard(char board[row][col],int Row,int Col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < Row;i++)
	{
		for (j = 0;j < Col;j++)
		{
			board[i][j] = ' ';
		}
	}
}
void printboard(char board[row][col],int Row,int Col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < Row;i++)
	{
			for (j = 0;j < Col;j++)
			{
				printf(" %c ", board[i][j]);
				if (j < Col - 1)
					printf("|");
			}
			printf("\n");
			if (i < Row-1)
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
void playerboard(char board[row][col], int Row, int Col)
{
	int x = 0;
	int y = 0;
	printf("�����ˣ�����������:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= Row && y >= 1 && y <= Col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("����ʧ�ܣ�����������:>");
			}
		}
	}
}
void computerboard(char board[row][col], int Row, int Col)
{
   // printf("������\n");
	while (1)
	{
	   int x = rand() % Row;
	   int y = rand() % Col;
	  
	   if (board[x][y] !='*' && board[x][y]!='#')
		{
			board[x][y] = '#';
		    break;
		}
	}
}
int is_full(char board[row][col], int ROW, int COL)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	
}
char is_win(char board[row][col], int Row, int Col)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	//�жϺ������Ӯ
	for (i = 0;i < Row;i++)
	{
		int count = 0;
		for (j = 0;j < Col;j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] )
			{
				
				 count++;
				
			}
			if ((board[i][j]) !=(board[i][j + 1]))
			{
				count = 0;
			}
			
			if (count == 4)
			{
				return board[i][j];
			}
		}
	}

	//�ж��������Ӯ
	for (j = 0;j < Col;j++)
	{
		count = 0;
		for (i = 0;i < Row;i++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i+1][j])
			{
				count++;
			}
			if (board[i][j] != board[i+1][j])
			{
				count = 0;
			}
			if (count == 4)
			{
				return board[i][j];
			}
		}
	}

	//�жϴ����ϵ����µ�б�����Ӯ
	for (i = 0;i < Row;i++)
	{
		//k = i;
		for (j = 0;j < Col;j++)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4] && board[i][j]!=' ')
			{
				return board[i][j];
			}
		}
	}

	//�ж����ϵ����µ�б�����Ӯ
	for (i = 0;i < Row;i++)
	{
		//k = i;
		for (j = 0;j < Col;j++)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i + 2][j - 2] == board[i + 3][j - 3] && board[i + 3][j - 3] == board[i + 4][j - 4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	int ret1 = is_full(board, Row, Col);

	if (ret1 == 0)
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}
