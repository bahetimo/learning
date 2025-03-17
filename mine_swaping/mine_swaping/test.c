#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu()
{
	printf("**********************\n");
	printf("******* 1.game *******\n");
	printf("******* 0.exit *******\n");
	printf("**********************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化雷
	Initmenu(mine, ROWS, COLS, '0');
	Initmenu(show, ROWS, COLS, '*');

	//设置雷
	SetMine(mine, ROW, COL);

	//展示
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//排查雷
	FindMine(mine, show, ROW, COL);

	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入序号：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("扫雷\n");
			game();
		}
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，重来\n");
			break;
		}

	} while (input);
	return 0;
}