/*
* ���ļ�������
*snake�Ľṹ��
*���ƶ��ĺ���
*�����û�������ĺ���
*�������ƶ��ٶȵĺ���
*�Ե�ʳ���ӳ��ĺ��� 
* ����������������������ͷ�����ӽڵ㡢����β��ɾ���ڵ�
* 
*/

#include "Snake.h"
#include "Block.h"


struct Node {
	int x_axis;
	int y_axis;
	Node *nextNode;

	//Ĭ�Ϲ��캯��
	Node() : x_axis(0), y_axis(0), nextNode(nullptr) {}

	//�������Ĺ��캯��
	Node(int x, int y, Node* next)
		: x_axis(x), y_axis(y), nextNode(next) {}
};

struct Snake {
	Node *head;
	Node *end;

	int length;
	int speed;

	//�½�һ����ʱ���õ�Ĭ�Ϲ��캯��
	Snake() {
		*head = Node(INITIAL_PLACE_X, INITIAL_PLACE_Y, nullptr);
		*end = Node(INITIAL_PLACE_X - 1, INITIAL_PLACE_Y + 1, nullptr);
		head->nextNode = end;
		length = INITIAL_LENGTH;
		speed = INITIAL_SPEED;	
	}
};

//����һ���µ���
Snake creatNewSnake() {
	return Snake();
}

//���ߵ�ǰ������µĽڵ�
void addFirst(Snake snake) {

}

//ȥ����ĩβ�Ľڵ�
void removeLast(Snake snake) {

}

//��������ǰ�ƶ��ĺ���
//��addFirst��removeLast���������
void snakeMove(Snake snake) {

}

//�������û�������ĺ���
bool isSnakeDead(Snake snake) {
	return false;
}

//���߼��ٵĳ���
void accelerateSnake(Snake *snake) {
	snake->speed++;
}