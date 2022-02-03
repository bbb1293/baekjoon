#include <bits/stdc++.h>

using namespace std;

struct State {
    int shark_num, duration;
};

struct Shark {
    int x, y, dir;
} shark[401];

int n, m, k, shark_cnt;
int dir_x[] = {0, 0, -1, 1}, dir_y[] = {-1, 1, 0, 0};
State state[20][20];
int priority[401][4][4];

bool are_valid(int x, int y) {
    return (0 <= x) && (0 <= y) && (x < n) && (y < n);
}

int solve(int cur_time) {
    if (cur_time > 1000) {
        return -1;
    }

    for (int i = 1; i <= m; i++) {
        Shark &cur_shark = shark[i];
        int cur_x = cur_shark.x, cur_y = cur_shark.y;

        if (cur_x == -1) {
            continue;
        }

        State &next_state = state[cur_y][cur_x];

        if (next_state.duration == cur_time) {
            cur_shark.x = -1;
            shark_cnt--;
        } else {
            next_state = {i, cur_time};
        }
    }

    if (shark_cnt == 1) {
        return cur_time;
    }

    cur_time++;
    for (int shark_num = 1; shark_num <= m; shark_num++) {
        Shark &cur_shark = shark[shark_num];
        int cur_x = cur_shark.x, cur_y = cur_shark.y;
        int cur_dir = cur_shark.dir;

        if (cur_x == -1) {
            continue;
        }

        int cand_x = -1, cand_y, cand_dir;
        for (int dir = 0; dir < 4; dir++) {
            int next_dir = priority[shark_num][cur_dir][dir];
            int new_x = cur_x + dir_x[next_dir];
            int new_y = cur_y + dir_y[next_dir];

            if (are_valid(new_x, new_y)) {
                State &next_state = state[new_y][new_x];

                if ((!next_state.shark_num) ||
                    (next_state.duration < (cur_time - k))) {
                    cand_x = new_x;
                    cand_y = new_y;
                    cand_dir = next_dir;
                    break;
                } else if ((cand_x == -1) &&
                           (next_state.shark_num == shark_num)) {
                    cand_x = new_x;
                    cand_y = new_y;
                    cand_dir = next_dir;
                }
            }
        }

        cur_shark = {cand_x, cand_y, cand_dir};
    }

    return solve(cur_time);
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);
    shark_cnt = m;

    int num;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &state[y][x].shark_num);
            state[y][x].duration = -1;

            if (state[y][x].shark_num != 0) {
                shark[state[y][x].shark_num] = {x, y, 0};
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d", &shark[i].dir);
        shark[i].dir--;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                scanf("%d", &priority[i][j][k]);
                priority[i][j][k]--;
            }
        }
    }
    printf("%d", solve(0));

    return 0;
}