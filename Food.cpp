/*
* 包含食物的定义、食物随机刷新的函数
* 
*/

#include "Block.h"
#include "Food.h"
#include <easyx.h>


Food createFood() {
	int x = 0;
	int y = 0;
	return Food(x, y);
}

void drawFood(Food food) {
	//该函数传进来一个food结构体，把它打印在界面上，用作board的刷新
}

