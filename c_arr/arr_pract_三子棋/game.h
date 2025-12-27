#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4
//初始化棋盘
void Initboard(char board[ROW][COL], int row, int col);

//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col);

//玩家下棋
void Playermove(char board[ROW][COL], int row, int col);

//电脑下棋
void Computermove(char board[ROW][COL], int row, int col);

//判断输赢
char Iswin();