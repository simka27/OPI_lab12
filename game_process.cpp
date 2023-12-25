#include "game_process.h"

//move functions
void move_left() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 0; j < 4; j++)
        {
            if (n == board[i][j] && n != 0) {
                board[i][prev] = 2 * n;
                board[i][j] = 0;
                score += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j] != 0) {
                n = board[i][j];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (board[i][k] == 0 && board[i][k + 1] != 0) {
                    board[i][k] = board[i][k] ^ board[i][k + 1];
                    board[i][k + 1] = board[i][k] ^ board[i][k + 1];
                    board[i][k] = board[i][k] ^ board[i][k + 1];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        add_element();
        step++;
    }
    display();
}

void move_right() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (n == board[i][j] && n != 0) {
                board[i][prev] = 2 * n;
                board[i][j] = 0;
                score += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j] != 0) {
                n = board[i][j];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 3; k > 0; k--) {
                if (board[i][k] == 0 && board[i][k - 1] != 0) {
                    board[i][k] = board[i][k] ^ board[i][k - 1];
                    board[i][k - 1] = board[i][k] ^ board[i][k - 1];
                    board[i][k] = board[i][k] ^ board[i][k - 1];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        add_element();
        step++;
    }
    display();
}

void move_up() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 0; j < 4; j++)
        {
            if (n == board[j][i] && n != 0) {
                board[prev][i] = 2 * n;
                board[j][i] = 0;
                score += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[j][i] != 0) {
                n = board[j][i];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (board[k][i] == 0 && board[k + 1][i] != 0) {
                    board[k][i] = board[k][i] ^ board[k + 1][i];
                    board[k + 1][i] = board[k][i] ^ board[k + 1][i];
                    board[k][i] = board[k][i] ^ board[k + 1][i];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        add_element();
        step++;
    }
    display();
}

void move_down() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (n == board[j][i] && n != 0) {
                board[prev][i] = 2 * n;
                board[j][i] = 0;
                score += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[j][i] != 0) {
                n = board[j][i];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 3; k > 0; k--) {
                if (board[k][i] == 0 && board[k - 1][i] != 0) {
                    board[k][i] = board[k][i] ^ board[k - 1][i];
                    board[k - 1][i] = board[k][i] ^ board[k - 1][i];
                    board[k][i] = board[k][i] ^ board[k - 1][i];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        add_element();
        step++;
    }
    display();
}