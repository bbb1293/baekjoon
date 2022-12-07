#include <bits/stdc++.h>

using namespace std;

int n, m;
int ori_y, ori_x, p;
int w[50][50];
int dir_x[] = {0, 1, 0, -1}, dir_y[] = {1, 0, -1, 0};
bool visited[50][50];

bool is_nonvalid(int y, int x) {
    return (y < 0 || x < 0 || y == n || x == m ||
            visited[y][x]);
}

int get_ret(int cur_y, int cur_x, int dir, int rest) {
    if (rest) {
        visited[cur_y][cur_x] = true;

        int ret = 0;

        int next_y = cur_y + dir_y[dir];
        int next_x = cur_x + dir_x[dir];

        if (!is_nonvalid(next_y, next_x)) {
            ret = max(ret, get_ret(next_y, next_x, dir,
                                   rest - 1));
        }

        if (rest > 1) {
            for (int i = 1; i < 4; i += 2) {
                int next_dir = (dir + i) % 4;

                int next_y = cur_y + dir_y[next_dir];
                int next_x = cur_x + dir_x[next_dir];

                if (!is_nonvalid(next_y, next_x)) {
                    ret = max(ret,
                              get_ret(next_y, next_x,
                                      next_dir, rest - 2));
                }
            }
        }
        visited[cur_y][cur_x] = false;

        return ret + w[cur_y][cur_x];
    } else {
        return 0;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &w[y][x]);
        }
    }

    scanf("%d %d %d", &ori_y, &ori_x, &p);
    visited[ori_y][ori_x] = true;

    int ret = 0;
    if (p) {
        for (int dir = 0; dir < 4; dir++) {
            int next_y = ori_y + dir_y[dir];
            int next_x = ori_x + dir_x[dir];

            if (!is_nonvalid(next_y, next_x)) {
                ret = max(ret,
                          get_ret(next_y, next_x, dir, p));
            }
        }
    }

    printf("%d", ret + w[ori_y][ori_x]);

    return 0;
}