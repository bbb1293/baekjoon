#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2500;
int n, m;
double prob[MAXN + 1], dp[MAXN + 1][11];
double acc_prob[MAXN + 1][MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lf", &prob[i]);
        prob[i] = 1.0 - prob[i];
    }

    for (int i = 1; i <= n; i++) {
        acc_prob[i][i] = prob[i];
        for (int j = i + 1; j <= n; j++) {
            acc_prob[i][j] = acc_prob[i][j - 1] * prob[j];
        }
        for (int j = i + 1; j <= n; j++) {
            acc_prob[i][j] += acc_prob[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i][1] = acc_prob[1][i];
        for (int j = 2; j <= min(m, i); j++) {
            for (int k = j; k <= i; k++) {
                dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] + acc_prob[k][i]);
            }
        }
    }

    printf("%lf", dp[n][m]);

    return 0;
}
