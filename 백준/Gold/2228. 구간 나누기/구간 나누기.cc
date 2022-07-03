#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[101];
int dp[101][201];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }

    int mm = 2 * m + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < min(i + 1, mm); j++) {
            if (j & 1) {
                if (j < min(i, mm)) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + num[i];
                }

            } else {
                if (j < min(i, mm)) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
    }

    printf("%d", max(dp[n][mm - 1], dp[n][mm - 2]));

    return 0;
}
