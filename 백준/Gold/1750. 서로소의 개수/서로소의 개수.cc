#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e7 + 3;
int n;
int num[51];
int dp[51][100001];

int get_gcd(int a, int b) {
    if (b < a) {
        return get_gcd(b, a);
    }

    if (a == 0) {
        return b;
    }

    return get_gcd(b % a, a);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 1; i <= n; i++) {
        dp[i][num[i]] = 1;
        for (int j = 1; j <= 100000; j++) {
            if (dp[i - 1][j] != 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
                dp[i][get_gcd(j, num[i])] += dp[i - 1][j];
                dp[i][get_gcd(j, num[i])] %= MOD;
            }
        }
    }

    printf("%d", dp[n][1]);

    return 0;
}
