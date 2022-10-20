#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int num[MAXN + 1], seg_tree[4 * MAXN];
long long presum[MAXN + 1];

void init_seg(int cur, int left, int right) {
    if (left == right) {
        seg_tree[cur] = left;
    } else {
        int mid = (left + right) / 2;

        init_seg(cur * 2, left, mid);
        init_seg(cur * 2 + 1, mid + 1, right);

        if (num[seg_tree[cur * 2]] <
            num[seg_tree[cur * 2 + 1]]) {
            seg_tree[cur] = seg_tree[cur * 2];
        } else {
            seg_tree[cur] = seg_tree[cur * 2 + 1];
        }
    }
}

int get_seg(int cur, int left, int right, int from,
            int to) {
    if (from <= left && right <= to) {
        return seg_tree[cur];
    } else if (right < from || to < left) {
        return 0;
    } else {
        int mid = (left + right) / 2;

        int l = get_seg(cur * 2, left, mid, from, to);
        int r =
            get_seg(cur * 2 + 1, mid + 1, right, from, to);

        if (num[l] < num[r]) {
            return l;
        } else {
            return r;
        }
    }
}

long long get_ret(int left, int right) {
    if (right < left) {
        return 0;
    }

    long long sum = presum[right] - presum[left - 1];

    int idx = get_seg(1, 1, n, left, right);

    long long cand = sum * num[idx];

    if (idx != left) {
        cand = max(cand, get_ret(left, idx - 1));
    }

    if (idx != right) {
        cand = max(cand, get_ret(idx + 1, right));
    }

    return cand;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    num[0] = 1e7;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        presum[i] = presum[i - 1] + num[i];
    }

    init_seg(1, 1, n);

    printf("%lld", get_ret(1, n));

    return 0;
}