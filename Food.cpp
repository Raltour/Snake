/*
* 包含食物的定义、食物随机刷新的函数
* 
*/

#include "Block.h"
#include "Food.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>


Food *createFood(int x, int y) {
	return &Food(x, y);
}



////生成随机食物，不能与蛇的身体重叠
//Food *generateFood(Snake snake)
//{
//	srand(time(0));//设置随机数种子
//
//	//食物坐标
//	int foodX, foodY;
//	while (true)
//	{
//		//随机生成食物坐标(保证食物不在墙壁上）
//		foodX = rand() % (X_SIZE - 2) + 1;
//		foodY = rand() % (Y_SIZE - 2) + 1;
//
//		//检查食物与身体是否重叠
//		bool overlapSnake = false;
//		SnakeSegment* temp = snakeHead;
//		while (temp != nullptr)
//		{
//			if (temp->x == foodX && temp->y == foodY)
//			{
//				overlapSnake = true;
//				break;
//			}
//			temp = temp->next;
//		}
//
//		if (!overlapSnake)
//		{
//			gameArea[foodX][foodY] = '*';//改
//			break;
//		}
//	}
//
//	return createFood(foodX, foodY);
//}