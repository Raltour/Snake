/*
* 游戏的主程序模块
*/

#include <easyx.h>
#include "Block.h"
#include "Snake.h"
#include "ui.h"
#include <stdio.h>
#include "Food.h"
#include "Board.h"


int main() {
	//新建一条蛇
	Snake* mySnake = new Snake();
	//初始化界面设置
	initGameBoard();


	//进入游戏逻辑循环
	while (true) {
		block(0, 0);
		block(0, 1);//绘制一节蛇身的函数（x,y)  范围0-29

		score(5);//计分函数

		food(10, 10);
	}


	closegraph();

	delete mySnake;
	return  0;
}