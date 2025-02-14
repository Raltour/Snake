#ifndef BOARD_H
#define BOARD_H

void block(int xcoord, int ycoord);

void initBoard();

void refreshBoard(Snake* snake, Food* food);

#endif // BOARD_H
