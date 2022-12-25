#include <bits/stdc++.h>

using namespace std;

int n;
int state[100][100], dist[100][100];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
queue<pair<int, int> > q;

void set_color(int y, int x, int color) {
    state[y][x] = color;
    q.push({y, x});

    for (int dir = 0; dir < 4; dir++) {
        int next_y = y + dir_y[dir];
        int next_x = x + dir_x[dir];

        if (next_y < 0 || next_x < 0 || next_y == n ||
            next_x == n || state[next_y][next_x] != 1) {
            continue;
        }

        set_color(next_y, next_x, color);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    int color = 2;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (state[y][x] == 1) {
                set_color(y, x, color++);
            }
        }
    }

    int ret = 987654321;
    int cur_dist = 0;
    while (!q.empty()) {
        cur_dist++;
        int cnt = q.size();

        while (cnt--) {
            auto [y, x] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int next_y = y + dir_y[dir];
                int next_x = x + dir_x[dir];

                if (next_y < 0 || next_x < 0 ||
                    next_y == n || next_x == n ||
                    state[next_y][next_x] == state[y][x]) {
                    continue;
                }

                if (state[next_y][next_x] == 0) {
                    state[next_y][next_x] = state[y][x];
                    dist[next_y][next_x] = cur_dist;
                    q.push({next_y, next_x});
                } else {
                    ret = min(ret, dist[next_y][next_x] +
                                       dist[y][x]);
                }
            }
        }
    }

    printf("%d", ret);

    return 0;
}