#include <bits/stdc++.h>

using namespace std;

int c, e, m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &c, &e, &m);

    if (c != 4 || (e & 1)) {
        printf("impossible");
        return 0;
    }

    if (m == 0) {
        printf("2 %d", e / 2 + 2);
    } else {
        for (int i = 1; i < 100000; i++) {
            if (!(m % i) && (2 * (i + m / i)) == e) {
                printf("%d %d", (m / i) + 2, i + 2);
                return 0;
            }
        }

        printf("impossible");
    }

    return 0;
}