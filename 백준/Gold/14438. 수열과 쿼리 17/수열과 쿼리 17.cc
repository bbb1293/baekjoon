#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int a[MAXN + 1];
int seg_tree[4 * MAXN];

void init_seg(int cur, int left, int right) {
    if (left == right) {
        seg_tree[cur] = a[left];
    } else {
        int mid = (left + right) / 2;

        init_seg(cur * 2, left, mid);
        init_seg(cur * 2 + 1, mid + 1, right);

        seg_tree[cur] =
            min(seg_tree[cur * 2], seg_tree[cur * 2 + 1]);
    }
}

int get_seg(int cur, int left, int right, int from,
            int to) {
    if (right < from || to < left) {
        return 1e9;
    } else if (from <= left && right <= to) {
        return seg_tree[cur];
    } else {
        int mid = (left + right) / 2;

        return min(
            get_seg(cur * 2, left, mid, from, to),
            get_seg(cur * 2 + 1, mid + 1, right, from, to));
    }
}

void update_seg(int cur, int left, int right, int target) {
    if (left == right) {
        seg_tree[cur] = a[left];
    } else if (left <= target && target <= right) {
        int mid = (left + right) / 2;

        if (target <= mid) {
            update_seg(cur * 2, left, mid, target);
        } else {
            update_seg(cur * 2 + 1, mid + 1, right, target);
        }

        seg_tree[cur] =
            min(seg_tree[cur * 2], seg_tree[cur * 2 + 1]);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    init_seg(1, 1, n);

    int m;
    scanf("%d", &m);

    while (m--) {
        int q, i, v;
        scanf("%d %d %d", &q, &i, &v);

        if (q == 1) {
            a[i] = v;
            update_seg(1, 1, n, i);
        } else {
            printf("%d\n", get_seg(1, 1, n, i, v));
        }
    }

    return 0;
}