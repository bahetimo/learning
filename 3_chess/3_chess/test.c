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
		printf("�����������һ����~\n");
	}
	else if (ret == '#')
	{
		printf("����ɲ���ɣ���Ȼ�������˻����²�Ӯ������~\n");
	}
	else if (ret == 'q')
	{
		printf("���˻�����൱�Ķ����������\n");
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
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("������\n");
			game();
		}
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ����ˣ���ѡ��\n");
			break;
		}
	} while(input);
	return 0;
}