/*
* 游戏的主程序模块
*/

#include <easyx.h>
#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "Time.h"
#include <stdio.h>
void test();//以后删掉

//新建一条蛇,带外部链接的静态变量
extern Snake *mySnake = new Snake();


int main() {
	test();//仅供测试



	// //初始化界面设置
	// initBoard();
 //
	// //食物初始化设置以及打印一帧
	// Food* myFood = generateFood();
	// refreshBoard(myFood);
	//
	// //进入游戏逻辑循环
	// while (true) {
 //        // changeDirection();
 //
	// 	snakeMove();
 //
	// 	if (isSnakeDead()) {
	// 		break;
	// 	}
 //
	// 	if (isFoodEaten(myFood)) {
	// 		mySnake->end->nextNode = mySnake->lastEnd;
	// 		mySnake->end = mySnake->lastEnd;
	// 		mySnake->length++;
	// 		delete myFood;
	// 		Food *myFood = generateFood();
	// 	}
 //
	// 	refreshBoard(myFood);
	// 	delay(0.5);
	// }
 //
	// closegraph();

	return  0;
}


//测试
void test() {
	//初始化界面设置
	initBoard();
	delay(0.5);
	puts("1");

	//测试能否正常打印(其实后面这些函数删掉就行，全都迁移到board.cpp文件中)
	block(0, 0);
	block(0, 1);
	puts("2");


	//测试新建食物
	Food* myFood = generateFood();

	//测试能否刷新界面
	refreshBoard(myFood);
	puts("3");
	getchar();



	//测试蛇能否正常移动
	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	puts("4");
	getchar();

	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	puts("5");
	getchar();

	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	puts("6");
	getchar();

	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	puts("7");
	getchar();




	//测试蛇能否转弯
	snakeTurnLeft();
	delay(0.5);
	refreshBoard(myFood);
	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	snakeMove();
	delay(0.5);
	refreshBoard(myFood);
	getchar();
	puts("6");


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
	getchar();
	puts("7");



	delay(0.5);
	closegraph();
	delay(0.5);
	getchar();
	puts("8");
}