#include <bits/stdc++.h>

using namespace std;

int n, m;
int state[1000][1000];
queue<pair<int, int> > q[2];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};

bool spread() {
    if (q[0].empty()) {
        return false;
    }

    while (!q[0].empty()) {
        auto [y, x] = q[0].front();
        q[0].pop();

        int cur = state[y][x];

        for (int dir = 0; dir < 4; dir++) {
            int next_y = y + dir_y[dir];
            int next_x = x + dir_x[dir];

            if (next_y < 0 || next_x < 0 || next_y == n ||
                next_x == m ||
                (state[next_y][next_x] != 0 &&
                 state[next_y][next_x] <= 3) ||
                state[next_y][next_x] == cur + 3)
                continue;

            if (state[next_y][next_x] == 0) {
                state[next_y][next_x] = cur + 3;
                q[1].push({next_y, next_x});

            } else {
                state[next_y][next_x] = 3;
            }
        }
    }

    return true;
}

bool fix() {
    if (q[1].empty()) {
        return false;
    }

    while (!q[1].empty()) {
        auto [y, x] = q[1].front();
        q[1].pop();

        if (state[y][x] == 4 || state[y][x] == 5) {
            state[y][x] -= 3;
            q[0].push({y, x});
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &state[y][x]);

            if (state[y][x] == 1 || state[y][x] == 2) {
                q[0].push({y, x});
            }
        }
    }

    while (spread() && fix()) {
    }

    int num[3] = {
        0,
    };

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (state[y][x] > 0) {
                num[state[y][x] - 1]++;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}