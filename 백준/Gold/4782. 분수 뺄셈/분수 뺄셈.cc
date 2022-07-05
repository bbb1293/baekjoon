#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    while (true) {
        long long b, n;
        scanf("%lld %lld", &b, &n);

        if (b == 0 && n == 0) {
            break;
        }

        for (long long m = 2 * n; m > 0; m--) {
            if (m == n) {
                continue;
            }

            long long upper = b * m * (2 * n - m);
            long long lower = n * n;

            if (!(upper % lower)) {
                printf("%lld/%lld ", upper / lower, m);
            }
        }

        printf("\n");
    }

    return 0;
}
