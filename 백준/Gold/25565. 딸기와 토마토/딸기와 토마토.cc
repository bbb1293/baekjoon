#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int state[2000][2000];
int x_dir[] = {1, 0, -1, 0}, y_dir[] = {0, 1, 0, -1};

bool exist(int y, int x, int dir) {
    int cnt = 0;
    while (state[y][x] != 0 && cnt < k) {
        cnt++;
        y += y_dir[dir];
        x += x_dir[dir];

        if (y < 0 || x < 0 || y == n || x == m) {
            break;
        }
    }

    return cnt == k;
}

void put(int y, int x, int dir) {
    int cnt = 0;
    while (cnt < k) {
        cnt++;
        state[y][x]++;
        y += y_dir[dir];
        x += x_dir[dir];
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    int s_y1 = -1, s_x1, dir1;
    for (int y = 0; y < n && s_y1 == -1; y++) {
        for (int x = 0; x < m && s_y1 == -1; x++) {
            if (state[y][x] == 1) {
                for (int dir = 0; dir < 2; dir++) {
                    if (exist(y, x, dir)) {
                        put(y, x, dir);
                        s_y1 = y;
                        s_x1 = x;
                        dir1 = dir;
                        break;
                    }
                }
            }
        }
    }

    int s_y2 = -1, s_x2, dir2;
    for (int y = 0; y < n && s_y2 == -1; y++) {
        for (int x = 0; x < m && s_y2 == -1; x++) {
            if (state[y][x] == 1) {
                for (int dir = 0; dir < 4; dir++) {
                    if (exist(y, x, dir)) {
                        put(y, x, dir);
                        s_y2 = y;
                        s_x2 = x;
                        dir2 = dir;
                        break;
                    }
                }
            }
        }
    }

    if (s_y2 == -1) {
        printf("%d\n", k);

        int cnt = 0;
        while (cnt < k) {
            printf("%d %d\n", s_y1 + 1, s_x1 + 1);
            s_y1 += y_dir[dir1];
            s_x1 += x_dir[dir1];
            cnt++;
        }
    } else {
        int cnt = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (state[y][x] == 3) {
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (state[y][x] == 3) {
                    printf("%d %d\n", y + 1, x + 1);
                }
            }
        }
    }

    return 0;
}
