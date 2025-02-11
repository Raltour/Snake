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
void addFirst(Snake& snake) {
    int newX = snake.head->x_axis;
    int newY = snake.head->y_axis;

    // 根据当前方向决定新节点的位置
    switch (snake.direction) {
    case 0: newY -= 1; break; // 向上
    case 1: newX += 1; break; // 向右
    case 2: newY += 1; break; // 向下
    case 3: newX -= 1; break; // 向左
    }

    Node* newNode = new Node(newX, newY, snake.head);
    snake.head = newNode;
}

//去掉蛇末尾的节点
void removeLast(Snake& snake) {
    if (!snake.end) return;

    snake.lastEnd = snake.end;

    Node* prev = snake.head;
    while (prev->nextNode && prev->nextNode != snake.end) {
        prev = prev->nextNode;
    }

    delete snake.end;
    snake.end = prev;
    snake.end->nextNode = nullptr;
}

//控制蛇向前移动的函数
//将addFirst和removeLast结合起来用
void snakeMove(Snake* snake) {
    addFirst(*snake);
    removeLast(*snake);
}

//检测蛇有没有死亡的函数
bool isSnakeDead(Snake* snake) {
    // 检测蛇头是否撞墙
    if (snake->head->x_axis < 0 || snake->head->x_axis > 30 ||
        snake->head->y_axis < 0 || snake->head->y_axis > 30) {
        return true;
    }

    // 检测蛇头是否撞到自己
    Node* current = snake->head->nextNode;
    while (current) {
        if (current->x_axis == snake->head->x_axis &&
            current->y_axis == snake->head->y_axis) {
            return true;
        }
        current = current->nextNode;
    }

    return false;
}

//让蛇加速的程序
void accelerateSnake(Snake *snake) {
	snake->speed++;
}

//让蛇左转的程序
void snakeTurnLeft() {
    int newX = mySnake->head->x_axis;
    int newY = mySnake->head->y_axis;

    // 根据当前方向决定新节点的位置
    switch (mySnake->direction) {
    case 0: newX -= 1; break; //向上时左转，以下同理
    case 1: newY -= 1; break; // 向右
    case 2: newX += 1; break; // 向下
    case 3: newY += 1; break; // 向左
    }

    Node* newNode = new Node(newX, newY, mySnake->head);
    mySnake->head = newNode;
    mySnake->direction = (mySnake->direction + 3) % 4;
}


//让蛇右转的程序
void snakeTurnRight() {
    int newX = mySnake->head->x_axis;
    int newY = mySnake->head->y_axis;

    // 根据当前方向决定新节点的位置
    switch (mySnake->direction) {
    case 0: newX += 1; break; //向上时右转，以下同理
    case 1: newY += 1; break; // 向右
    case 2: newX -= 1; break; // 向下
    case 3: newY -= 1; break; // 向左
    }

    Node* newNode = new Node(newX, newY, mySnake->head);
    mySnake->head = newNode;
    mySnake->direction = (mySnake->direction + 1) % 4;
}

//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
//include<windows.h>
void changeDirection(char key) {//没想明白函数的输入怎么写
    int newdirection;
    if （！KEY_DOWN（87））
        newdirection = 0;
    else if (！KEY_DOWN（68)
        newdirection = 1;
    else if (！KEY_DOWN（83)
        newdirection = 2;
    else if (！KEY_DOWN（65)
        newdirection = 3;

    if (mySnake->direction == (newdirection + 1) % 4)
        snakeTurnLeft();
    else if (mySnake->direction == (newdirection + 3) % 4)
        snakeTurnRight();

    //结合turnleft\turnright
}

//检测蛇头有没有吃到食物（与食物坐标重叠）
//该函数被包含在了头文件Food.h中
bool isFoodEaten(Snake* snake, Food* food)
{
    if (snake->head->x_axis == food->xcoord && snake->head->y_axis == food->ycoord)
    {
        return true;
    }
    return false;
}
