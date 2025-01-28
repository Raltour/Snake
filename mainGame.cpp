/*
* 游戏的主程序模块
*/

#include <easyx.h>
#include "Block.h"
#include "Snake.h"
#include <stdio.h>
#include "Food.h"
#include "Board.h"
#include <malloc.h>


int main() {
	//新建一条蛇
	Snake* mySnake = (Snake*)malloc(sizeof(Snake));
	//初始化界面设置
	initGameBoard();


	//进入游戏逻辑循环
	while (true) {
		//以下程序仅作为测试使用，实际程序不是这样滴

		//测试能否正常打印(其实后面这些函数删掉就行，全都迁移到board.cpp文件中)
		block(0, 0);
		block(0, 1);//绘制一节蛇身的函数（x,y)  范围0-29
		food(10, 10);

		//测试新建食物
		Food* myFood = (Food*)malloc(sizeof(Food));

		//测试能否刷新界面
		refreshBoard(mySnake, myFood);

		//测试蛇能否正常移动
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);

		//测试蛇能否转弯
		snakeTurnLeft(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);

		snakeTurnRight(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);
		free(myFood);
		break;
	}

	score(5);//计分函数
	closegraph();

	delete mySnake;
	return  0;
}