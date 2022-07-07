#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5, INF = 1e9 + 1;
int n;
int a[MAXN + 1], dp[MAXN + 1][4];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    dp[0][0] = 1;
    dp[0][1] = INF;
    dp[0][2] = INF;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = INF;

            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                if (dp[i - 1][j] <= a[i]) {
                    dp[i][j] = min(dp[i][j], a[i]);
                }
            } else {
                if (dp[i - 1][j] <= a[i]) {
                    dp[i][j] = a[i];
                }
            }
        }
    }

    int cur_j = 4;
    for (int j = 0; j < 4; j++) {
        if (dp[n][j] != INF) {
            cur_j = j;
            break;
        }
    }

    if (cur_j == 4) {
        printf("NO");
    } else {
        printf("YES\n%d\n", cur_j);

        for (int i = n; i > 0; i--) {
            if (dp[i][cur_j] != a[i]) {
                printf("%d %d\n", i, dp[i][cur_j]);
                cur_j--;
            }
        }
    }

    return 0;
}
