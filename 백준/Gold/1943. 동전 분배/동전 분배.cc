#include <bits/stdc++.h>

using namespace std;

const int MAXM = 5e4;
int n;
bool dp[MAXM + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    for (int t = 0; t < 3; t++) {
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        scanf("%d", &n);

        int sum = 0;
        while (n--) {
            int c, k;
            scanf("%d %d", &c, &k);

            sum += (c * k);

            for (int i = min(sum, MAXM); i >= c; i--) {
                if (dp[i - c]) {
                    for (int j = 0; j < k && i + c * j <= MAXM; j++) {
                        dp[i + c * j] = true;
                    }
                }
            }
        }

        if ((sum % 2 == 0) && dp[sum / 2]) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}
