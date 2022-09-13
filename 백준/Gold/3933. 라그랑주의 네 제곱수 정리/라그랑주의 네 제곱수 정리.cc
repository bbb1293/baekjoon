#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32768;
int dp[MAXN][5];

int main() {
    // freopen("input.txt", "r", stdin);

    dp[0][0] = 1;
    for (int i = 1; i < 200; i++) {
        int i_2 = i * i;

        if (i_2 >= 32768) {
            break;
        }

        for (int j = i_2; j < MAXN; j++) {
            for (int k = 1; k < 5; k++) {
                dp[j][k] += dp[j - i_2][k - 1];
            }
        }
    }

    while (true) {
        int n;
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        int ret = 0;
        for (int j = 0; j < 5; j++) {
            ret += dp[n][j];
        }

        printf("%d\n", ret);
    }

    return 0;
}
