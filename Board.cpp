//把初始化背景、打印界面的函数写在这里

#include "Block.h"
#include <easyx.h>
#include "Food.h"
#include "Snake.h"

void initGameBoard() {
	initgraph(X_LENGTH, Y_LENGTH + BLOCK_WIDTH);
	setbkcolor(RGB(35, 206, 250));
	cleardevice();//背景
	setfillcolor(RGB(240, 255, 240));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillrectangle(1, 1, X_SIZE * BLOCK_WIDTH, BLOCK_WIDTH);//计分区域
}

void drawFood(Food* food) {
	//该函数传进来一个food结构体的指针，把它打印在界面上
}

void drawSnake(Snake* snake) {
	//该函数传进来一个snake结构体的指针，把它打印在界面上
}

//main函数中调用该函数，游戏刷新新的一帧
void refreshBoard(Snake* snake, Food* food) {
	drawSnake(snake);
	drawFood(food);
}