#include <bits/stdc++.h>

using namespace std;

struct Info {
    int k, from, to, idx;

    const bool operator<(const Info &a) const {
        return k < a.k;
    }
};

const int MAXN = 1e5;
int n;
long long a[MAXN], seg[4 * MAXN];
long long ret[MAXN];
pair<int, int> query1[MAXN];
Info query2[MAXN];

void init_seg(int cur, int left, int right) {
    if (left == right) {
        seg[cur] = a[left];
    } else {
        int mid = (left + right) / 2;

        init_seg(cur * 2, left, mid);
        init_seg(cur * 2 + 1, mid + 1, right);

        seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    }
}

void update(int cur, int left, int right, int target) {
    if (left == right) {
        seg[cur] = a[left];
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

long long get_range(int cur, int left, int right, int from,
                    int to) {
    if (from <= left && right <= to) {
        return seg[cur];
    } else if (right < from || to < left) {
        return 0;
    }

    int mid = (left + right) / 2;

    return get_range(cur * 2, left, mid, from, to) +
           get_range(cur * 2 + 1, mid + 1, right, from, to);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    init_seg(1, 0, n - 1);

    int m;
    scanf("%d", &m);

    int cnt1 = 0, cnt2 = 0;
    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int i, v;
            scanf("%d %d", &i, &v);

            query1[cnt1++] = {i - 1, v};
        } else {
            int k, from, to;
            scanf("%d %d %d", &k, &from, &to);

            query2[cnt2] = {k - 1, from - 1, to - 1, cnt2};
            cnt2++;
        }
    }

    sort(query2, query2 + cnt2);

    int left = 0;
    while (left < cnt2 && query2[left].k == -1) {
        ret[query2[left].idx] =
            get_range(1, 0, n - 1, query2[left].from,
                      query2[left].to);
        left++;
    }

    for (int i = 0; i < cnt1; i++) {
        a[query1[i].first] = query1[i].second;
        update(1, 0, n - 1, query1[i].first);

        while (left < cnt2 && query2[left].k == i) {
            ret[query2[left].idx] =
                get_range(1, 0, n - 1, query2[left].from,
                          query2[left].to);
            left++;
        }
    }

    for (int i = 0; i < cnt2; i++) {
        printf("%lld\n", ret[i]);
    }

    return 0;
}