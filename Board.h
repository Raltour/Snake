#ifndef BOARD_H
#define BOARD_H

void block(int xcoord, int ycoord);
void food(int xcoord, int ycoord);
void score(int score);

void initBoard();

void refreshBoard(Snake* snake, Food* food，int currentscore);

bool hasKeyInput();
char getKey();//有时间研究下怎么搞这个


#endif // BOARD_H