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
#include "Time.h"
void test();//以后删掉




int main() {
	//新建一条蛇
	Snake* mySnake = (Snake*)malloc(sizeof(Snake));
	//初始化界面设置
	initBoard();
	//蛇的初始化设置、食物初始化设置以及打印一帧
	Food* myFood = generateFood(mySnake);
	refreshBoard(mySnake, myFood);//这里还没写完
	int currentscore = 0;

	test();//仅供测试

	//进入游戏逻辑循环
	while (true) {
		if (hasKeyInput()) {
			changeDirection(mySnake, getKey());
		}

		snakeMove(mySnake);

		if (isSnakeDead(mySnake)) {
			break;
		}

		if (isFoodEaten(mySnake, myFood)) {
			mySnake->end->nextNode = mySnake->lastEnd;
			mySnake->end = mySnake->lastEnd;
			mySnake->length++;
		}

		refreshBoard(mySnake, myFood, currentscore);
		delay(0.5);
	}

	score(5);//计分函数
	closegraph();

	free(mySnake);
	return  0;
}


//测试
void test() {
	//新建一条蛇
	Snake* mySnake = (Snake*)malloc(sizeof(Snake));
	//初始化界面设置
	initBoard();

	delay(0.5);
	//测试能否正常打印(其实后面这些函数删掉就行，全都迁移到board.cpp文件中)
	block(0, 0);
	delay(0.5);
	block(0, 1);//绘制一节蛇身的函数（x,y)  范围0-29
	delay(0.5);
	food(10, 10);
	delay(0.5);

	//测试新建食物
	Food* myFood = (Food*)malloc(sizeof(Food));

	//测试能否刷新界面
	refreshBoard(mySnake, myFood);
	delay(0.5);

	//测试蛇能否正常移动
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);

	//测试蛇能否转弯
	snakeTurnLeft(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);

	snakeTurnRight(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	free(myFood);
	delay(0.5);

	score(5);//计分函数
	delay(0.5);
	closegraph();
	delay(0.5);

	free(mySnake);
}