#include <bits/stdc++.h>

using namespace std;

struct Query {
    int l, r, idx;
    long long sum;

    const bool operator<(const Query &a) const {
        return sum < a.sum;
    }
};

const int MAXN = 3e5;
int n, q;
long long presum[MAXN + 1];
long long seg[2][4 * MAXN], ret[MAXN];
pair<long long, int> sortedpresum[MAXN];
Query query[MAXN];

void init(int cur, int left, int right) {
    if (left == right) {
        seg[0][cur] = 2 * presum[left];
        seg[1][cur] = -1e15;
    } else {
        int mid = (left + right) / 2;

        init(cur * 2, left, mid);
        init(cur * 2 + 1, mid + 1, right);

        seg[0][cur] =
            min(seg[0][cur * 2], seg[0][cur * 2 + 1]);
        seg[1][cur] = -1e15;
    }
}

void update(int cur, int left, int right, int target,
            long long num, int idx) {
    if (left == right) {
        seg[idx][cur] = num;
    } else {
        int mid = (left + right) / 2;

        if (target <= mid) {
            update(cur * 2, left, mid, target, num, idx);
        } else {
            update(cur * 2 + 1, mid + 1, right, target, num,
                   idx);
        }

        if (idx == 0) {
            seg[idx][cur] = min(seg[idx][cur * 2],
                                seg[idx][cur * 2 + 1]);
        } else {
            seg[idx][cur] = max(seg[idx][cur * 2],
                                seg[idx][cur * 2 + 1]);
        }
    }
}

long long get_range(int cur, int left, int right, int from,
                    int to, int idx) {
    if (from <= left && right <= to) {
        return seg[idx][cur];
    } else if (right < from || to < left) {
        if (idx == 0) {
            return 1e15;
        }
        return -1e15;
    } else {
        int mid = (left + right) / 2;

        long long left_ret =
            get_range(cur * 2, left, mid, from, to, idx);
        long long right_ret = get_range(
            cur * 2 + 1, mid + 1, right, from, to, idx);

        if (idx == 0) {
            return min(left_ret, right_ret);
        }
        return max(left_ret, right_ret);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &presum[i]);
        presum[i] += presum[i - 1];
        sortedpresum[i] = {2 * presum[i], i};
    }

    init(1, 1, n);

    sort(sortedpresum, sortedpresum + n,
         [](pair<long long, int> &a,
            pair<long long, int> &b) {
             return a.first < b.first;
         });

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &query[i].l, &query[i].r);
        query[i].idx = i;
        query[i].sum =
            presum[query[i].r] + presum[query[i].l - 1];
    }
    sort(query, query + q);

    int sorted_idx = 0;
    for (int i = 0; i < q; i++) {
        while (sorted_idx < n &&
               sortedpresum[sorted_idx].first <=
                   query[i].sum) {
            update(1, 1, n, sortedpresum[sorted_idx].second,
                   1e15, 0);
            update(1, 1, n, sortedpresum[sorted_idx].second,
                   sortedpresum[sorted_idx].first, 1);
            sorted_idx++;
        }

        int c = (query[i].r - query[i].l + 1) / 3;
        int from = query[i].l + c - 1, to = query[i].r - c;
        long long cand1 = get_range(1, 1, n, from, to, 0);
        long long cand2 = get_range(1, 1, n, from, to, 1);

        ret[query[i].idx] =
            min(abs(get_range(1, 1, n, from, to, 0) -
                    query[i].sum),
                abs(get_range(1, 1, n, from, to, 1) -
                    query[i].sum));
    }

    for (int i = 0; i < q; i++) {
        printf("%lld\n", ret[i]);
    }

    return 0;
}
