#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n, k;
int cow[MAXN + 1];
int dp[MAXN + 1][1001], max_dp[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &cow[i]);
    }

    for (int i = 1; i <= n; i++) {
        int max_group = min(i, k);
        dp[i][1] = max_dp[i - 1] + cow[i];
        max_dp[i] = dp[i][1];

        for (int j = 2; j <= max_group; j++) {
            dp[i][j] =
                max_dp[i - j] +
                max((dp[i - 1][j - 1] - max_dp[i - j]) / (j - 1), cow[i]) * j;
            max_dp[i] = max(max_dp[i], dp[i][j]);
        }
    }

    printf("%d", max_dp[n]);

    return 0;
}
