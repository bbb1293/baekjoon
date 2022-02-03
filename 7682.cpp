#include <bits/stdc++.h>

using namespace std;

char state[10];

int who_win() {
    int ret = 0;

    for (int i = 0; i < 3; i++) {
        if ((state[i] != '.') && (state[i] == state[i + 3]) &&
            (state[i] == state[i + 6])) {
            ret++;
        }
    }

    for (int i = 0; i < 9; i += 3) {
        if ((state[i] != '.') && (state[i] == state[i + 1]) &&
            state[i] == state[i + 2]) {
            ret++;
        }
    }

    if (state[4] != '.') {
        if ((state[0] == state[4]) && (state[0] == state[8])) {
            ret++;
        }
        if ((state[2] == state[4]) && (state[2] == state[6])) {
            ret++;
        }
    }
    return ret;
}

bool go_prev(char turn) {
    bool fin = true;
    for (int i = 0; i < 9; i++) {
        if (state[i] != '.') {
            fin = false;
            break;
        }
    }

    if (fin) {
        return true;
    }

    if (who_win()) {
        return false;
    }

    char next_turn = (turn == 'X') ? 'O' : 'X';

    bool ret = false;
    for (int i = 0; i < 9; i++) {
        if (state[i] == turn) {
            state[i] = '.';
            ret |= go_prev(next_turn);
            state[i] = turn;
        }
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    while (true) {
        scanf(" %s", state);

        if (state[0] == 'e') {
            break;
        }

        int x_cnt = 0, o_cnt = 0;

        for (int i = 0; i < 9; i++) {
            if (state[i] == 'X') {
                x_cnt++;
            } else if (state[i] == 'O') {
                o_cnt++;
            }
        }

        if ((who_win() || ((x_cnt + o_cnt) == 9)) &&
            ((x_cnt == o_cnt) || (x_cnt == o_cnt + 1))) {
            char turn = (x_cnt == o_cnt) ? 'O' : 'X';
            char next_turn = (turn == 'O') ? 'X' : 'O';

            bool ret = false;
            for (int i = 0; i < 9; i++) {
                if (state[i] == turn) {
                    state[i] = '.';
                    ret |= go_prev(next_turn);
                    state[i] = turn;
                }
            }
            if (ret) {
                printf("valid\n");
            } else {
                printf("invalid\n");
            }

        } else {
            printf("invalid\n");
        }
    }

    return 0;
}