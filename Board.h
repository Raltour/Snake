#ifndef BOARD_H
#define BOARD_H

void block(int xcoord, int ycoord);
void food(int xcoord, int ycoord);

void initBoard();

void refreshBoard(Snake* snake, Food* food);

bool hasKeyInput();
char getKey();//有时间研究下怎么搞这个


#endif // BOARD_H
