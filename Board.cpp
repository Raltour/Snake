//�ѳ�ʼ����������ӡ����ĺ���д������

#include "Block.h"
#include <easyx.h>
#include "Food.h"
#include "Snake.h"

void initGameBoard() {
	initgraph(X_LENGTH, Y_LENGTH + BLOCK_WIDTH);
	setbkcolor(RGB(35, 206, 250));
	cleardevice();//����
	setfillcolor(RGB(240, 255, 240));
	setlinecolor(RGB(240, 255, 240));
	setlinestyle(PS_DASH, 3);
	fillrectangle(1, 1, X_SIZE * BLOCK_WIDTH, BLOCK_WIDTH);//�Ʒ�����
}

void drawFood(Food* food) {
	//�ú���������һ��food�ṹ���ָ�룬������ӡ�ڽ�����
}

void drawSnake(Snake* snake) {
	//�ú���������һ��snake�ṹ���ָ�룬������ӡ�ڽ�����
}

//main�����е��øú�������Ϸˢ���µ�һ֡
void refreshBoard(Snake* snake, Food* food) {
	drawSnake(snake);
	drawFood(food);
}