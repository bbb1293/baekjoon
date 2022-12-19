#include <bits/stdc++.h>

using namespace std;

const int MAXW = 1e2;
int w, h;
int state[MAXW + 2][MAXW + 2];
int dir_y[2][6] = {{-1, -1, 0, 1, 1, 0},
                   {-1, -1, 0, 1, 1, 0}};
int dir_x[2][6] = {{-1, 0, 1, 0, -1, -1},
                   {0, 1, 1, 1, 0, -1}};
bool visited[MAXW + 2][MAXW + 2];

int dfs(int y, int x) {
    int ret = 0;

    for (int dir = 0; dir < 6; dir++) {
        int next_y = y + dir_y[y & 1][dir];
        int next_x = x + dir_x[y & 1][dir];

        if (next_y < 0 || next_x < 0 || next_y > h + 1 ||
            next_x > w + 1 || visited[next_y][next_x]) {
            continue;
        }

        if (state[next_y][next_x] == 1) {
            ret++;
        } else {
            visited[next_y][next_x] = true;
            ret += dfs(next_y, next_x);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &w, &h);

    for (int y = 1; y <= h; y++) {
        for (int x = 1; x <= w; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    visited[0][0] = true;
    printf("%d", dfs(0, 0));

    return 0;
}