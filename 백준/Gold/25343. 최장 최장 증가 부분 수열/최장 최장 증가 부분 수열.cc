#include <bits/stdc++.h>

using namespace std;

const int INF = 1e5;
int n;
int num[101][101], dp[101][101][200];

int get_dp(int y, int x, int cnt) {
    if (cnt == 0) {
        return 0;
    }

    if (x * y == 0) {
        return INF;
    }

    int &ret = dp[y][x][cnt];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    ret = min(ret, min(get_dp(y - 1, x, cnt), get_dp(y, x - 1, cnt)));

    if (get_dp(y - 1, x, cnt - 1) < num[y][x] ||
        get_dp(y, x - 1, cnt - 1) < num[y][x]) {
        ret = min(ret, num[y][x]);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            scanf("%d", &num[y][x]);
        }
    }

    memset(dp, -1, sizeof(dp));

    int last = n + n - 1;
    for (int i = last; i > 0; i--) {
        if (get_dp(n, n, i) != INF) {
            printf("%d", i);
            return 0;
        }
    }

    return 0;
}
