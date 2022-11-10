#include <bits/stdc++.h>

using namespace std;

const int ALL = (1 << 16);
int n, k;
int num[16];
long long dp[ALL][16];

long long get_dp(int state, int last) {
    long long &ret = dp[state][last];

    if (ret != -1) {
        return ret;
    }

    if (state == (1 << last)) {
        return ret = 1;
    }

    ret = 0;
    for (int i = 0; i < n; i++) {
        if (i != last && (((1 << i) | state) == state) &&
            (abs(num[last] - num[i]) > k)) {
            ret += get_dp(state - (1 << last), i);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    memset(dp, -1, sizeof(dp));

    int all_state = (1 << n) - 1;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        ret += get_dp(all_state, i);
    }

    printf("%lld", ret);

    return 0;
}