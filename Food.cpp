/*
* ����ʳ��Ķ��塢ʳ�����ˢ�µĺ���
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

////ʳ������
//int foodX, foodY;
//
////����ʳ��
//Food generateFood(Snake snake)
//{
//	srand(time(0));//�������������
//
//	while (true)
//	{
//		//�������ʳ������(��֤ʳ�ﲻ��ǽ���ϣ�
//		foodX = rand() % (X_SIZE - 2) + 1;
//		foodY = rand() % (Y_SIZE - 2) + 1;
//
//		//���ʳ���������Ƿ��ص�
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
//			gameArea[foodX][foodY] = '*';//��
//			break;
//		}
//	}
//
//	return createFood(foodX, foodY);
//}
//
////�ж��Ƿ�Ե�ʳ��
//bool isFoodEaten()
//{
//	if (snakeHead->x == foodX && snakeHead->y == foodY)
//	{
//		return true;
//	}
//	return false;
//}