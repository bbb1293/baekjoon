#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[1000][1000];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
bool removed[1000][1000];
stack<pair<int, int> > stk[2];

void in_adj(int y, int x) {
    for (int dir = 0; dir < 4; dir++) {
        auto [next_y, next_x] =
            make_pair(y + dir_y[dir], x + dir_x[dir]);

        if (next_y < 0 || next_x < 0 || next_y == n ||
            next_x == m || removed[next_y][next_x]) {
            continue;
        }

        stk[grid[next_y][next_x]].push({next_y, next_x});
        removed[next_y][next_x] = true;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    int cnt[2] = {
        0,
    };

    int y1, y2, x1, x2;
    bool check = true;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &grid[y][x]);
            cnt[grid[y][x]]++;

            if (y != 0) {
                if (grid[y - 1][x] == grid[y][x]) {
                    y1 = y - 1;
                    x1 = x;
                    y2 = y;
                    x2 = x;

                    check = false;
                }

            } else {
                if (x != 0) {
                    if (grid[y][x - 1] == grid[y][x]) {
                        y1 = y;
                        x1 = x - 1;
                        y2 = y;
                        x2 = x;

                        check = false;
                    }
                }
            }
        }
    }

    if (check || (cnt[0] & 1) || (cnt[1] & 1)) {
        printf("-1");
    } else {
        printf("1\n");

        stk[0].push({y1, x1});
        stk[0].push({y2, x2});

        removed[y1][x1] = removed[y2][x2] = true;

        while (stk[0].size() > 1 || stk[1].size() > 1) {
            for (int i = 0; i < 2; i++) {
                while (stk[i].size() > 1) {
                    auto [y1, x1] = stk[i].top();
                    stk[i].pop();
                    auto [y2, x2] = stk[i].top();
                    stk[i].pop();

                    printf("%d %d %d %d\n", y1 + 1, x1 + 1,
                           y2 + 1, x2 + 1);

                    in_adj(y1, x1);
                    in_adj(y2, x2);
                }
            }
        }
    }

    return 0;
}