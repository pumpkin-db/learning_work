#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//测试四字棋
void game()
{
	//数组-存放棋盘信息
	char board[ROW][COL] = {0};
	//初始化棋盘
	Initboard(board, ROW, COL);
	//打印棋盘
    //   |   |   
    //---|---|---
	//   |   |   
	//---|---|---
	//   |   |  
	Displayboard(board, ROW, COL);
	char ret=0;
	while (1)
	{
		Playermove(board, ROW, COL);
		//判断输赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		Displayboard(board, ROW, COL);

		Computermove(board, ROW, COL); 
		char ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		Displayboard(board, ROW, COL);
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
	Displayboard(board, ROW, COL);
}
void menu()
{
	printf("*************************\n");
	printf("****1. play    0.exit****\n");
	printf("*************************\n");
}
void test()
{
	srand((unsigned int)time(NULL));//设置随机数生成的起点
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("四字棋\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}