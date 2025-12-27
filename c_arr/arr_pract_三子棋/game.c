#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//初始化棋盘
void Initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j]=' ';
		}
	}
}

//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		//打印数据行
		for (int j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//打印分割行
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

//玩家下棋
void Playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋->\n");
	printf("请输入坐标:\n");
	//填入坐标，并进行合法化判断
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请选择其他位置\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}

//电脑下棋
void Computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋->\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
//判断是否满了，满了返回1，否则返回0
int Isfull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//判断输赢
//玩家赢->'*'
//电脑赢->'#'
//平局->'Q'
//继续->'C'
char Iswin(char board[ROW][COL], int row, int col)
{
	//行
	for (int i = 0; i < row; i++)
	{
		int num1 = 1;
		for (int j = 1; j < col; j++)
		{
			if (board[i][0] != board[i][j])
			{
				num1 = 0;
			}
		}
		if (num1 == 1 && board[i][0]!=' ')
			return board[i][0];
	}
	//列
	for (int j = 0; j < col; j++)
	{
		int num2 = 1;
		for (int i = 1; i < row; i++)
		{
			if (board[0][j] != board[i][j])
			{
				num2 = 0;
			}
		}
		if (num2 == 1 && board[0][j] != ' ')
			return board[0][j];
	}
	//对角线

	//主对角线
	int num3 = 1;
	for (int i = 1; i < row; i++)
	{
		if (board[0][0] != board[i][i])
		{
			num3 = 0;
		}
	}
	if (num3 == 1 && board[0][0] != ' ')
		return board[0][0];
	//负对角线
	int num4 = 1;
	for (int i = 1; i < row; i++)
	{
		if (board[0][col - 1] != board[i][col - 1 - i])
		{
			num4 = 0;
			break;
		}
	}
	if (num4 == 1 && board[0][col - 1] != ' ')
		return board[0][col - 1];
	//平局
	if (Isfull(board, ROW, COL))
	{
		return 'Q';
	}
	//继续
	return 'C';
}