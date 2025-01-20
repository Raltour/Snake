//�ѳ�ʼ����������ӡ����ĺ���д������

#include "Block.h"
#include <easyx.h>
#include "Food.h"
#include "Snake.h"
#include<string.h>
#include<stdio.h>
#define ROUND 5//Բ�Ǿ��ε�Բ�ǰ뾶


void initGameBoard() {
	initgraph(X_LENGTH, Y_LENGTH + BLOCK_WIDTH);
	//��ɫ����ҵģ����Ե�
	setbkcolor(RGB(35, 206, 250));
	cleardevice();//����
	setfillcolor(RGB(240, 255, 240));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillrectangle(1, 1, X_SIZE * BLOCK_WIDTH, BLOCK_WIDTH);//�Ʒ�����
}

void drawFood(Food* food) {
	//�ú���������һ��food�ṹ���ָ�룬������ӡ�ڽ�����
}

void drawSnake(Snake* snake) {
	//�ú���������һ��snake�ṹ���ָ�룬������ӡ�ڽ�����
}

//main�����е��øú�������Ϸˢ���µ�һ֡
void refreshBoard(Snake* snake, Food* food) {
	drawSnake(snake);
	drawFood(food);
}



void food(int xcoord, int ycoord) {
	setfillcolor(RGB(255, 20, 147));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillroundrect(xcoord * BLOCK_WIDTH + 1, (ycoord + 1) * BLOCK_WIDTH + 1, (xcoord + 1) * BLOCK_WIDTH, (ycoord + 2) * BLOCK_WIDTH, ROUND, ROUND);
}

void score(int xxxx) {
	settextcolor(RGB(0, 0, 0));
	settextstyle(20, 0, _T("Verdana"));
	setbkcolor(RGB(240, 255, 240));
	outtextxy(240, 1, _T("Score:%d", xxxx));//����ط��е����⣬û�������ô�������
}

void block(int xcoord, int ycoord) {
	setfillcolor(RGB(0, 255, 0));
	solidroundrect(xcoord * BLOCK_WIDTH + 1, (ycoord + 1) * BLOCK_WIDTH + 1, (xcoord + 1) * BLOCK_WIDTH, (ycoord + 2) * BLOCK_WIDTH, ROUND, ROUND);
}