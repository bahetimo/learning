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

	//��ʼ����
	Initmenu(mine, ROWS, COLS, '0');
	Initmenu(show, ROWS, COLS, '*');

	//������
	SetMine(mine, ROW, COL);

	//չʾ
	//Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//�Ų���
	FindMine(mine, show, ROW, COL);

	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��������ţ�>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("ɨ��\n");
			game();
		}
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������\n");
			break;
		}

	} while (input);
	return 0;
}