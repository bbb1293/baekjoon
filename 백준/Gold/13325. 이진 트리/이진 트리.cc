#include <bits/stdc++.h>

using namespace std;

const int MAXK = (1 << 21);
int k, last_k;
int dist[MAXK], dp[MAXK];

int set_dp(int cur) {
    int ret = 0;
    if (cur * 2 < last_k) {
        ret += set_dp(cur * 2);
        ret += set_dp(cur * 2 + 1);

        int diff = abs(dp[cur * 2] - dp[cur * 2 + 1]);
        ret += (diff + dist[cur * 2] + dist[cur * 2 + 1]);
        dp[cur] = max(dp[cur * 2], dp[cur * 2 + 1]);
    }
    dp[cur] += dist[cur];

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &k);
    last_k = (1 << (k + 1));
    for (int i = 2; i < last_k; i++) {
        scanf("%d", &dist[i]);
    }

    printf("%d", set_dp(1));

    return 0;
}