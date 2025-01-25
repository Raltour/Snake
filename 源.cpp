// ���ߵ�ǰ������µĽڵ�
void addFirst(Snake& snake) {
    int newX = snake.head->x_axis;
    int newY = snake.head->y_axis;

    // ���ݵ�ǰ��������½ڵ��λ��
    switch (snake.direction) {
    case 0: newY -= 1; break; // ����
    case 1: newX += 1; break; // ����
    case 2: newY += 1; break; // ����
    case 3: newX -= 1; break; // ����
    }

    Node* newNode = new Node(newX, newY, snake.head);
    snake.head = newNode;
    snake.length++;
}

// ȥ����ĩβ�Ľڵ�
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

// ��������ǰ�ƶ��ĺ���
void snakeMove(Snake* snake) {
    addFirst(*snake);
    removeLast(*snake);
}

// ������Ƿ������ĺ���
bool isSnakeDead(Snake* snake) {
    // �����ͷ�Ƿ�ײǽ
    if (snake->head->x_axis < 0 || snake->head->x_axis > 30 ||
        snake->head->y_axis < 0 || snake->head->y_axis > 30) {
        return true;
    }

    // �����ͷ�Ƿ�ײ���Լ�
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

