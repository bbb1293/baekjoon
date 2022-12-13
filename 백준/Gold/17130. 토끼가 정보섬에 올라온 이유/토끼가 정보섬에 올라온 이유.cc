#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m;
char state[MAXN][MAXN + 1];
int cnt[MAXN][MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    int start_y, start_x;
    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);

        for (int x = 0; x < m; x++) {
            if (state[y][x] == 'R') {
                start_y = y;
                start_x = x;
            }
        }
    }

    memset(cnt, -1, sizeof(cnt));
    cnt[start_y][start_x] = 0;

    for (int x = 1; x < m; x++) {
        for (int y = 0; y < n; y++) {
            if (state[y][x] == '#') {
                continue;
            }

            for (int i = -1; i <= 1; i++) {
                if (0 <= y + i && y + i < n) {
                    if (cnt[y + i][x - 1] != -1) {
                        cnt[y][x] = max(cnt[y][x],
                                        cnt[y + i][x - 1]);
                    }
                }
            }

            if (cnt[y][x] != -1 && state[y][x] == 'C') {
                cnt[y][x]++;
            }
        }
    }

    int ret = -1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (state[y][x] == 'O') {
                ret = max(ret, cnt[y][x]);
            }
        }
    }

    printf("%d", ret);

    return 0;
}