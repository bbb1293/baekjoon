#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int b, m;
int dp[51][1001];

int get_dp(int rest, int level) {
    if (rest == 1) {
        return level;
    }

    if (level == 0) {
        return 0;
    }

    int &ret = dp[rest][level];
    if (ret != -1) {
        return ret;
    }

    ret = INF;
    for (int i = 1; i <= level; i++) {
        ret = min(ret, max(get_dp(rest, level - i),
                           get_dp(rest - 1, i - 1)) +
                           1);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &b, &m);

        memset(dp, -1, sizeof(dp));

        printf("%d\n", get_dp(b, m));
    }

    return 0;
}