#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9, MAXK = 1e5;
int n, k;
int k_y, k_x;
int dir_x[] = {0, 1, 1, 0, -1, -1, -1, 0, 1},
    dir_y[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
bool dead[9];

bool is_dead(int cur_y, int cur_x, int q_y, int q_x) {
    if (cur_y <= 0 || cur_x <= 0 || cur_y > n ||
        cur_x > n) {
        return true;
    }

    if (cur_y == q_y || cur_x == q_x) {
        return true;
    }

    if ((cur_y - cur_x == q_y - q_x) ||
        (cur_y + cur_x == q_y + q_x)) {
        return true;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);
    scanf("%d %d", &k_y, &k_x);

    while (k--) {
        int q_y, q_x;
        scanf("%d %d", &q_y, &q_x);

        for (int dir = 0; dir < 9; dir++) {
            int cur_y = k_y + dir_y[dir],
                cur_x = k_x + dir_x[dir];

            dead[dir] |= is_dead(cur_y, cur_x, q_y, q_x);
        }
    }

    bool all_dead = true;
    for (int i = 1; i < 9; i++) {
        all_dead &= dead[i];
    }

    if (dead[0]) {
        if (all_dead) {
            printf("CHECKMATE");
        } else {
            printf("CHECK");
        }
    } else {
        if (all_dead) {
            printf("STALEMATE");
        } else {
            printf("NONE");
        }
    }

    return 0;
}
