#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n;
int dist[500][500], dp[500][500];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[j][i] = INF;

            for (int k = 0; k < n; k++) {
                if (dist[j][k] != 0) {
                    dp[j][i] = min(dp[j][i], dist[j][k] + dp[k][i - 1]);
                }
            }
        }
    }

    int ret = INF;
    for (int i = 0; i < n; i++) {
        ret = min(ret, dp[i][n - 1]);
    }

    if (ret == INF) {
        printf("-1");
    } else {
        printf("%d", ret);
    }

    return 0;
}
