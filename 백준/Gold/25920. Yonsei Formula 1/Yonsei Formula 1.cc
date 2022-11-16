#include <bits/stdc++.h>

using namespace std;

int n, m;
long long l, a, b, d;
long long dp[101], cost[101];

long long get_round(long long consumed_time) {
    consumed_time--;

    long long th_time = (a - b) / d;
    long long cur_len = 0;
    if (consumed_time < th_time) {
        if (2e11 / (consumed_time + 1) <=
            (2 * a - consumed_time * d)) {
            return 100;
        }

        cur_len = (2 * a - consumed_time * d) *
                  (consumed_time + 1) / 2;
    } else {
        if (2e11 / (th_time + 1) <= (a + b)) {
            return 100;
        }

        cur_len = (a + b) * (th_time + 1) / 2;
        consumed_time -= th_time;

        if (1e11 / b <= consumed_time) {
            return 100;
        }

        cur_len += (consumed_time * b);
    }

    return cur_len / l;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %lld", &n, &m, &l);

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    while (n--) {
        scanf("%lld %lld %lld", &a, &b, &d);

        for (int i = 1; i <= m; i++) {
            long long left = 1, right = 1e11;

            while (left <= right) {
                long long mid = (left + right) / 2;

                if (i <= get_round(mid)) {
                    cost[i] = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        for (int i = m; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                int round = i - j;
                if (dp[j] != -1 &&
                    (dp[i] == -1 ||
                     dp[j] + cost[round] < dp[i])) {
                    dp[i] = dp[j] + cost[round];
                }
            }
        }
    }

    printf("%lld", dp[m]);

    return 0;
}