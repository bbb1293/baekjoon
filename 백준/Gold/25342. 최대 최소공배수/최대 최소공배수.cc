#include <bits/stdc++.h>

using namespace std;

long long get_gcd(long long a, long long b) {
    while (a != 0) {
        long long tmp = b % a;
        b = a;
        a = tmp;
    }

    return b;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        long long n;
        scanf("%lld", &n);

        if (n & 1) {
            printf("%lld\n", n * (n - 1) * (n - 2));
        } else {
            long long ret = (n - 1) * (n - 2) * (n - 3);
            long long tmp = n * (n - 1);

            for (int i = 2; i < 5; i++) {
                long long cand = tmp / get_gcd(tmp, n - i) * (n - i);
                if (ret < cand) {
                    ret = cand;
                }
            }
            printf("%lld\n", ret);
        }
    }

    return 0;
}
