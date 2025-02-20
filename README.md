# Snake 贪吃蛇
***
## 规则：
吃食物增加身体长度  
撞墙或者撞到身体死亡
***
## 对象：蛇、食物、图形
***
## 逻辑功能：  
按键操控方向  
蛇的移动  
吃食物、增长  
随机刷新食物  
撞墙死亡  
撞到身体死亡
***
## 显示模块  
功能：刷新界面  
传参：蛇、食物、基本背景信息  
每次界面变动后立刻刷新一帧
***
## 蛇的实现：
为了便于传参，采取带有外部链接的静态变量（全局变量）  
采用链表进行实现，每次移动时，只需要头部增加新节点，尾部删去旧节点  
为了保证蛇吃掉食物后正常增长，在蛇的结构体内记录尾部上一时刻的位置
***
## main函数伪代码：

    int main(void) {

        initBoard
        genetate new food
        refresh

        while {
            changeDirection

            Snake.move

            if (dead) {
                break
            }

            if（eat food) {
                end = new_end
                length++
                generate new_food
            }

            showBoard(刷新一帧）

            time_pause
        } 
        
        closegraph

        return 0
    }