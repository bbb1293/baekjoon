#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int h[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
        h[i] += h[i - 1];
    }

    int ret = 0;
    for (int i = 2; i < n; i++) {
        ret = max(ret, h[n] - h[1] - (h[i] - h[i - 1]) +
                           h[n] - h[i]);
        ret = max(ret, h[n] - (h[n] - h[n - 1]) -
                           (h[i] - h[i - 1]) + h[i - 1]);
        ret = max(ret, h[n - 1] - h[1] + (h[i] - h[i - 1]));
    }

    printf("%d", ret);

    return 0;
}