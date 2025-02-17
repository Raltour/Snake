//蛇的初始长度设定为2，朝下
#define INITIAL_LENGTH 2
//蛇的初始方向，直接用0、1、2、3代表四个方向
#define INITIAL_DIRECTION 1
//蛇的初始位置
#define INITIAL_PLACE_X 10
#define INITIAL_PLACE_Y 10

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
	Node* lastEnd;

	int length;
	int direction;

	//新建一个蛇时采用的默认构造函数
	Snake() {
		end = new Node(INITIAL_PLACE_X, INITIAL_PLACE_Y - 1, nullptr);
		head = new Node(INITIAL_PLACE_X, INITIAL_PLACE_Y, end);
		lastEnd = end;
		head->nextNode = end;
		length = INITIAL_LENGTH;
		direction = INITIAL_DIRECTION;
	}
};
#endif

extern Snake* mySnake;
void snakeMove();
bool isSnakeDead();
void changeDirection();
void snakeTurnLeft();//测试，以后删掉
void snakeTurnRight();//测试，以后删掉