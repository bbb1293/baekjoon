#include <bits/stdc++.h>

using namespace std;

int dp[1005][2];
char n[1005];

int get_dp(int idx, int state) {
    int &ret = dp[idx][state];
    if (ret != -1) {
        return ret;
    }

    if (idx == 0) {
        int cur = n[idx] - '0';
        if (state) {
            cur++;
        }

        if (cur == 10) {
            return ret = 1;
        }

        return ret = min(cur, 1 + 10 - cur);
    }

    int cur = n[idx] - '0' + state;

    if (cur == 10) {
        return ret = get_dp(idx - 1, 1);
    }

    return ret = min(cur + get_dp(idx - 1, 0), 10 - cur + get_dp(idx - 1, 1));
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", n);

    memset(dp, -1, sizeof(dp));

    printf("%d", get_dp(strlen(n) - 1, 0));

    return 0;
}