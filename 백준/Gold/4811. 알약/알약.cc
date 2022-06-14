#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[61][31];

long long set_dp() {
    dp[0][0] = 1;

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;

            if (j - 1 >= 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }

            if (j + 1 <= n) {
                dp[i][j] += dp[i - 1][j + 1];
            }
        }
    }

    return dp[2 * n][0];
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (true) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        printf("%lld\n", set_dp());
    }

    return 0;
}
