/*
* 包含食物的定义、食物随机刷新的函数
*/

#include "Block.h"
#include "Food.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>



//生成随机食物，不能与蛇的身体重叠
Food *generateFood()
{
	srand(time(NULL));//设置随机数种子

	//食物坐标
	int foodX, foodY;
	while (true) {
		//随机生成食物坐标(保证食物不在墙壁上）
		foodX = rand() % (X_SIZE - 2) + 1;
		foodY = rand() % (Y_SIZE - 2) + 1;

		//检查食物与身体是否重叠
		bool overlapSnake = false;
		Node *temp = mySnake->head;
		while (temp != nullptr)
		{
			if (temp->x_axis == foodX && temp->y_axis == foodY)
			{
				overlapSnake = true;
				break;
			}
			temp = temp->nextNode;
		}

		if (!overlapSnake)
		{
			break;
		}
	}

	return new Food(foodX, foodY);
}