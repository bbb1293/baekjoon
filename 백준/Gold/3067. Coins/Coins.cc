#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10001];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        while (n--) {
            int coin;
            scanf("%d", &coin);

            for (int i = coin; i <= 10000; i++) {
                dp[i] += dp[i - coin];
            }
        }

        int m;
        scanf("%d", &m);

        printf("%d\n", dp[m]);
    }

    return 0;
}