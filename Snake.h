//�ߵĳ�ʼ�����趨Ϊ2
#define INITIAL_LENGTH 2
//�ߵĳ�ʼ�ٶȣ���Ҳ��֪�������ö��٣������һ������
#define INITIAL_SPEED 10
//�ߵĳ�ʼ����ֱ����0��1��2��3�����ĸ�����
#define INITIAL_DIRECTION 0
//�ߵĳ�ʼλ��
#define INITIAL_PLACE_X 10
#define INITIAL_PLACE_Y 10

#ifndef NODE_H
#define NODE_H
struct Node {
	int x_axis;
	int y_axis;
	Node* nextNode;

	//Ĭ�Ϲ��캯��
	Node() : x_axis(0), y_axis(0), nextNode(nullptr) {}

	//�������Ĺ��캯��
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
	int speed;
	int direction;

	//�½�һ����ʱ���õ�Ĭ�Ϲ��캯��
	Snake() {
		head = new Node(INITIAL_PLACE_X, INITIAL_PLACE_Y, nullptr);
		end = new Node(INITIAL_PLACE_X - 1, INITIAL_PLACE_Y + 1, nullptr);
		lastEnd = end;
		head->nextNode = end;
		length = INITIAL_LENGTH;
		speed = INITIAL_SPEED;
		direction = 1;
	}
};
#endif

void snakeMove(Snake *snake);
bool isSnakeDead(Snake *snake);
void accelerateSnake(Snake *snake);
void changeDirection(Snake *snake, char key);
void snakeTurnLeft(Snake* snake);//���ԣ��Ժ�ɾ��
void snakeTurnRight(Snake* snake);//���ԣ��Ժ�ɾ��