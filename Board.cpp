//把初始化背景、打印界面的函数写在这里

#include "Block.h"
#include <easyx.h>

void initGameBoard() {
	initgraph(X_LENGTH, Y_LENGTH + BLOCK_WIDTH);
	setbkcolor(RGB(35, 206, 250));
	cleardevice();//背景
	setfillcolor(RGB(240, 255, 240));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillrectangle(1, 1, X_SIZE * BLOCK_WIDTH, BLOCK_WIDTH);//计分区域
}