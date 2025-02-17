#ifndef NODE_H
#define NODE_H
struct Node {
	int x_axis;
	int y_axis;
	Node* nextNode;

	//默认构造函数
	Node() : x_axis(0), y_axis(0), nextNode(nullptr) {}

	//带参数的构造函数
	Node(int x, int y, Node* next)
		: x_axis(x), y_axis(y), nextNode(next) {}
};
#endif

#ifndef SNAKE_H
#define SNAKE_H
struct Snake {
	Node* head;
	Node* end;
	int lastX;
	int lastY;

	int length;
	int direction;

	//新建一个蛇时采用的默认构造函数
	Snake() {
		end = new Node(10, 9, nullptr);
		head = new Node(10, 10, end);
		lastX = 10;
		lastY = 8;
		head->nextNode = end;
		length = 2;
		direction = 2;
	}
};
#endif

extern Snake* mySnake;
void snakeMove();
bool isSnakeDead();
void changeDirection();
void snakeTurnLeft();//测试，以后删掉
void snakeTurnRight();//测试，以后删掉