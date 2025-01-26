/*
* 包含食物的定义、食物随机刷新的函数
* 
*/

#include "Block.h"
#include "Food.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>


Food createFood(int x, int y) {
	return Food(x, y);
}

////食物坐标
//int foodX, foodY;
//
////生成食物
//Food generateFood(Snake snake)
//{
//	srand(time(0));//设置随机数种子
//
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
//
////判断是否吃到食物
//bool isFoodEaten()
//{
//	if (snakeHead->x == foodX && snakeHead->y == foodY)
//	{
//		return true;
//	}
//	return false;
//}