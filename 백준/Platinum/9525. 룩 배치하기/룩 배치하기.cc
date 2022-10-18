#include <bits/stdc++.h>

using namespace std;

int n, row_idx, col_idx;
char state[100][101];
int color[100][100][2];
vector<int> edges[5000];
int p[5000];
bool visited[5000];

bool dfs(int cur) {
    if (visited[cur]) {
        return false;
    }
    visited[cur] = true;

    for (auto v : edges[cur]) {
        if (p[v] == -1 || dfs(p[v])) {
            p[v] = cur;
            return true;
        }
    }

    return false;
}

int kuhn() {
    memset(p, -1, sizeof(p));

    int ret = 0;
    for (int i = 0; i < row_idx; i++) {
        memset(visited, 0, sizeof(visited));

        if (dfs(i)) {
            ret++;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);
    }

    memset(color, -1, sizeof(color));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (state[y][x] == 'X' ||
                color[y][x][0] != -1) {
                continue;
            }

            color[y][x][0] = row_idx;

            int cur_y = y + 1;
            while (cur_y < n && state[cur_y][x] != 'X') {
                color[cur_y][x][0] = row_idx;
                cur_y++;
            }
            row_idx++;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (state[y][x] == 'X' ||
                color[y][x][1] != -1) {
                continue;
            }

            color[y][x][1] = col_idx;

            int cur_x = x + 1;
            while (cur_x < n && state[y][cur_x] != 'X') {
                color[y][cur_x][1] = col_idx;
                cur_x++;
            }
            col_idx++;
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (state[y][x] != 'X') {
                edges[color[y][x][0]].push_back(
                    color[y][x][1]);
            }
        }
    }

    printf("%d", kuhn());

    return 0;
}