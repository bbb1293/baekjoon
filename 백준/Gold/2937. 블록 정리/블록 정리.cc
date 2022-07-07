#include <bits/stdc++.h>

using namespace std;

int n, m;
int cnt[101][101];

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    int add = 0;
    for (int i = 0; i < m; i++) {
        int r, c;
        scanf("%d %d", &r, &c);

        if (cnt[r][c] == 1) {
            add++;
        }
        cnt[r][c] = 1;
    }

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cnt[y][x] += (cnt[y - 1][x] + cnt[y][x - 1] - cnt[y - 1][x - 1]);
        }
    }

    int ret = m - add;
    for (int w = 1; w <= m; w++) {
        if (m % w) {
            continue;
        }

        int h = m / w;
        for (int y = 1; y + h - 1 <= n; y++) {
            for (int x = 1; x + w - 1 <= n; x++) {
                int cur = cnt[y + h - 1][x + w - 1] - cnt[y + h - 1][x - 1] -
                          cnt[y - 1][x + w - 1] + cnt[y - 1][x - 1];

                ret = min(ret, m - cur - add);
            }
        }
    }

    printf("%d", ret + add);

    return 0;
}
