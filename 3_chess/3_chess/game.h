#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define ROW 3
#define COL 3

void Initborad(char board[ROW][COL],int row,int col);

void displayboard(char board[ROW][COL], int row, int col);

void player(char board[ROW][COL], int row, int col);

void computer(char board[ROW][COL], int row, int col);

char iswin(char board[ROW][COL], int row, int col);
//ret
//c ����
//q ƽ��
//* ���Ӯ
//# ����Ӯ




