#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int a[MAXN], seg[4 * MAXN];

void init(int cur, int left, int right) {
    if (left == right) {
        seg[cur] = a[left];
    } else {
        int mid = (left + right) / 2;

        init(cur * 2, left, mid);
        init(cur * 2 + 1, mid + 1, right);

        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}

void update(int cur, int left, int right, int target) {
    if (left == right) {
        seg[cur] ^= 1;
    } else {
        int mid = (left + right) / 2;

        if (target <= mid) {
            update(cur * 2, left, mid, target);
        } else {
            update(cur * 2 + 1, mid + 1, right, target);
        }

        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}

int query(int cur, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return seg[cur];
    } else if (right < from || to < left) {
        return 0;
    } else {
        int mid = (left + right) / 2;

        return query(cur * 2, left, mid, from, to) +
               query(cur * 2 + 1, mid + 1, right, from, to);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i] &= 1;
    }

    init(1, 0, n - 1);

    int m;
    scanf("%d", &m);

    while (m--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        l--;

        if (op == 1) {
            r &= 1;
            if (a[l] != r) {
                a[l] = r;
                update(1, 0, n - 1, l);
            }
        } else {
            r--;

            int cnt = query(1, 0, n - 1, l, r);

            if (op == 2) {
                cnt = (r - l + 1) - cnt;
            }

            printf("%d\n", cnt);
        }
    }

    return 0;
}