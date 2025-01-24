//�ƶ���
void moveSnake()
{
	int newX = snakeHead->x;
	int newY = snakeHead->y;

	//���ݵ�ǰ���������ͷ����
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

	//�����µ���ͷ�Ľڵ�
	SnakeSegment* newHead = new SnakeSegment{ newX ,newY ,snakeHead };
	snakeHead = newHead;

	//����Ե�ʳ���ɾ����β
	if (isFoodEaten())
	{
		generateFood();
	}
	else
	{
		//ɾ����β��û�Ե�ʳ�
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




//�ж��Ƿ�Ե�ʳ��
bool isFoodEaten()
{
	if (snakeHead->x == foodX && snakeHead->y == foodY)
	{
		return true;
	}
	return false;
}

//�����ײ��ǽ���Լ���
bool isCollision()
{
	//�Ƿ�ײǽ
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