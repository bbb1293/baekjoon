#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int k;
long long r, c;
pair<long long, long long> yx[1000];
set<long long> s;

long long get_power(long long a, long long k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return a;
    }

    long long ret = get_power(a, k / 2);

    if (k & 1) {
        return (((ret * a) % MOD) * ret) % MOD;
    }

    return ((ret * ret) % MOD);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld %d", &r, &c, &k);

    int cnt = 0;
    for (int i = 0; i < k; i++) {
        scanf("%lld %lld", &yx[i].first, &yx[i].second);

        if (s.count(yx[i].first) == 0) {
            s.insert(yx[i].first);
            cnt++;
        }
    }

    long long ret1 = (c / 2) * (r - cnt), ret2 = 1;
    if (c & 1) {
        ret2 = get_power(c / 2 + 1, r - cnt);
    }

    if (k != 0) {
        sort(yx, yx + k);

        long long cur_r = -1, from = c;
        for (int i = 0; i < k; i++) {
            auto [y, x] = yx[i];

            if (cur_r == y) {
                long long dist = x - from;
                ret1 += (dist / 2);
                if ((dist > 1) && (dist & 1)) {
                    ret2 *= (dist / 2 + 1);
                    ret2 %= MOD;
                }
            } else {
                long long dist = c - from + 1;
                ret1 += (dist / 2);
                if ((dist > 1) && (dist & 1)) {
                    ret2 *= (dist / 2 + 1);
                    ret2 %= MOD;
                }

                cur_r = y;

                dist = x - 1;
                ret1 += (dist / 2);
                if ((dist > 1) && (dist & 1)) {
                    ret2 *= (dist / 2 + 1);
                    ret2 %= MOD;
                }
            }
            from = x + 1;
        }

        long long dist = c - from + 1;
        ret1 += (dist / 2);
        if ((dist > 1) && (dist & 1)) {
            ret2 *= (dist / 2 + 1);
            ret2 %= MOD;
        }
    }

    printf("%lld %lld", ret1, ret2);

    return 0;
}
