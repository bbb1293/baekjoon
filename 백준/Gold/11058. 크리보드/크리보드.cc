#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n;
long long dp[MAXN + 1][3];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]),
                       dp[i - 1][2]) +
                   1;

        if (i > 1) {
            dp[i][1] = max(max(dp[i - 2][0], dp[i - 2][1]),
                           dp[i - 2][2]);
        }

        for (int j = 0; j < i; j++) {
            dp[i][2] =
                max(dp[i][2], dp[j][1] * (i - j + 1));
        }
    }

    printf("%lld", max(max(dp[n][0], dp[n][1]), dp[n][2]));

    return 0;
}