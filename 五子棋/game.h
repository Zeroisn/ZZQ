#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define row 21
#define col 21

//�˻�ģʽ
void Initboard(char board[row][col],int Row,int Col);//��ʼ��
void printboard(char board[row][col], int Row, int Col);//��ӡ����
void playerboard(char board[row][col], int Row, int Col);//�������
void computerboard(char board[row][col], int Row, int Col);//��������
char is_win(char board[row][col], int Row, int Col);//�ж���Ӯ

//˫��ģʽ
void otherplayerboard(char board1[row][col], int Row, int Col);//��һ���������
void Initboard1(char board1[row][col], int Row, int Col);//��ʼ��
void printboard1(char board1[row][col], int Row, int Col);//��ӡ����
void playerboard1(char board1[row][col], int Row, int Col);//�������
char is_win1(char board1[row][col], int Row, int Col);//�ж���Ӯ