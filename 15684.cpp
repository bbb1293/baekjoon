#include <bits/stdc++.h>

#define MAXN 10
#define MAXH 30

using namespace std;

int n, h;
bool horizon[MAXH + 1][MAXN + 2];

bool all_connected() {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 1; j <= h; j++) {
            if (horizon[j][cur]) {
                cur++;
            } else if (horizon[j][cur - 1]) {
                cur--;
            }
        }
        if (i != cur) {
            return false;
        }
    }
    return true;
}

int solve(int cur_height, int cnt) {
    if (all_connected()) {
        return cnt;
    }

    if (cnt == 3) {
        return 4;
    }

    int ret = 4;
    for (int hh = cur_height; hh <= h; hh++) {
        for (int nn = 1; nn < n; nn++) {
            if (horizon[hh][nn] || horizon[hh][nn + 1] || horizon[hh][nn - 1]) {
                continue;
            }
            horizon[hh][nn] = true;
            ret = min(ret, solve(hh, cnt + 1));
            horizon[hh][nn] = false;
        }
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    int m;

    scanf("%d %d %d", &n, &m, &h);

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        horizon[a][b] = true;
    }

    int ret = solve(1, 0);
    if (ret >= 4) {
        ret = -1;
    }

    printf("%d", ret);

    return 0;
}