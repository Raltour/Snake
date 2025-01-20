/*
* ��Ϸ��������ģ��
*/

#include <easyx.h>
#include "Block.h"
#include "Snake.h"
#include "ui.h"
#include <stdio.h>


int main() {

	Snake* mySnake = new Snake();


	initgraph(X_LENGTH, Y_LENGTH + BLOCK_WIDTH);

	setbkcolor(RGB(35, 206, 250));
	cleardevice();//����

	setfillcolor(RGB(240, 255, 240));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillrectangle(1, 1, X_SIZE * BLOCK_WIDTH, BLOCK_WIDTH);//�Ʒ�����

	block(0, 0);
	block(0, 1);//����һ������ĺ�����x,y)  ��Χ0-29

	score(5);//�Ʒֺ���

	food(10, 10);

	char a = getchar();
	closegraph();

	delete mySnake;
	return  0;
}