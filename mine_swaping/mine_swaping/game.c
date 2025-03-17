#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void Initmenu(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0, j = 0;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("-----ɨ����Ϸ-----\n");
	for (j = 0;j <= col;j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	printf("  ");
	for (j = 1;j < col;j++)
	{
		printf("__");
	}
	printf("_");
	printf("\n");

	for (i = 1;i <= row;i++)
	{
		printf("%d|", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	printf("-----ɨ����Ϸ-----\n");

}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = MINE_NUM;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] != '0');
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int mine_count(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while (win < row * col - MINE_NUM)
	{
		printf("�������꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("ը��\n");
				printf("os��1Ϊ��\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else if (show[x][y] == '*')
			{
				int count = mine_count(mine, x, y);
				show[x][y] = count + '0';
				Displayboard(show, ROW, COL);

			}
			else
			{
				printf("��ѡ��������\n");
			}
		}
		else
		{
			printf("���겻���ڣ���ѡ\n");
		}
	}
	if (win == row * col - MINE_NUM)
	{
		printf("�ɹ����ף�\n");
		printf("os��1Ϊ��\n");
		Displayboard(mine, ROW, COL);

	}

}
