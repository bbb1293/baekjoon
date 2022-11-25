#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5, MAXK = 1e6;
int n, k;
long long presum[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    int a, b, cur_right;
    scanf("%d %d", &a, &cur_right);

    for (int i = 2; i <= n; i++) {
        scanf("%d %d", &a, &b);

        if (a <= cur_right) {
            presum[i] = presum[i - 1];
            cur_right = max(b, cur_right);
        } else {
            presum[i] = presum[i - 1] + (a - cur_right);
            cur_right = b;
        }
    }

    int cur = 1;
    long long ret = 0;
    while (k--) {
        int target;
        scanf("%d", &target);

        ret += abs(presum[target] - presum[cur]);
        cur = target;
    }

    printf("%lld", ret);

    return 0;
}
