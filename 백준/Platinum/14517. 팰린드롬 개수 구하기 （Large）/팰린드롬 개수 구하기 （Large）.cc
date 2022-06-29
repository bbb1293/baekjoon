#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;
string s;
int dp[1000][1000];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;

        if (i != 0) {
            if (s[i - 1] == s[i]) {
                dp[i - 1][i] = 3;
            } else {
                dp[i - 1][i] = 2;
            }
        }
    }
    for (int len = 2; len < n; len++) {
        for (int left = 0; left + len < n; left++) {
            int right = left + len;

            dp[left][right] = (dp[left + 1][right] + dp[left][right - 1] -
                               dp[left + 1][right - 1] + MOD) %
                              MOD;

            if (s[left] == s[right]) {
                dp[left][right] += (dp[left + 1][right - 1] + 1);
                dp[left][right] %= MOD;
            }
        }
    }

    printf("%d", dp[0][n - 1]);

    return 0;
}
