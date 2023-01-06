#include <bits/stdc++.h>

using namespace std;

const int MAXD = 1e5;
int d, p;
int dp[MAXD + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));
    dp[0] = (1 << 30);

    scanf("%d %d", &d, &p);

    while (p--) {
        int l, c;
        scanf("%d %d", &l, &c);

        for (int i = d; i >= l; i--) {
            if (dp[i - l] != -1) {
                dp[i] = max(dp[i], min(dp[i - l], c));
            }
        }
    }

    printf("%d", dp[d]);

    return 0;
}