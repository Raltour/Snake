// 在蛇的前端添加新的节点
void addFirst(Snake& snake) {
    int newX = snake.head->x_axis;
    int newY = snake.head->y_axis;

    // 根据当前方向决定新节点的位置
    switch (snake.direction) {
    case 0: newY -= 1; break; // 向上
    case 1: newX += 1; break; // 向右
    case 2: newY += 1; break; // 向下
    case 3: newX -= 1; break; // 向左
    }

    Node* newNode = new Node(newX, newY, snake.head);
    snake.head = newNode;
    snake.length++;
}

// 去掉蛇末尾的节点
void removeLast(Snake& snake) {
    if (!snake.end) return;

    Node* prev = snake.head;
    while (prev->nextNode && prev->nextNode != snake.end) {
        prev = prev->nextNode;
    }

    delete snake.end;
    snake.end = prev;
    snake.end->nextNode = nullptr;
    snake.length--;
}

// 控制蛇向前移动的函数
void snakeMove(Snake* snake) {
    addFirst(*snake);
    removeLast(*snake);
}

// 检测蛇是否死亡的函数
bool isSnakeDead(Snake* snake) {
    // 检测蛇头是否撞墙
    if (snake->head->x_axis < 0 || snake->head->x_axis > 30 ||
        snake->head->y_axis < 0 || snake->head->y_axis > 30) {
        return true;
    }

    // 检测蛇头是否撞到自己
    Node* current = snake->head->nextNode;
    while (current) {
        if (current->x_axis == snake->head->x_axis &&
            current->y_axis == snake->head->y_axis) {
            return true;
        }
        current = current->nextNode;
    }

    return false;
}

