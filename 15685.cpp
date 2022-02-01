#include <bits/stdc++.h>

using namespace std;

int dragoncurv[1024];
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, -1, 0, 1};
bool grid[101][101];

void draw_dragoncurv(int age, int cur_len) {
    if (age == 0) {
        return;
    }

    int end_idx = 2 * cur_len - 1;
    for (int i = 0; i < cur_len; i++) {
        dragoncurv[end_idx - i] = (dragoncurv[i] + 1) % 4;
    }

    draw_dragoncurv(age - 1, cur_len * 2);
}

bool is_square(int x, int y) {
    return grid[y][x] && grid[y + 1][x] && grid[y][x + 1] && grid[y + 1][x + 1];
}

int main() {
    freopen("input.txt", "r", stdin);
    memset(grid, 0, sizeof(grid));
    int n;
    scanf("%d", &n);

    int x, y, d, g;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        dragoncurv[0] = d;
        draw_dragoncurv(g, 1);

        grid[y][x] = true;
        int len = (1 << g);
        for (int i = 0; i < len; i++) {
            int idx = dragoncurv[i];
            y += dir_y[idx];
            x += dir_x[idx];
            grid[y][x] = true;
        }
    }

    int ret = 0;
    for (y = 0; y < 100; y++) {
        for (x = 0; x < 100; x++) {
            ret += is_square(x, y);
        }
    }
    printf("%d", ret);

    return 0;
}