#include <bits/stdc++.h>

using namespace std;

long long n;

long long times5(long long k) {
    long long ret = k;

    for (int i = 0; i < 4; i++) {
        ret *= k;
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld", &n);

    long long ret = 0;
    while (n) {
        ret += times5(n % 10);
        n /= 10;
    }

    printf("%lld", ret);

    return 0;
}
