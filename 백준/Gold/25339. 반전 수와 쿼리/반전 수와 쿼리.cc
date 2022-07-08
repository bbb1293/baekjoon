#include <bits/stdc++.h>

using namespace std;

int n, q;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &q);

    int parity = 0;
    while (q--) {
        int a, l, r;
        scanf("%d %d %d", &a, &l, &r);

        if (a == 1) {
            parity ^= 1;
        } else {
            long long len = r - l + 1;
            len *= (len - 1);
            len /= 2;

            if (len & 1) {
                parity ^= 1;
            }
        }
        printf("%d\n", parity);
    }

    return 0;
}
