#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n, m, a;
int h;

long long power_k(int a, int k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return a;
    }

    long long tmp = power_k(a, k / 2);

    if (k & 1) {
        return (((tmp * tmp) % MOD) * a) % MOD;
    }
    return ((tmp * tmp) % MOD);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &a);
    scanf("%d", &h);

    printf("%lld", power_k(m, n - 1));

    return 0;
}
