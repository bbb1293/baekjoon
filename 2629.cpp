#include <bits/stdc++.h>

using namespace std;

int n, weight[30];
bool dp[30][15001] = {
    0,
};

void set_dp() {
    dp[0][0] = true;
    dp[0][weight[0]] = true;

    int last = weight[0];
    for (int i = 1; i < n; i++) {
        for (int j = last + weight[i]; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] |= dp[i - 1][abs(j - weight[i])];
            if (j + weight[i] <= 15000) {
                dp[i][j] |= dp[i - 1][j + weight[i]];
            }
        }
        last += weight[i];
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    set_dp();

    int t;
    scanf("%d", &t);

    while (t--) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp > 15000) {
            printf("N ");
            continue;
        }

        if (dp[n - 1][tmp]) {
            printf("Y ");
        } else {
            printf("N ");
        }
    }

    return 0;
}