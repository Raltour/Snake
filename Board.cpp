//把初始化背景、打印界面的函数写在这里

#include "Block.h"
#include <easyx.h>
#include "Food.h"
#include "Snake.h"
#include<string.h>
#include<stdio.h>
#define ROUND 5//圆角矩形的圆角半径

void block(int xcoord, int ycoord) {
	setfillcolor(RGB(0, 255, 0));
	solidroundrect(xcoord * BLOCK_WIDTH + 1, (ycoord + 1) * BLOCK_WIDTH + 1, (xcoord + 1) * BLOCK_WIDTH, (ycoord + 2) * BLOCK_WIDTH, ROUND, ROUND);
}

void score(int xxxx) {
	settextcolor(RGB(0, 0, 0));
	settextstyle(20, 0, _T("Verdana"));
	setbkcolor(RGB(240, 255, 240));
	outtextxy(240, 1, _T("Score:%d", xxxx));//这个地方有点问题，没想出来怎么插入变量
}

void initBoard() {
	initgraph(X_LENGTH, Y_LENGTH + BLOCK_WIDTH);
	//颜色随便找的，可以调
	setbkcolor(RGB(35, 206, 250));
	cleardevice();//背景
	setfillcolor(RGB(240, 255, 240));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillrectangle(1, 1, X_SIZE * BLOCK_WIDTH, BLOCK_WIDTH);//计分区域
}

//该函数传进来一个food结构体的指针，把它打印在界面上
void drawFood(Food* food) {
	setfillcolor(RGB(255, 20, 147));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillroundrect(food->xcoord * BLOCK_WIDTH + 1, (food->ycoord + 1) * BLOCK_WIDTH + 1, (food->xcoord + 1) * BLOCK_WIDTH, (food->xcoord + 2) * BLOCK_WIDTH, ROUND, ROUND);

}

//该函数传进来一个snake结构体的指针，把它打印在界面上
void drawSnake(Snake* snake) {
	Node* current = snake->head->nextNode;
	while (current) {
		block(current->x_axis, current->x_axis);
		current = current->nextNode;
		}

}

//main函数中调用该函数，游戏刷新新的一帧
void refreshBoard(Snake* snake, Food* food, int currentScore) {
	drawSnake(snake);
	drawFood(food);
	score(currentScore);
}






