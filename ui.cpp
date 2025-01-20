//颜色随便找的，可以调
#include<easyx.h>
#include<string.h>
#include "Block.h"
#include<stdio.h>
#define ROUND 5//圆角矩形的圆角半径
void block(int xcoord, int ycoord);
void food(int xcoord, int ycoord);
void score(int score);


void food(int xcoord, int ycoord) {
	setfillcolor(RGB(255, 20, 147));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillroundrect(xcoord*BLOCK_WIDTH+1, (ycoord+1) * BLOCK_WIDTH + 1, (xcoord + 1) * BLOCK_WIDTH, (ycoord + 2) * BLOCK_WIDTH, ROUND,ROUND);
}

void score(int xxxx) {
	settextcolor(RGB(0, 0, 0));
	settextstyle(20, 0, _T("Verdana"));
	setbkcolor(RGB(240, 255, 240));
	outtextxy(240, 1, _T("Score:%d",xxxx));//这个地方有点问题，没想出来怎么插入变量
}

void block(int xcoord, int ycoord) {
	setfillcolor(RGB(0, 255, 0));
	solidroundrect(xcoord * BLOCK_WIDTH + 1, (ycoord + 1) * BLOCK_WIDTH + 1, (xcoord + 1) * BLOCK_WIDTH, (ycoord + 2) * BLOCK_WIDTH, ROUND, ROUND);
}