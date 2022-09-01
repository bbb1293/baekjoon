#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n;
int a[MAXN], b[MAXN];
int dp1[MAXN][3], dp2[MAXN][3];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + n);

    dp1[0][0] = 1e9;
    dp1[0][1] = abs(a[0] - b[0]);
    dp1[0][2] = abs(a[0] - b[1]);

    for (int i = 1; i < n; i++) {
        dp1[i][0] = max(dp1[i - 1][0], abs(a[i] - b[i - 1]));
        dp1[i][1] = max(min(dp1[i - 1][0], dp1[i - 1][1]), abs(a[i] - b[i]));

        if (i != n - 1) {
            dp1[i][2] =
                max(min(dp1[i - 1][0], min(dp1[i - 1][1], dp1[i - 1][2])),
                    abs(a[i] - b[i + 1]));
        } else {
            dp1[i][2] = 1e9;
        }
    }

    dp2[n - 1][0] = abs(a[n - 1] - b[n - 2]);
    dp2[n - 1][1] = abs(a[n - 1] - b[n - 1]);
    dp2[n - 1][2] = 1e9;

    for (int i = n - 2; i >= 0; i--) {
        dp2[i][2] = max(dp2[i + 1][2], abs(a[i] - b[i + 1]));
        dp2[i][1] = max(min(dp2[i + 1][1], dp2[i + 1][2]), abs(a[i] - b[i]));

        if (i != 0) {
            dp2[i][0] =
                max(min(dp2[i + 1][0], min(dp2[i + 1][1], dp2[i + 1][2])),
                    abs(a[i] - b[i - 1]));
        } else {
            dp2[i][0] = 1e9;
        }
    }

    int ret = a[0], diff = min(dp2[1][0], dp2[1][1]);

    for (int i = 1; i < n; i++) {
        int cur_diff = min(dp1[i - 1][1], dp1[i - 1][2]);

        if (i != n - 1) {
            cur_diff = max(cur_diff, min(dp2[i + 1][0], dp2[i + 1][1]));
        }

        if (cur_diff < diff) {
            diff = cur_diff;
            ret = a[i];
        }
    }

    printf("%d", ret);

    return 0;
}