#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n, m;
int dp[MAXN][500];
bool small[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    while (m--) {
        int k;
        scanf("%d", &k);
        small[k - 1] = true;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < n - 1; i++) {
        if (small[i]) {
            continue;
        }
        for (int j = 0; j < 500; j++) {
            if (dp[i][j] != -1) {
                for (int k = -1; k <= 1; k++) {
                    int next_idx = i + j + k;

                    if (i < next_idx && next_idx < n) {
                        if (dp[next_idx][j + k] == -1 ||
                            dp[i][j] + 1 < dp[next_idx][j + k]) {
                            dp[next_idx][j + k] = dp[i][j] + 1;
                        }
                    }
                }
            }
        }
    }

    int ret = 987654321;
    for (int i = 0; i < 500; i++) {
        if (dp[n - 1][i] != -1) {
            ret = min(ret, dp[n - 1][i]);
        }
    }

    if (ret == 987654321) {
        ret = -1;
    }
    printf("%d", ret);

    return 0;
}
