//为保持程序健壮性，头文件里只放可以公开访问的内容，私有辅助模块不要写在头文件里

//蛇的初始长度设定为2
#define INITIAL_LENGTH 2
//蛇的初始速度？我也不知道这里用多少，随便用一个数字
#define INITIAL_SPEED 10
//蛇的初始方向，直接用0、1、2、3代表四个方向
#define INITIAL_DIRECTION 0
//蛇的初始位置
#define INITIAL_PLACE_X 10
#define INITIAL_PLACE_Y 10

typedef struct Snake;

void snakeMove(Snake snake);

bool isSnakeDead(Snake snake);

void accelerateSnake(Snake* snake);