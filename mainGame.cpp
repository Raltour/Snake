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
	Snake* mySnake = new Snake();
	//��ʼ����������
	initGameBoard();


	//������Ϸ�߼�ѭ��
	while (true) {
		block(0, 0);
		block(0, 1);//����һ������ĺ�����x,y)  ��Χ0-29

		score(5);//�Ʒֺ���

		food(10, 10);
	}


	closegraph();

	delete mySnake;
	return  0;
}