/*
* ���ļ�������
*snake�Ľṹ��
*���ƶ��ĺ���
*�����û�������ĺ���
*�������ƶ��ٶȵĺ���
*�Ե�ʳ���ӳ��ĺ���
* ����������������������ͷ�����ӽڵ㡢����β��ɾ���ڵ�
*/

#include "Snake.h"
#include "Block.h"
#include "Food.h"


//���ߵ�ǰ������µĽڵ�
void addFirst() {
    int newX = mySnake->head->x_axis;
    int newY = mySnake->head->y_axis;

    // ���ݵ�ǰ��������½ڵ��λ��
    switch (mySnake->direction) {
    case 0: newY -= 1; break; // ����
    case 1: newX += 1; break; // ����
    case 2: newY += 1; break; // ����
    case 3: newX -= 1; break; // ����
    }

    Node* newNode = new Node(newX, newY, mySnake->head);
    mySnake->head = newNode;
}

//ȥ����ĩβ�Ľڵ�
void removeLast() {
    if (!mySnake->end) return;

    mySnake->lastEnd = mySnake->end;

    Node* prev = mySnake->head;
    while (prev->nextNode && prev->nextNode != snake.end) {
        prev = prev->nextNode;
    }

    delete mySnake->end;
    mySnake->end = prev;
    mySnake->->nextNode = nullptr;
}

//��������ǰ�ƶ��ĺ���
//��addFirst��removeLast���������
void snakeMove() {
    addFirst();
    removeLast();
}

//�������û�������ĺ���
bool isSnakeDead() {
    // �����ͷ�Ƿ�ײǽ
    if (mySnake->head->x_axis < 0 || mySnake->head->x_axis > 30 ||
        mySnake->head->y_axis < 0 || mySnake->head->y_axis > 30) {
        return true;
    }

    // �����ͷ�Ƿ�ײ���Լ�
    Node* current = mySnake->head->nextNode;
    while (current) {
        if (current->x_axis == mySnake->head->x_axis &&
            current->y_axis == mySnake->head->y_axis) {
            return true;
        }
        current = current->nextNode;
    }

    return false;
}

//���߼��ٵĳ���
void accelerateSnake() {
    mySnake->speed++;
}

//������ת�ĳ���
void snakeTurnLeft() {

}

//������ת�ĳ���
void snakeTurnRight() {
	
}

void changeDirection(char key) {
    //���turnleft\turnright
}

//�����ͷ��û�гԵ�ʳ���ʳ�������ص���
//�ú�������������ͷ�ļ�Food.h��
bool isFoodEaten(Food* food)
{
    if (mySnake->head->x_axis == food->xcoord && mySnake->head->y_axis == food->ycoord)
    {
        return true;
    }
    return false;
}