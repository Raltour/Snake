#include <time.h>

// 自定义的一个延时函数delay()
void delay(int seconds) //  参数必须为整型，表示延时多少秒
{
    clock_t start = clock();
    clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;
    while ((clock() - start) < lay);
}


void delay(double seconds) //  参数为双精度浮点型，重载一下。
{
    double start = clock();
    double lay = (double)seconds * CLOCKS_PER_SEC;
    while ((clock() - start) < lay);
}
