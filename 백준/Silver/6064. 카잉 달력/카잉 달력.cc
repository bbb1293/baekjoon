#include <bits/stdc++.h>

using namespace std;

int m, n, x, y;

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d", &m, &n, &x, &y);

        int a = 0, b = 0;

        while (a < n && m * a + x != n * b + y) {
            if (m * a + x > n * b + y) {
                b++;
            } else {
                a++;
            }
        }

        if (a >= n) {
            printf("-1\n");
        } else {
            printf("%d\n", a * m + x);
        }
    }

    return 0;
}
