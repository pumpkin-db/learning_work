#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------棋盘--------\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------棋盘--------\n");
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_CONUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char board[ROWS][COLS], int x, int y)
{
	return(board[x - 1][y - 1] + board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0');
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EASY_CONUNT)
	{
		printf("请输入要排查的坐标->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				if (show[x][y] == '*')
				{
					win++;
					//统计mine[x][y]附近8个格子有几个雷
					int count = get_mine_count(mine, x, y);
					show[x][y] = count + '0';//转换为字符count
					Displayboard(show, ROW, COL);
				}
				else
				{
					printf("这个地方已经排查过，请排查其它地方\n");
				}
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_CONUNT)
	{
		printf("恭喜你，扫雷成功\n");
	}
	Displayboard(mine, ROW, COL);
}