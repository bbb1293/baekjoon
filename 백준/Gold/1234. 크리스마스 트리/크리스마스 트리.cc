#include <bits/stdc++.h>

using namespace std;

int n, r, g, b;
long long comb[101][101], dp[11][201][201];

void set_comb() {
    comb[0][0] = 1;

    for (int i = 1; i < 101; i++) {
        comb[i][0] = comb[i][i] = 1;

        for (int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_comb();

    scanf("%d %d %d %d", &n, &r, &g, &b);

    int sum = r + g + b;

    dp[0][r][g] = 1;
    for (int i = 1; i <= n; i++) {
        sum -= i;
        for (int j = 0; j <= r; j++) {
            for (int k = 0; k <= g; k++) {
                int cur_b = sum - j - k;
                if (cur_b < 0) {
                    break;
                }

                dp[i][j][k] += dp[i - 1][j + i][k];
                dp[i][j][k] += dp[i - 1][j][k + i];

                if (cur_b + i <= b) {
                    dp[i][j][k] += dp[i - 1][j][k];
                }

                if (!(i & 1)) {
                    int used_num = i / 2;
                    long long c = comb[i][used_num];

                    dp[i][j][k] += (dp[i - 1][j + used_num][k + used_num] * c);

                    if (cur_b + used_num <= b) {
                        dp[i][j][k] += (dp[i - 1][j + used_num][k] * c);
                        dp[i][j][k] += (dp[i - 1][j][k + used_num] * c);
                    }
                }

                if (!(i % 3)) {
                    int used_num = i / 3;
                    long long c =
                        comb[i][used_num] * comb[i - used_num][used_num];

                    if (cur_b + used_num <= b) {
                        dp[i][j][k] +=
                            (dp[i - 1][j + used_num][k + used_num] * c);
                    }
                }
            }
        }
    }

    long long ret = 0;
    for (int j = 0; j <= r; j++) {
        for (int k = 0; k <= g; k++) {
            ret += dp[n][j][k];
        }
    }

    printf("%lld\n", ret);

    return 0;
}
