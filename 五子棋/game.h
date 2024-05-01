#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define row 21
#define col 21

//人机模式
void Initboard(char board[row][col],int Row,int Col);//初始化
void printboard(char board[row][col], int Row, int Col);//打印棋盘
void playerboard(char board[row][col], int Row, int Col);//玩家下棋
void computerboard(char board[row][col], int Row, int Col);//电脑下棋
char is_win(char board[row][col], int Row, int Col);//判断输赢

//双人模式
void otherplayerboard(char board1[row][col], int Row, int Col);//另一名玩家下棋
void Initboard1(char board1[row][col], int Row, int Col);//初始化
void printboard1(char board1[row][col], int Row, int Col);//打印棋盘
void playerboard1(char board1[row][col], int Row, int Col);//玩家下棋
char is_win1(char board1[row][col], int Row, int Col);//判断输赢