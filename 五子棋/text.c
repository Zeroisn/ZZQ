#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"
void meun()
{
	printf("*********************\n");
	printf("******  1.piay  *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}
void menu()
{
	printf("*************************\n");
	printf("******  1.双人模式  *****\n");
	printf("******  2.人机模式  *****\n");
	printf("******  0.返回主页  *****\n");
	printf("*************************\n");
}


void game1()
{
	char board1[row][col] = { 0 };
	Initboard1(board1, row, col);
	printboard1(board1, row, col);
	char ret = 0;
	while (1)
	{
		playerboard1(board1, row, col);
		system("cls");
		printboard1(board1, row, col);
		ret = is_win1(board1, row, col);
		if (ret != 'C')
		{
			break;
		}
		otherplayerboard(board1, row, col);
		system("cls");
		printboard1(board1, row, col);
		ret = is_win1(board1, row, col);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("黑棋获胜\n");
	}
	else if (ret == 'O')
	{
		printf("白棋获胜\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}


void game()
{
	char board[row][col] = { 0 };
	Initboard(board, row, col);
	printboard(board, row, col);
	char ret = 0;
	while (1)
	{
		playerboard(board, row, col);
		system("cls");
		printboard(board, row, col);
	    ret=is_win(board, row, col);
		if (ret != 'C')
		{
			break;
		}
		computerboard(board, row, col);
		system("cls");
		printboard(board, row, col);
	    ret=is_win(board, row, col);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	else if (ret == '#')
	{
		printf("电脑获胜\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	
	int intput = 0;
	do
	{
		meun();
		printf("请选择:>");
		scanf("%d", &intput);
		system("cls");
		switch (intput)
		{
		case 1:
		{
            srand((unsigned int)time(NULL));
			int intput1 = 0;
			do 
			{
				menu();
				printf("请选择游戏模式:>");
				scanf("%d", &intput1);
				system("cls");
				switch (intput1)
				{
				case 1:
				{
					game1();
					Sleep(3000);
					system("cls");
					break;
				}
				case 2:
				{
					game();
					Sleep(3000);
					system("cls");
					break;
				}
				case 0:
				{
					break;
				}
				default :
				{
					printf("重新选择\n");
					break;
				}
				}
			} while (intput1);
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("重新选择\n");
			break;
		}
		}
	} while (intput);
	return 0;
}