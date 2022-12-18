#include <bits/stdc++.h>

using namespace std;

long long dp[1001][5];

int main() {
    // freopen("input.txt", "r", stdin);

    dp[1][3] = 1;
    for (int i = 2; i <= 1000; i++) {
        dp[i][3] = dp[i - 1][3] * 2 + 1;
    }

    dp[1][4] = 1;
    for (int i = 2; i <= 1000; i++) {
        int k = i - sqrt(2 * i + 1) + 1;

        dp[i][4] = 2 * dp[k][4] + dp[i - k][3];
    }

    int n;
    for (int i = 1; scanf("%d", &n) > 0; i++) {
        printf("Case %d: %lld\n", i, dp[n][4]);
    }

    return 0;
}