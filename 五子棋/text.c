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
	printf("******  1.˫��ģʽ  *****\n");
	printf("******  2.�˻�ģʽ  *****\n");
	printf("******  0.������ҳ  *****\n");
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
		printf("�����ʤ\n");
	}
	else if (ret == 'O')
	{
		printf("�����ʤ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("��һ�ʤ\n");
	}
	else if (ret == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	
	int intput = 0;
	do
	{
		meun();
		printf("��ѡ��:>");
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
				printf("��ѡ����Ϸģʽ:>");
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
					printf("����ѡ��\n");
					break;
				}
				}
			} while (intput1);
			break;
		}
		case 0:
		{
			printf("�˳���Ϸ\n");
			break;
		}
		default:
		{
			printf("����ѡ��\n");
			break;
		}
		}
	} while (intput);
	return 0;
}