/*
* 本文件包含：
*snake的结构体
*蛇移动的函数
*检测有没有死亡的函数
*调整蛇移动速度的函数
*吃到食物延长的函数
* 几个辅助函数，作用链表头部增加节点、链表尾部删除节点
*/

#include "Snake.h"
#include "Block.h"
#include "Food.h"


//在蛇的前端添加新的节点
void addFirst() {
    int newX = mySnake->head->x_axis;
    int newY = mySnake->head->y_axis;

    // 根据当前方向决定新节点的位置
    switch (mySnake->direction) {
    case 0: newY -= 1; break; // 向上
    case 1: newX += 1; break; // 向右
    case 2: newY += 1; break; // 向下
    case 3: newX -= 1; break; // 向左
    }

    Node* newNode = new Node(newX, newY, mySnake->head);
    mySnake->head = newNode;
}

//去掉蛇末尾的节点
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

//控制蛇向前移动的函数
//将addFirst和removeLast结合起来用
void snakeMove() {
    addFirst();
    removeLast();
}

//检测蛇有没有死亡的函数
bool isSnakeDead() {
    // 检测蛇头是否撞墙
    if (mySnake->head->x_axis < 0 || mySnake->head->x_axis > 30 ||
        mySnake->head->y_axis < 0 || mySnake->head->y_axis > 30) {
        return true;
    }

    // 检测蛇头是否撞到自己
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

//让蛇加速的程序
void accelerateSnake() {
    mySnake->speed++;
}

//让蛇左转的程序
void snakeTurnLeft() {

}

//让蛇右转的程序
void snakeTurnRight() {
	
}

void changeDirection(char key) {
    //结合turnleft\turnright
}

//检测蛇头有没有吃到食物（与食物坐标重叠）
//该函数被包含在了头文件Food.h中
bool isFoodEaten(Food* food)
{
    if (mySnake->head->x_axis == food->xcoord && mySnake->head->y_axis == food->ycoord)
    {
        return true;
    }
    return false;
}