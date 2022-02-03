#include <bits/stdc++.h>

using namespace std;

struct State {
    int dir, speed = 0, mass = 0, cnt = 0;
};

int n, m, k;
int dir_x[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dir_y[] = {-1, -1, 0, 1, 1, 1, 0, -1};
State state[50][50];

void add_fireball(State tmp[50][50], int x, int y, State &cur) {
    State &cur_tmp = tmp[y][x];

    cur_tmp.cnt++;
    cur_tmp.mass += cur.mass;
    cur_tmp.speed += cur.speed;

    if (cur_tmp.cnt == 1) {
        cur_tmp.dir = cur.dir;
    } else {
        if (cur_tmp.dir != -1) {
            if ((cur_tmp.dir % 2) != (cur.dir % 2)) {
                cur_tmp.dir = -1;
            }
        }
    }
}

void solve() {
    State tmp[50][50];
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            State cur_state = state[y][x];

            if (cur_state.cnt == 1) {
                int new_x =
                    (x + (dir_x[cur_state.dir] + n) * cur_state.speed) % n;
                int new_y =
                    (y + (dir_y[cur_state.dir] + n) * cur_state.speed) % n;

                add_fireball(tmp, new_x, new_y, cur_state);

            } else if (cur_state.cnt > 1) {
                int new_mass = cur_state.mass / 5;

                if (!new_mass) {
                    continue;
                }

                int new_speed = cur_state.speed / cur_state.cnt;
                int dir = 0;
                if (cur_state.dir == -1) {
                    dir++;
                }

                for (; dir < 8; dir += 2) {
                    int new_x = (x + (dir_x[dir] + n) * new_speed) % n;
                    int new_y = (y + (dir_y[dir] + n) * new_speed) % n;

                    State new_state = {dir, new_speed, new_mass, 1};
                    add_fireball(tmp, new_x, new_y, new_state);
                }
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            state[y][x] = tmp[y][x];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    int r, c, mm, s, d;
    while (m--) {
        scanf("%d %d %d %d %d", &r, &c, &mm, &s, &d);
        state[r - 1][c - 1] = {d, s, mm, 1};
    }

    while (k--) {
        solve();
    }

    int ret = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (state[y][x].cnt == 1) {
                ret += (state[y][x].mass);

            } else if (state[y][x].cnt > 1) {
                ret += ((state[y][x].mass / 5) * 4);
            }
        }
    }
    printf("%d", ret);

    return 0;
}