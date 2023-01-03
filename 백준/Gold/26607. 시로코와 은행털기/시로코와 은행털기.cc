#include <bits/stdc++.h>

using namespace std;

int n, k, x;
bool dp[81][16001];

int main() {
    // freopen("input.txt", "r", stdin);

    dp[0][0] = true;

    scanf("%d %d %d", &n, &k, &x);

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);

        for (int i = k; i > 0; i--) {
            for (int j = a; j <= x * i; j++) {
                dp[i][j] |= dp[i - 1][j - a];
            }
        }
    }

    int ret = 0;
    for (int i = 1; i < k * x; i++) {
        if (dp[k][i]) {
            ret = max(ret, i * (k * x - i));
        }
    }

    printf("%d", ret);

    return 0;
}
