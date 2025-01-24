//移动蛇
void moveSnake()
{
	int newX = snakeHead->x;
	int newY = snakeHead->y;

	//根据当前方向更新蛇头坐标
	if (currentDirection == 'R')
	{
		newX += 1;
	}
	else if (currentDirection == 'L')
	{
		newX -= 1;
	}
	else if (currentDirection == 'D')
	{
		newY += 1;
	}
	else if (currentDirection == 'U')
	{
		newY -= 1;
	}

	//创建新的蛇头的节点
	SnakeSegment* newHead = new SnakeSegment{ newX ,newY ,snakeHead };
	snakeHead = newHead;

	//如果吃到食物，不删除蛇尾
	if (isFoodEaten())
	{
		generateFood();
	}
	else
	{
		//删除蛇尾（没吃到食物）
		SnakeSegment* temp = snakeHead;
		while (temp->next != nullptr && temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		if (temp->next != nullptr)
		{
			delete temp->next;
			temp->next = nullptr;
		}
	}
}




//判断是否吃到食物
bool isFoodEaten()
{
	if (snakeHead->x == foodX && snakeHead->y == foodY)
	{
		return true;
	}
	return false;
}

//检测碰撞（墙或自己）
bool isCollision()
{
	//是否撞墙
	if (snakeHead->x <= 0 || snakeHead->x >= WIDTH - 1 ||
		snakeHead->y <= 0 || snakeHead->y >= HEIGHT - 1)
	{
		return true;
	}
	SnakeSegment* current = snakeHead->next;
	while (current != nullptr)
	{
		if (snakeHead->x == current->x && snakeHead->y == current->y)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}