#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n, k, r;
int cur_color;
int color[MAXN][MAXN];
int cnt[MAXN * MAXN];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
set<pair<int, int> > bridge;

int convert_p(int y, int x) { return y * n + x; }

void set_color(int y, int x) {
    int cur_p = convert_p(y, x);

    for (int dir = 0; dir < 4; dir++) {
        int next_y = y + dir_y[dir];
        int next_x = x + dir_x[dir];

        if (next_y < 0 || next_x < 0 || next_y == n ||
            next_x == n || color[next_y][next_x] != -1) {
            continue;
        }

        int next_p = convert_p(next_y, next_x);

        if (!bridge.count({cur_p, next_p})) {
            color[next_y][next_x] = cur_color;
            set_color(next_y, next_x);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &k, &r);

    while (r--) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int p1 = convert_p(y1 - 1, x1 - 1);
        int p2 = convert_p(y2 - 1, x2 - 1);

        bridge.insert({p1, p2});
        bridge.insert({p2, p1});
    }

    memset(color, -1, sizeof(color));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (color[y][x] == -1) {
                color[y][x] = cur_color;
                set_color(y, x);
                cur_color++;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < k; i++) {
        int y, x;
        scanf("%d %d", &y, &x);

        ret += (i - cnt[color[y - 1][x - 1]]);

        cnt[color[y - 1][x - 1]]++;
    }

    printf("%d", ret);

    return 0;
}