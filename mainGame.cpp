/*
* 游戏的主程序模块
*/

#include <easyx.h>
#include "Block.h"
#include "Snake.h"

int main(void) {

	Snake *mySnake = new Snake();



	delete mySnake;
	return 0;
}