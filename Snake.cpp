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


struct Node {
	int x_axis;
	int y_axis;
	Node *nextNode;

	//默认构造函数
	Node() : x_axis(0), y_axis(0), nextNode(nullptr) {}

	//带参数的构造函数
	Node(int x, int y, Node* next)
		: x_axis(x), y_axis(y), nextNode(next) {}
};

struct Snake {
	Node *head;
	Node *end;

	int length;
	int speed;

	//新建一个蛇时采用的默认构造函数
	Snake() {
		*head = Node(INITIAL_PLACE_X, INITIAL_PLACE_Y, nullptr);
		*end = Node(INITIAL_PLACE_X - 1, INITIAL_PLACE_Y + 1, nullptr);
		head->nextNode = end;
		length = INITIAL_LENGTH;
		speed = INITIAL_SPEED;	
	}
};

//构造一个新的蛇
Snake creatNewSnake() {
	return Snake();
}

//在蛇的前端添加新的节点
void addFirst(Snake snake) {

}

//去掉蛇末尾的节点
void removeLast(Snake snake) {

}

//控制蛇向前移动的函数
//将addFirst和removeLast结合起来用
void snakeMove(Snake snake) {

}

//检测蛇有没有死亡的函数
bool isSnakeDead(Snake snake) {
	return false;
}

//让蛇加速的程序
void accelerateSnake(Snake *snake) {
	snake->speed++;
}