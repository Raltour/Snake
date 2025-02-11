/*
* ��Ϸ��������ģ��
*/

#include <easyx.h>
#include "Block.h"
#include "Snake.h"
#include <stdio.h>
#include "Food.h"
#include "Board.h"
#include <malloc.h>
#include "Time.h"
void test();//�Ժ�ɾ��




int main() {
	//�½�һ����
	Snake* mySnake = (Snake*)malloc(sizeof(Snake));
	//��ʼ����������
	initBoard();
	//�ߵĳ�ʼ�����á�ʳ���ʼ�������Լ���ӡһ֡
	Food* myFood = generateFood(mySnake);
	refreshBoard(mySnake, myFood);//���ﻹûд��
	int currentscore = 0;

	test();//��������

	//������Ϸ�߼�ѭ��
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

	score(5);//�Ʒֺ���
	closegraph();

	free(mySnake);
	return  0;
}


//����
void test() {
	//�½�һ����
	Snake* mySnake = (Snake*)malloc(sizeof(Snake));
	//��ʼ����������
	initBoard();

	delay(0.5);
	//�����ܷ�������ӡ(��ʵ������Щ����ɾ�����У�ȫ��Ǩ�Ƶ�board.cpp�ļ���)
	block(0, 0);
	delay(0.5);
	block(0, 1);//����һ������ĺ�����x,y)  ��Χ0-29
	delay(0.5);
	food(10, 10);
	delay(0.5);

	//�����½�ʳ��
	Food* myFood = (Food*)malloc(sizeof(Food));

	//�����ܷ�ˢ�½���
	refreshBoard(mySnake, myFood);
	delay(0.5);

	//�������ܷ������ƶ�
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);
	snakeMove(mySnake);
	delay(0.5);

	//�������ܷ�ת��
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

	score(5);//�Ʒֺ���
	delay(0.5);
	closegraph();
	delay(0.5);

	free(mySnake);
}