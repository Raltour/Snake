//蛇的初始长度设定为2
#define INITIAL_LENGTH 2
//蛇的初始速度？我也不知道这里用多少，随便用一个数字
#define INITIAL_SPEED 10
//蛇的初始方向，直接用0、1、2、3代表四个方向
#define INITIAL_DIRECTION 0
//蛇的初始位置
#define INITIAL_PLACE_X 10
#define INITIAL_PLACE_Y 10

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

struct Snake {
	Node* head;
	Node* end;

	int length;
	int speed;
	int direction;

	//新建一个蛇时采用的默认构造函数
	Snake() {
		head = new Node(INITIAL_PLACE_X, INITIAL_PLACE_Y, nullptr);
		end = new Node(INITIAL_PLACE_X - 1, INITIAL_PLACE_Y + 1, nullptr);
		head->nextNode = end;
		length = INITIAL_LENGTH;
		speed = INITIAL_SPEED;
		direction = 1;
	}
};

void snakeMove(Snake snake);

bool isSnakeDead(Snake snake);

void accelerateSnake(Snake* snake);