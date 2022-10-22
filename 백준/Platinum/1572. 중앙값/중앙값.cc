#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250000, MAXM = 65536;
int n, k;
int t[MAXN], seg[4 * MAXM];

void update(int cur, int left, int right, int target,
            int num) {
    if (left == right) {
        seg[cur] += num;
    } else {
        int mid = (left + right) / 2;

        if (target <= mid) {
            update(cur * 2, left, mid, target, num);
        } else {
            update(cur * 2 + 1, mid + 1, right, target,
                   num);
        }

        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}

int get_kth(int cur, int left, int right, int k) {
    if (left == right) {
        return left;
    }

    int mid = (left + right) / 2;

    if (seg[cur * 2] < k) {
        return get_kth(cur * 2 + 1, mid + 1, right,
                       k - seg[cur * 2]);
    }
    return get_kth(cur * 2, left, mid, k);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    long long ret = 0;
    int target = (k + 1) / 2;

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);

        update(1, 0, MAXM, t[i], 1);
        if (k - 1 <= i) {
            ret += get_kth(1, 0, MAXM, target);

            update(1, 0, MAXM, t[i - k + 1], -1);
        }
    }

    printf("%lld", ret);

    return 0;
}