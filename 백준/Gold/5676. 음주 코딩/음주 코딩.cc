#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, k;
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
            seg_tree[cur * 2] * seg_tree[cur * 2 + 1];
    }
}

int get_seg(int cur, int left, int right, int from,
            int to) {
    if (right < from || to < left) {
        return 1;
    } else if (from <= left && right <= to) {
        return seg_tree[cur];
    } else {
        int mid = (left + right) / 2;

        return get_seg(cur * 2, left, mid, from, to) *
               get_seg(cur * 2 + 1, mid + 1, right, from,
                       to);
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
            seg_tree[cur * 2] * seg_tree[cur * 2 + 1];
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (scanf("%d %d", &n, &k) > 0) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);

            if (a[i] > 0) {
                a[i] = 1;
            } else if (a[i] < 0) {
                a[i] = -1;
            }
        }
        init_seg(1, 1, n);

        char op;
        int i, j;
        while (k--) {
            scanf(" %c %d %d", &op, &i, &j);

            if (op == 'C') {
                a[i] = j;
                if (a[i] > 0) {
                    a[i] = 1;
                } else if (a[i] < 0) {
                    a[i] = -1;
                }

                update_seg(1, 1, n, i);
            } else {
                int ret = get_seg(1, 1, n, i, j);

                if (ret < 0) {
                    printf("-");
                } else if (ret > 0) {
                    printf("+");
                } else {
                    printf("0");
                }
            }
        }
        printf("\n");
    }

    return 0;
}