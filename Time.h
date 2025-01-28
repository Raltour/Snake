#include <time.h>

// �Զ����һ����ʱ����delay()
void delay(int seconds) //  ��������Ϊ���ͣ���ʾ��ʱ������
{
    clock_t start = clock();
    clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;
    while ((clock() - start) < lay);
}


void delay(double seconds) //  ����Ϊ˫���ȸ����ͣ�����һ�¡�
{
    double start = clock();
    double lay = (double)seconds * CLOCKS_PER_SEC;
    while ((clock() - start) < lay);
}
