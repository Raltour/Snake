#Snake

规则：
吃食物增加身体长度
撞墙或者撞到身体死亡

对象：蛇、食物、方块、坐标、背景

游戏逻辑功能：
按键操控方向
蛇的移动
吃食物、增长
随机刷新食物
撞墙死亡
撞到身体死亡
计分(最终长度）
增加速度

显示模块
功能：刷新界面
传参：蛇、食物、基本背景信息
每次界面变动后立刻刷新一帧

蛇的实现？：链表（双端？）尾部多一个节点
节点：横坐标、纵坐标、下一个节点
蛇：head、end、length、lastEnd、direction、speed

怎么让食物出现在没有蛇的地方？
（游戏后期 随机 + 遍历蛇效率很低）
为了保证蛇吃掉食物后正常增长，建议在蛇的结构体内添加一个虚节点，记录尾部上一时刻的位置


main函数伪代码：
Init {
    printBoard
    Create new snake
    Genetate new food
    Score = 0
}

while {
    if (getKey(检测输入) {
        Change(snake.direction)
    }
    
    Snake.move
    if (dead) {
        Gameover
        break
    }
    if（eat food) {
        Length++
        Generate new food
    }
    showBoard(刷新一帧）、
    
    Speed ->{
        Length > 20
        Pause.time--
    }   

    pause
}
Show score



