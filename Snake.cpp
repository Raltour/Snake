/*
* 本文件包含：
*snake的结构体
*蛇移动的函数
*检测有没有死亡的函数
*调整蛇移动速度的函数
*吃到食物延长的函数 
* 几个辅助函数，作用链表头部增加节点、链表尾部删除节点
* 
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
    snake.length++;
}

//去掉蛇末尾的节点
void removeLast(Snake& snake) {
    if (!snake.end) return;

    Node* prev = snake.head;
    while (prev->nextNode && prev->nextNode != snake.end) {
        prev = prev->nextNode;
    }

    delete snake.end;
    snake.end = prev;
    snake.end->nextNode = nullptr;
    snake.length--;
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
void snakeTurnLeft(Snake* snake) {

}

//让蛇右转的程序
void snakeTurnRight(Snake* snake) {
	
}

//检测蛇头有没有吃到食物（与食物坐标重叠）
bool isFoodEaten(Snake* snake, Food* food)
{
    if (snake->head->x_axis == food->xcoord && snake->head->y_axis == food->ycoord)
    {
        return true;
    }
    return false;
}