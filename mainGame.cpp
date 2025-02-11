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

//�½�һ����,���ⲿ���ӵľ�̬����
extern Snake *mySnake = new Snake();


int main() {
	//��ʼ����������
	initBoard();

	//ʳ���ʼ�������Լ���ӡһ֡
	Food* myFood = generateFood(mySnake);
	refreshBoard(mySnake, myFood);//���ﻹûд��

	//���Է���Ϊ0
	int currentscore = 0;

	test();//��������

	//������Ϸ�߼�ѭ��
	while (true) {
		if (hasKeyInput()) {
			changeDirection(getKey());
		}

		snakeMove();

		if (isSnakeDead()) {
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
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);

	//�������ܷ�ת��
	snakeTurnLeft();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);
	snakeMove();
	delay(0.5);

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

	score(5);//�Ʒֺ���
	delay(0.5);
	closegraph();
	delay(0.5);
}