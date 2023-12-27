#include <iostream>
#include <cstdlib>
#include <ctime>
extern int board[4][4];
extern int step;
extern int score;
extern void display();
extern void add_element();

using namespace std;

void move_left();
void move_right();
void move_up();
void move_down();