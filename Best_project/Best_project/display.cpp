#include "display.h"

//show game board
void display() {
    int index_i1, index_j1, index_i2, index_j2;
    //test duplication
    while (1) {
        index_i1 = random_index_generate();
        index_j1 = random_index_generate();
        index_i2 = random_index_generate();
        index_j2 = random_index_generate();
        if (index_i1 == index_i2 && index_j1 == index_j2) {
            continue;
        }
        else
            break;
    }
    //initialize
    if (step == 0) {
        title();
        for (int i = 0; i < 4; i++) {
            cout << "|-----------------------|" << endl;
            for (int j = 0; j < 4; j++) {
                cout << "|";
                if (i == index_i1 && j == index_j1) {
                    board[i][j] = 2;
                    cout << "  " << 2 << "  ";
                }
                else if (i == index_i2 && j == index_j2) {
                    int temp = new_random_element();
                    board[i][j] = temp;
                    cout << "  " << temp << "  ";
                }
                else
                    cout << "     ";
            }
            cout << "|" << endl;
        }
        cout << "|-----------------------|" << endl;
    }
    //redisplay
    else {
        for (int i = 0; i < 4; i++) {
            cout << "|-----------------------|" << endl;
            for (int j = 0; j < 4; j++) {
                cout << "|";
                if (board[i][j] != 0) {
                    if (board[i][j] == 1024 || board[i][j] == 2048)
                        cout << " " << board[i][j];
                    if (board[i][j] == 128 || board[i][j] == 256 || board[i][j] == 512)
                        cout << " " << board[i][j] << " ";
                    if (board[i][j] == 16 || board[i][j] == 32 || board[i][j] == 64)
                        cout << "  " << board[i][j] << " ";
                    if (board[i][j] == 2 || board[i][j] == 4 || board[i][j] == 8)
                        cout << "  " << board[i][j] << "  ";
                }
                else
                    cout << "     ";
            }
            cout << "|" << endl;
        }
        cout << "|-----------------------|" << endl;
    }
    //cout<<"step "<<step<<endl;
}