#include "Best_project.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "display.h"
#include "game_process.h"


using namespace std;

int MAX = 2048;
int board[4][4] = { 0 };
int step;
int score;

int random_index_generate() {
    int random_index = rand() % 4;
    return random_index;
}


int is_win() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == MAX) {
                return 1;
            }
        }
    }
    return 0;
}

int new_random_element() {
    int random_element = rand() % 10;
    random_element = (random_element == 0) ? 4 : 2;
    return random_element;
}
//win or lose check


int game_over() {
    int is_game_over = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0 || board[i][j + 1] == 0 || board[i][j] == board[i][j + 1]) {
                is_game_over = 0;
                break;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (board[i][j] == 0 || board[i + 1][j] == 0 || board[i][j] == board[i + 1][j]) {
                is_game_over = 0;
                break;
            }
        }
    }
    return is_game_over;
}

//insert random element
void add_element() {
    int index_i3, index_j3;
    int flag = 0;
    while (1) {
        if (flag == 1)break;
        index_i3 = random_index_generate();
        index_j3 = random_index_generate();
        if (board[index_i3][index_j3] == 0) {
            board[index_i3][index_j3] = new_random_element();
            flag = 1;
        }
    }
}

void title() {
    cout << "------2048------" << endl;
    cout << "Rules:" << endl;
    cout << "Use w(up), s(down), a(left), d(right) keys to move the tiles in certain direction" << ", ";
    cout << "Use 'q' to exit" << endl;
    cout << "Double up and merge titles with the same number touch" << endl << endl;
}

int mainttfe() {
    system("color B9");
    srand((unsigned)time(NULL));
    char ch, c;
    cout << "------2048------" << endl;
    cout << "Hi! Press any button to start the game or 'q' to exit" << endl;
    cin >> ch;
    system("cls");
    if (ch == 'q') {
        exit(1);
    }
    //initialize board
    display();
    while (1) {
        if (is_win()) {
            cout << step << " steps" << endl;
            cout << "!!!YOU WIN!!!" << endl;
            exit(1);
        }
        if (game_over()) {
            cout << "~~~GAME OVER~~~" << endl;
            exit(2);
        }
        cin >> ch;
        switch (ch) {
        case 'w':
            system("cls");
            title();
            move_up();
            break;
        case 's':
            system("cls");
            title();
            move_down();
            break;
        case 'a':
            system("cls");
            title();
            move_left();
            break;
        case 'd':
            system("cls");
            title();
            move_right();
            break;
        case 'q':
            exit(1);
        default:
            break;
        }
        //show current scores
        cout << "score: " << score << endl;
    }
    return 0;
}