#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2;
int n, m;
int dir_x[] = {1, -1}, dir_y[] = {1, 1};
int cnt[2], idx[MAXN][MAXN][2], connected[MAXN * MAXN];
bool obstacle[MAXN][MAXN], used[MAXN * MAXN];
set<int> edges[MAXN * MAXN];

bool kuhn(int cur) {
    if (used[cur]) {
        return false;
    }
    used[cur] = true;

    for (auto v : edges[cur]) {
        if (connected[v] == -1 || kuhn(connected[v])) {
            connected[v] = cur;
            return true;
        }
    }

    return false;
}

void set_idx(int dir) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (obstacle[y][x] || idx[y][x][dir] != -1) {
                continue;
            }

            idx[y][x][dir] = cnt[dir]++;
            int cur_y = y;
            int cur_x = x;

            while (1) {
                cur_y = cur_y + dir_y[dir];
                cur_x = cur_x + dir_x[dir];

                if (cur_y < 0 || cur_x < 0 || cur_y == n ||
                    cur_x == n || obstacle[cur_y][cur_x]) {
                    break;
                }

                idx[cur_y][cur_x][dir] = idx[y][x][dir];
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    scanf("%d", &m);
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        obstacle[y - 1][x - 1] = true;
    }

    memset(idx, -1, sizeof(idx));

    set_idx(0);
    set_idx(1);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (obstacle[y][x]) {
                continue;
            }
            edges[idx[y][x][0]].insert(idx[y][x][1]);
        }
    }

    memset(connected, -1, sizeof(connected));
    for (int i = 0; i < cnt[0]; i++) {
        memset(used, 0, sizeof(used));
        kuhn(i);
    }

    int ret = 0;
    for (int i = 0; i < cnt[1]; i++) {
        if (connected[i] != -1) {
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}