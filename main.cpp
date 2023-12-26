#include <iostream>
#include <Windows.h>

//сдвиг курсора кансоли в начало, чтобы не было кинопрёнки
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

using namespace std;

//размер поля и макс длина змейки
const int WIDTH = 17;
const int HEIGHT = 10;
const int MAX_LEN_SNAKE = (WIDTH - 3) * (HEIGHT - 2);

//направление
const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int snake_dir = UP;

//игра идёт или закончена
bool isRunning = true;

char map[] =
"################\n"
"#              #\n"
"#              #\n"
"#              #\n"
"#              #\n"
"#              #\n"
"#              #\n"
"#              #\n"
"#              #\n"
"################\n";

//символ змейки
char snake = 'O';

//массивы для хранения каждого блока змейки
int snake_x[MAX_LEN_SNAKE] = {0};
int snake_y[MAX_LEN_SNAKE] = {0};
int snake_len = 1;//длина змейки
//координаты еды
int food_x = 1 + (rand() % (WIDTH - 3));
int food_y = 1 + (rand() % (HEIGHT - 3));
char food = '*';

int main()
{
	//определение головы
	snake_x[0] = WIDTH / 2;
	snake_y[0] = HEIGHT / 2;

	double  time = clock();//делаем процессорное время(тик)
	//движение
	while (isRunning) {
		if (GetKeyState('A') & 0x8000) {
			if (snake_dir != RIGHT) {
				snake_dir = LEFT;
			}
		}
		if (GetKeyState('W') & 0x8000) {
			if (snake_dir != DOWN) {
				snake_dir = UP;
			}
		}
		if (GetKeyState('S') & 0x8000) {
			if (snake_dir != UP) {
				snake_dir = DOWN;
			}
		}
		if (GetKeyState('D') & 0x8000) {
			if (snake_dir != LEFT) {
				snake_dir = RIGHT;
			}
		}
		


		if ((clock() - time) / CLOCKS_PER_SEC >= 0.3) {
			time = clock();//разрешаем заходить в цикл 1 раз в 1 сек

			if (snake_x[0] == food_x && snake_y[0] == food_y) {//увеличение змейки и спавн еды
				++snake_len;
				food_x = 1 + (rand() % (WIDTH - 3));
				food_y = 1 + (rand() % (HEIGHT - 3));
			}

			for (int i = snake_len - 2; i >= 0; --i) {
				snake_x[i + 1] = snake_x[i];
				snake_y[i + 1] = snake_y[i];
			}
			//направление
			if (snake_dir == UP) {
				--snake_y[0];
			}
			if (snake_dir == DOWN) {
				++snake_y[0];
			}
			if (snake_dir == LEFT) {
				--snake_x[0];
			}
			if (snake_dir == RIGHT) {
				++snake_x[0];
			}

			//окно gameover
			if (snake_x[0] == 0 || snake_y[0] == 0 || snake_x[0] == WIDTH - 2 || snake_y[0] == HEIGHT - 1) {
				isRunning = false;
			}
			if (GetKeyState('Q') & 0x8000)
				isRunning = false;

			//пересечение змейки
			for (int i = 1; i < snake_len; i++) {
				if (snake_x[0] == snake_x[i] && snake_y[0] == snake_y[i]) {
					isRunning = false;
					i = snake_len;
				}
			}

			gotoxy(0, 0);
			cout << "Length: " << snake_len << endl;//вывод лоины змейки

			map[food_y * WIDTH + food_x] = food;

			for (int i = 0; i < snake_len; i++) {
				map[snake_y[i] * WIDTH + snake_x[i]] = snake;
			}
			cout << map;
			for (int i = 0; i < snake_len; i++) { //очищение змейки с буфера карты
				map[snake_y[i] * WIDTH + snake_x[i]] = ' ';
			}
		}
	}
	gotoxy(1, HEIGHT / 2);
	cout << "YOU SCORE IS " << snake_len;
	gotoxy(WIDTH, HEIGHT);
}