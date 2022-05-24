#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n, r, m;
int pos[MAXN + 1], diff[2 * MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%d %d", &r, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    sort(pos, pos + n);

    pos[n] = pos[0] + m;

    for (int i = 0; i < n; i++) {
        diff[i] = diff[i + n] = (pos[i + 1] - pos[i] - 2 * r);
    }

    int sum = 0, ret = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += diff[i];
        if (sum < 0) {
            sum = 0;
        }
        ret = max(ret, sum);
    }

    printf("%d", (ret + 1) / 2);

    return 0;
}
