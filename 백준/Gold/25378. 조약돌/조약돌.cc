#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2500;
int n;
int a[MAXN + 1], dp[MAXN + 1];
bool pos[MAXN + 1][MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) {
        int rest = a[i];
        for (int j = i + 1; j <= n; j++) {
            if (rest > a[j]) {
                break;
            } else {
                rest = a[j] - rest;
                if (rest == 0) {
                    pos[i][j] = true;
                    break;
                }
            }
        }
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;

        for (int j = 1; j < i; j++) {
            if (pos[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + i - j);
                break;
            }
        }
    }

    printf("%d", dp[n]);

    return 0;
}
