#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("**************************\n");
	printf("**********1.play**********\n");
	printf("**********0.exit**********\n");
	printf("**************************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	Initborad(board, ROW, COL);
	displayboard(board, ROW, COL);
	while (1)
	{
		player(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		displayboard(board, ROW, COL);
		computer(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		displayboard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("还不错嘛，再来一局呗~\n");
	}
	else if (ret == '#')
	{
		printf("不会吧不会吧，居然有人连人机都下不赢，杂鱼~\n");
	}
	else if (ret == 'q')
	{
		printf("和人机旗鼓相当的对手嘛，真厉害\n");
	}
	displayboard(board, ROW, COL);
	printf("\n");

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("三子棋\n");
			game();
		}
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错了，重选！\n");
			break;
		}
	} while(input);
	return 0;
}