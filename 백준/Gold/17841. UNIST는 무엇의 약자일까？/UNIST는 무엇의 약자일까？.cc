#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5, MOD = 1e9 + 7;
int n;
char w[MAXN][26], target[6] = "UNIST";
long long dp[MAXN][6];

long long get_dp(int cur, int rest) {
    if (rest == 0) {
        return 1;
    }

    if (cur == n) {
        return 0;
    }

    long long &ret = dp[cur][rest];

    if (ret != -1) {
        return ret;
    }

    ret = get_dp(cur + 1, rest);

    for (int i = 0; i < rest; i++) {
        if (w[cur][i] == target[5 - rest + i]) {
            ret += get_dp(cur + 1, rest - i - 1);
            ret %= MOD;
        } else {
            break;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", w[i]);
    }

    printf("%lld", get_dp(0, 5));

    return 0;
}
