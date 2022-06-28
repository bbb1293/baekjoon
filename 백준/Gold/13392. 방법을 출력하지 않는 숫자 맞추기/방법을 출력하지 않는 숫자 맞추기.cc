#include <bits/stdc++.h>

using namespace std;

int n;
int dp[10000][10];
int ori[10000], want[10000];

int get_dp(int cur, int diff) {
    int &ret = dp[cur][diff];

    if (ret != -1) {
        return ret;
    }

    if (cur == n) {
        return 0;
    }

    int cur_num = (ori[cur] + diff) % 10;
    ret = ((cur_num - want[cur] + 10) % 10) + get_dp(cur + 1, diff);

    int new_diff = (want[cur] - cur_num + 10) % 10;

    return ret = min(ret, new_diff + get_dp(cur + 1, (diff + new_diff) % 10));
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &ori[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%1d", &want[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d", get_dp(0, 0));

    return 0;
}