#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m, modified_n, modified_m;
int h, w, s_r, s_c, f_r, f_c;
int grid[MAXN + 1][MAXN + 1], modified_grid[MAXN + 1][MAXN + 1];
int x_dir[] = {0, 1, 0, -1}, y_dir[] = {1, 0, -1, 0};

void set_grid() {
    modified_n = n - h + 1;
    modified_m = m - w + 1;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            grid[y][x] +=
                (grid[y - 1][x] + grid[y][x - 1] - grid[y - 1][x - 1]);
        }
    }

    for (int y = 1; y <= modified_n; y++) {
        for (int x = 1; x <= modified_m; x++) {
            modified_grid[y][x] = grid[y + h - 1][x + w - 1] -
                                  grid[y - 1][x + w - 1] -
                                  grid[y + h - 1][x - 1] +
                                  grid[y - 1][x - 1];
        }
    }
}

int solve() {
    queue<pair<int, pair<int, int> > > q;
    q.push({0, {s_r, s_c}});

    while (!q.empty()) {
        int cnt = q.front().first;
        auto [r, c] = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [next_r, next_c] = make_pair(r + y_dir[dir], c + x_dir[dir]);

            if (next_r < 1 || next_c < 1 || next_r > modified_n ||
                next_c > modified_m || modified_grid[next_r][next_c] != 0) {
                continue;
            }

            if (next_r == f_r && next_c == f_c) {
                return cnt + 1;
            }

            modified_grid[next_r][next_c] = 1;
            q.push({cnt + 1, {next_r, next_c}});
        }
    }

    return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= m; x++) {
            scanf("%d", &grid[y][x]);
        }
    }

    scanf("%d %d %d %d %d %d", &h, &w, &s_r, &s_c, &f_r, &f_c);

    set_grid();
    printf("%d", solve());

    return 0;
}
