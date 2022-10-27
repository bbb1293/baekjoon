#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int p[MAXN], left_p[MAXN][2], right_p[MAXN][2];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    left_p[0][0] = left_p[0][1] = p[0];
    for (int i = 1; i < n; i++) {
        left_p[i][0] = max(left_p[i - 1][0] + p[i], p[i]);
        left_p[i][1] = min(left_p[i - 1][1] + p[i], p[i]);
    }

    for (int i = 1; i < n; i++) {
        left_p[i][0] = max(left_p[i - 1][0], left_p[i][0]);
        left_p[i][1] = min(left_p[i - 1][1], left_p[i][1]);
    }

    right_p[n - 1][0] = right_p[n - 1][1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right_p[i][0] = max(right_p[i + 1][0] + p[i], p[i]);
        right_p[i][1] = min(right_p[i + 1][1] + p[i], p[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        right_p[i][0] =
            max(right_p[i + 1][0], right_p[i][0]);
        right_p[i][1] =
            min(right_p[i + 1][1], right_p[i][1]);
    }

    long long ret = -1e15;
    for (int i = 1; i < n; i++) {
        ret = max(ret, (long long)left_p[i - 1][0] *
                           right_p[i][0]);
        ret = max(ret, (long long)left_p[i - 1][1] *
                           right_p[i][1]);
    }

    printf("%lld", ret);

    return 0;
}