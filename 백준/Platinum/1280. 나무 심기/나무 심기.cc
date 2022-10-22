#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const long long MOD = 1e9 + 7;
int n;
long long cnt[MAXN + 1], sum[MAXN + 1];

void update(int target) {
    for (int i = target; i <= MAXN; i = (i | (i + 1))) {
        cnt[i]++;
        sum[i] += target;
        sum[i] %= MOD;
    }
}

pair<long long, long long> get_sum(int to) {
    pair<long long, long long> ret = {0, 0};
    for (int i = to; i >= 0; i = ((i & (i + 1)) - 1)) {
        ret.first += cnt[i];
        ret.second += sum[i];
        ret.second %= MOD;
    }

    return ret;
}

pair<long long, long long> get_range(int from, int to) {
    pair<long long, long long> ret1 = get_sum(to),
                               ret2 = get_sum(from - 1);

    return {ret1.first - ret2.first,
            (ret1.second - ret2.second + MOD) % MOD};
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    long long ret = 1;
    for (int i = 0; i < n; i++) {
        int pos;
        scanf("%d", &pos);

        if (i != 0) {
            long long tmp = 0;

            if (pos != 0) {
                pair<long long, long long> left =
                    get_sum(pos - 1);

                tmp += ((((left.first * pos) % MOD) -
                         left.second + MOD) %
                        MOD);
                tmp %= MOD;
            }

            pair<long long, long long> right =
                get_range(pos + 1, MAXN);

            tmp += ((right.second -
                     ((right.first * pos) % MOD) + MOD) %
                    MOD);
            tmp %= MOD;

            ret *= tmp;
            ret %= MOD;
        }

        update(pos);
    }

    printf("%lld", ret);

    return 0;
}