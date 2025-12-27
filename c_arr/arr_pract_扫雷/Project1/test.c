#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*****************************\n");
	printf("*********** 1.play **********\n");
	printf("*********** 0.exit **********\n");
	printf("*****************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化数组
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	//设置雷
	Setmine(mine, ROW, COL);
	//展示数组
	Displayboard(mine,ROW,COL);
	Displayboard(show,ROW,COL);
	//排查雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input = 0;
	//设置随机数生成
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择->");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}