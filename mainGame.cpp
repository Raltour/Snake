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


int main() {
	//�½�һ����
	Snake* mySnake = (Snake*)malloc(sizeof(Snake));
	//��ʼ����������
	initGameBoard();


	//������Ϸ�߼�ѭ��
	while (true) {
		//���³������Ϊ����ʹ�ã�ʵ�ʳ�����������

		//�����ܷ�������ӡ(��ʵ������Щ����ɾ�����У�ȫ��Ǩ�Ƶ�board.cpp�ļ���)
		block(0, 0);
		block(0, 1);//����һ������ĺ�����x,y)  ��Χ0-29
		food(10, 10);

		//�����½�ʳ��
		Food* myFood = (Food*)malloc(sizeof(Food));

		//�����ܷ�ˢ�½���
		refreshBoard(mySnake, myFood);

		//�������ܷ������ƶ�
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);

		//�������ܷ�ת��
		snakeTurnLeft(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);

		snakeTurnRight(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);
		free(myFood);
		break;
	}

	score(5);//�Ʒֺ���
	closegraph();

	delete mySnake;
	return  0;
}