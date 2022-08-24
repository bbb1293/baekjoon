#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
const long long MINF = -1e15;
int n;
int pos[MAXN + 1], h[MAXN + 1];
long long dp[MAXN + 1][3];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp) {
            pos[cnt] = i;
            h[cnt] = tmp;

            cnt++;
        }
    }

    for (int i = 1; i < cnt; i++) {
        if (1 <= pos[i] - h[i]) {
            if (pos[i] - h[i] < pos[i - 1]) {
                dp[i][0] = MINF;
            } else if (pos[i - 1] == pos[i] - h[i]) {
                dp[i][0] = dp[i - 1][0] + h[i];
            } else if (pos[i - 1] + h[i - 1] < pos[i] - h[i]) {
                dp[i][0] =
                    max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + h[i];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + h[i];
            }
        } else {
            dp[i][0] = MINF;
        }

        if (pos[i - 1] + h[i - 1] < pos[i]) {
            dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + 1;
        } else {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }

        if (pos[i] + h[i] <= n) {
            if (pos[i - 1] + h[i - 1] <= pos[i]) {
                dp[i][2] =
                    max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + h[i];
            } else {
                dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + h[i];
            }
        } else {
            dp[i][2] = MINF;
        }
    }

    long long ret =
        n - max(dp[cnt - 1][0], max(dp[cnt - 1][1], dp[cnt - 1][2]));
    printf("%lld", ret);

    return 0;
}
