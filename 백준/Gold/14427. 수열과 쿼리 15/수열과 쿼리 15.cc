#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int a[MAXN], seg[4 * MAXN];

void init_seg(int cur, int left, int right) {
    if (left == right) {
        seg[cur] = left;
    } else {
        int mid = (left + right) / 2;

        init_seg(cur * 2, left, mid);
        init_seg(cur * 2 + 1, mid + 1, right);

        if (a[seg[cur * 2]] <= a[seg[cur * 2 + 1]]) {
            seg[cur] = seg[cur * 2];
        } else {
            seg[cur] = seg[cur * 2 + 1];
        }
    }
}

void update(int cur, int left, int right, int target) {
    if (left != right) {
        int mid = (left + right) / 2;

        if (target <= mid) {
            update(cur * 2, left, mid, target);
        } else {
            update(cur * 2 + 1, mid + 1, right, target);
        }

        if (a[seg[cur * 2]] <= a[seg[cur * 2 + 1]]) {
            seg[cur] = seg[cur * 2];
        } else {
            seg[cur] = seg[cur * 2 + 1];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    init_seg(1, 0, n - 1);

    int m;
    scanf("%d", &m);

    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int i, v;
            scanf("%d %d", &i, &v);

            a[i - 1] = v;
            update(1, 0, n - 1, i - 1);
        } else {
            printf("%d\n", seg[1] + 1);
        }
    }

    return 0;
}