/*
* ��Ϸ��������ģ��
*/

#include <easyx.h>
#include "Block.h"
#include "Snake.h"
#include "ui.h"
#include <stdio.h>
#include "Food.h"
#include "Board.h"


int main() {
	//�½�һ����
	Snake *mySnake = new Snake();
	//��ʼ����������
	initGameBoard();


	//������Ϸ�߼�ѭ��
	while (true) {
		//���³������Ϊ����ʹ�ã�ʵ�ʳ�����������

		//�����ܷ�������ӡ
		block(0, 0);
		block(0, 1);//����һ������ĺ�����x,y)  ��Χ0-29
		food(10, 10);

		//�������ܷ������ƶ�
		snakeMove(mySnake);
		snakeMove(mySnake);
		snakeMove(mySnake);

	}

	score(5);//�Ʒֺ���
	closegraph();

	delete mySnake;
	return  0;
}