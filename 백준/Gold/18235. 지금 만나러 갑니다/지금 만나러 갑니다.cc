#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5;
int n, a, b;
bool dp1[2][MAXN + 1], dp2[2][MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &a, &b);

    dp1[0][a] = true;
    dp2[0][b] = true;

    for (int i = 1; i < 20; i++) {
        int step = (1 << (i - 1));

        if (step > n) {
            break;
        }

        for (int j = 0; j <= n; j++) {
            dp1[i & 1][j] = false;
            dp2[i & 1][j] = false;
            if (j - step > 0) {
                dp1[i & 1][j] |= dp1[(i & 1) ^ 1][j - step];
                dp2[i & 1][j] |= dp2[(i & 1) ^ 1][j - step];
            }

            if (j + step <= n) {
                dp1[i & 1][j] |= dp1[(i & 1) ^ 1][j + step];
                dp2[i & 1][j] |= dp2[(i & 1) ^ 1][j + step];
            }

            if (dp1[i & 1][j] && dp2[i & 1][j]) {
                printf("%d", i);
                return 0;
            }
        }
    }

    printf("-1");

    return 0;
}
