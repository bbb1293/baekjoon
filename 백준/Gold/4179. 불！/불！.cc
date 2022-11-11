#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m;
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
char state[MAXN][MAXN + 1];
bool visited[MAXN][MAXN];
queue<pair<int, int> > q[2];

int move() {
    int sz = q[1].size();
    while (sz--) {
        auto [y, x] = q[1].front();
        q[1].pop();

        for (int dir = 0; dir < 4; dir++) {
            int next_y = y + dir_y[dir];
            int next_x = x + dir_x[dir];

            if (next_y < 0 || next_x < 0 || next_y == n ||
                next_x == m || visited[next_y][next_x] ||
                state[next_y][next_x] == '#') {
                continue;
            }

            visited[next_y][next_x] = true;
            q[1].push({next_y, next_x});
        }
    }

    sz = q[0].size();
    if (sz == 0) {
        return -2;
    }

    while (sz--) {
        auto [y, x] = q[0].front();
        q[0].pop();

        if (y == 0 || x == 0 || y == n - 1 || x == m - 1) {
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int next_y = y + dir_y[dir];
            int next_x = x + dir_x[dir];

            if (next_y < 0 || next_x < 0 || next_y == n ||
                next_x == m || visited[next_y][next_x] ||
                state[next_y][next_x] != '.') {
                continue;
            }

            visited[next_y][next_x] = true;
            q[0].push({next_y, next_x});
        }
    }

    return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);

        for (int x = 0; x < m; x++) {
            if (state[y][x] == 'J') {
                q[0].push({y, x});
            } else if (state[y][x] == 'F') {
                q[1].push({y, x});
            }
        }
    }

    int cnt = 1, ret;
    while ((ret = move()) == -1) {
        cnt++;
    }

    if (ret == -2) {
        printf("IMPOSSIBLE");
    } else {
        printf("%d", cnt);
    }

    return 0;
}