#ifndef FOOD_H
#define FOOD_H

struct Food
{
	int xcoord;
	int ycoord;

	Food() : xcoord(0), ycoord(0) {}
	Food(int x, int y) : xcoord{ x }, ycoord{ y } {}
};

#endif // FOOD_H

Food* generateFood(Snake snake);