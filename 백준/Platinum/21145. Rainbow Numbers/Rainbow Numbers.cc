#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
const long long MOD = 998244353;
char lu[2][MAXN + 1];

long long get_power(int a, int r) {
    if (r == 0) {
        return 1;
    }

    if (r == 1) {
        return a;
    }

    long long tmp = get_power(a, r / 2);

    if (r & 1) {
        return (((tmp * a) % MOD) * tmp) % MOD;
    }

    return ((tmp * tmp) % MOD);
}

int is_rainbow(int idx) {
    int n = strlen(lu[idx]);

    for (int i = 1; i < n; i++) {
        if (lu[idx][i - 1] == lu[idx][i]) {
            return 0;
        }
    }

    return 1;
}

long long get_inv(int a) { return get_power(a, MOD - 2); }

long long get_cnt(int idx) {
    int n = strlen(lu[idx]);

    long long cnt =
        (((((get_power(9, n - 1) - 1 + MOD) % MOD) * 9) %
          MOD) *
         get_inv(8)) %
        MOD;

    for (int i = 0; i < n; i++) {
        int cur = lu[idx][i] - '0';

        if (i == 0) {
            cur--;
        } else {
            int prev = lu[idx][i - 1] - '0';

            if (prev < cur) {
                cur--;
            }
        }

        if (cur > 0) {
            cnt += ((cur * get_power(9, n - i - 1)) % MOD);
            cnt %= MOD;
        }

        if (i != 0 && lu[idx][i - 1] == lu[idx][i]) {
            break;
        }
    }

    cnt += is_rainbow(idx);
    cnt %= MOD;

    return cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", lu[0]);
    scanf("%s", lu[1]);

    long long ret =
        (get_cnt(1) - get_cnt(0) + is_rainbow(0) + MOD) %
        MOD;

    printf("%lld", ret);

    return 0;
}