#include <bits/stdc++.h>

using namespace std;

char s[3][102];
int s_len[3];
int dp[101][101][101];

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 3; i++) {
        scanf("%s", s[i] + 1);
        s_len[i] = strlen(s[i] + 1);
    }

    for (int i = 1; i <= s_len[0]; i++) {
        for (int j = 1; j <= s_len[1]; j++) {
            for (int k = 1; k <= s_len[2]; k++) {
                dp[i][j][k] = max(
                    dp[i - 1][j][k],
                    max(dp[i][j - 1][k], dp[i][j][k - 1]));

                if (s[0][i] == s[1][j] &&
                    s[1][j] == s[2][k]) {
                    dp[i][j][k] =
                        max(dp[i][j][k],
                            1 + dp[i - 1][j - 1][k - 1]);
                }
            }
        }
    }

    printf("%d", dp[s_len[0]][s_len[1]][s_len[2]]);

    return 0;
}