#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n, m;

long long power(long long a, long long k) {
    if (k == 1) {
        return a;
    }

    long long tmp = power(a, k / 2);

    if (k & 1) {
        return (((tmp * a) % MOD) * tmp) % MOD;
    }

    return ((tmp * tmp) % MOD);
}

long long factorial(long long a) {
    if (a == 0) {
        return 1;
    }

    return (a * factorial(a - 1)) % MOD;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    long long ret = factorial(n);
    ret *= power(factorial(m), MOD - 2);
    ret %= MOD;
    ret *= power(factorial(n - m), MOD - 2);
    ret %= MOD;

    printf("%lld", ret);

    return 0;
}
