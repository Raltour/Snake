//Ϊ���ֳ���׳�ԣ�ͷ�ļ���ֻ�ſ��Թ������ʵ����ݣ�˽�и���ģ�鲻Ҫд��ͷ�ļ���

//�ߵĳ�ʼ�����趨Ϊ2
#define INITIAL_LENGTH 2
//�ߵĳ�ʼ�ٶȣ���Ҳ��֪�������ö��٣������һ������
#define INITIAL_SPEED 10
//�ߵĳ�ʼ����ֱ����0��1��2��3�����ĸ�����
#define INITIAL_DIRECTION 0
//�ߵĳ�ʼλ��
#define INITIAL_PLACE_X 10
#define INITIAL_PLACE_Y 10

typedef struct Snake;

void snakeMove(Snake snake);

bool isSnakeDead(Snake snake);

void accelerateSnake(Snake* snake);