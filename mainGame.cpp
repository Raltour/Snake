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
	initGameBoard();

	test();

	////������Ϸ�߼�ѭ��
	//while (true) {
	//	
	//}

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
	initGameBoard();

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

	delete mySnake;
}