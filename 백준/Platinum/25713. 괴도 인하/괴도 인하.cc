#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int state[1001][1001][2], dp[1001][1001];

int get_dp(int y, int x) {
    int &ret = dp[y][x];

    if (ret != -1) {
        return ret;
    }

    ret = 10000;

    if (1 < y) {
        ret = min(ret, get_dp(y - 1, x) + state[y][x][0]);
    }

    if (1 < x) {
        ret = min(ret, get_dp(y, x - 1) + state[y][x][1]);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    scanf("%d", &k);

    while (k--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        state[a][b][0]++;
        state[a][b][1]++;

        for (int x = b + 1; x <= d; x++) {
            state[a][x][0]++;
        }

        for (int y = a + 1; y <= c; y++) {
            state[y][b][1]++;
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[1][1] = state[1][1][0];

    printf("%d", get_dp(n, m));

    return 0;
}