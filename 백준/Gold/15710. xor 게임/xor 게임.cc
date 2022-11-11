#include <bits/stdc++.h>

using namespace std;

long long a, b, n;

const long long MOD = 1e9 + 7, U = ((1ll << 31) % MOD);

long long get_power(long long k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return U;
    }

    long long tmp = get_power(k / 2);

    if (k & 1) {
        return (((tmp * U) % MOD) * tmp) % MOD;
    }

    return ((tmp * tmp) % MOD);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld", &a, &b, &n);

    printf("%lld", get_power(n - 1));

    return 0;
}