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
#include "Food.h"
#include <conio.h>  // 用于检测键盘输入


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
    Node* prev = mySnake->head;
    while (prev->nextNode && prev->nextNode != mySnake->end) {
        prev = prev->nextNode;
    }

    mySnake->lastX = mySnake->end->x_axis;
    mySnake->lastY = mySnake->end->y_axis;

    mySnake->end = prev;
    delete mySnake->end->nextNode;
    mySnake->end->nextNode = nullptr;
}

//控制蛇向前移动的函数
//将addFirst和removeLast结合起来用
void snakeMove() {
    addFirst();
    removeLast();
}
//根据键盘输入改变direction的函数
void changeDirection(Snake* snake) {
    if (_kbhit()) {  // 如果有键盘输入
        char key = _getch();  // 获取键盘输入字符

        switch (key) {
        case 'w': case 'W':
            if (snake->direction != 2)  
                snake->direction = 0;
            break;
        case 'd': case 'D':
            if (snake->direction != 3)
                snake->direction = 1;
            break;
        case 's': case 'S':
            if (snake->direction != 0)
                snake->direction = 2;
            break;
        case 'a': case 'A':
            if (snake->direction != 1)
                snake->direction = 3;
            break;
        }
    }
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