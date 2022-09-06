#include <bits/stdc++.h>

using namespace std;

int n, k;
int x[500], y[500];
int dp[500][501];

int get_dist(int i, int j) { return abs(x[i] - x[j]) + abs(y[i] - y[j]); }

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    memset(dp, -1, sizeof(dp));
    dp[0][k] = 0;

    for (int i = 1; i < n; i++) {
        for (int rest = 0; rest <= k; rest++) {
            int tmp = -1;
            for (int last = 0; last < i; last++) {
                if (dp[last][rest] != -1) {
                    if (tmp == -1 || dp[last][rest] + get_dist(last, i) < tmp) {
                        tmp = dp[last][rest] + get_dist(last, i);
                    }
                }
            }

            dp[i][rest] = tmp;
        }

        for (int last = 0; last < i; last++) {
            for (int rest = 0; rest <= k; rest++) {
                dp[last][rest] = dp[last][rest + 1];
            }
        }

    }

    int ret = 1e9;
    for (int rest = 0; rest <= k; rest++) {
        if (dp[n - 1][rest] != -1) {
            ret = min(ret, dp[n - 1][rest]);
        }
    }

    printf("%d", ret);

    return 0;
}
