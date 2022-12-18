#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const long long MOD = 9901;
long long dp[MAXN + 1][5];

int main() {
    // freopen("input.txt", "r", stdin);

    dp[1][3] = 1;
    for (int i = 2; i <= MAXN; i++) {
        dp[i][3] = dp[i - 1][3] * 2 + 1;
        dp[i][3] %= MOD;
    }

    dp[1][4] = 1;
    for (int i = 2; i <= MAXN; i++) {
        int k = i - sqrt(2 * i + 1) + 1;

        dp[i][4] = 2 * dp[k][4] + dp[i - k][3];
        dp[i][4] %= MOD;
    }

    int n;
    scanf("%d", &n);

    printf("%lld", dp[n][4]);

    return 0;
}