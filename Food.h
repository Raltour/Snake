struct Food
{
	int xcoord;
	int ycoord;

	Food() : xcoord(0), ycoord(0) {}
	Food(int x, int y) : xcoord{ x }, ycoord{ y } {}
};

Food createFood();
void drawFood(Food food);

