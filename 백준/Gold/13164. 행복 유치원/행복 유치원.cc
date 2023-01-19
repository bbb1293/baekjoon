#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
int n, k;
int h[MAXN], diff[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);

        if (i != 0) {
            diff[i - 1] = h[i] - h[i - 1];
        }
    }

    int ret = h[n - 1] - h[0];

    sort(diff, diff + n - 1);
    for (int i = 0; i < k - 1; i++) {
        ret -= diff[n - 2 - i];
    }

    printf("%d", ret);

    return 0;
}
