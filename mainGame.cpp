/*
* 游戏的主程序模块
*/

#include <easyx.h>
#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "Time.h"

//新建一条蛇,带外部链接的静态变量
extern Snake *mySnake = new Snake();

int main() {
	//初始化界面设置
	initBoard();

	//食物初始化设置以及打印一帧
	Food* myFood = generateFood();
	refreshBoard(myFood);

	//进入游戏逻辑循环
	while (true) {
        changeDirection();

		snakeMove();

		if (isSnakeDead()) {
			break;
		}

		if (isFoodEaten(myFood)) {
			mySnake->end->nextNode = new Node(mySnake->lastX, mySnake->lastY, nullptr);
			mySnake->end = mySnake->end->nextNode;
			mySnake->length++;
			delete myFood;
			Food *myFood = generateFood();
		}

		refreshBoard(myFood);
		delay(0.2);
	}

	closegraph();

	return  0;
}