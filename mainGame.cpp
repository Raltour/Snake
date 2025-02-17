/*
* 游戏的主程序模块
*/

#include <easyx.h>
#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "Time.h"
void test();//以后删掉

//新建一条蛇,带外部链接的静态变量
extern Snake *mySnake = new Snake();


int main() {
	//初始化界面设置
	initBoard();

	//食物初始化设置以及打印一帧
	Food* myFood = generateFood();
	refreshBoard(myFood);

	// test();//仅供测试

	//进入游戏逻辑循环
	while (true) {
        changeDirection();

		snakeMove();

		if (isSnakeDead()) {
			break;
		}

		if (isFoodEaten(myFood)) {
			mySnake->end->nextNode = mySnake->lastEnd;
			mySnake->end = mySnake->lastEnd;
			mySnake->length++;
			delete myFood;
			Food *myFood = generateFood();
		}

		refreshBoard(myFood);
		delay(0.5);
	}

	closegraph();

	return  0;
}


//测试
void test() {
	//初始化界面设置
	initBoard();
	delay(0.5);

	//测试能否正常打印(其实后面这些函数删掉就行，全都迁移到board.cpp文件中)
	block(0, 0);
	block(0, 1);//绘制一节蛇身的函数（x,y)  范围0-29

	//测试新建食物
	Food* myFood = (Food*)malloc(sizeof(Food));

	//测试能否刷新界面
	refreshBoard(myFood);

	//测试蛇能否正常移动
	snakeMove();
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	refreshBoard(myFood);


	//测试蛇能否转弯
	snakeTurnLeft();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	refreshBoard(myFood);


	snakeTurnRight();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	free(myFood);
	delay(0.5);
	refreshBoard(myFood);


	delay(0.5);
	closegraph();
	delay(0.5);
}