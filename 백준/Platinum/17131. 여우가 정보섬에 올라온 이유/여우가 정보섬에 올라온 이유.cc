#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
const long long MOD = 1e9 + 7;
int n, x_idx = 0;
pair<int, int> xy[MAXN];
int seg_tree[MAXN * 4];

void update(int target, int cur = 1, int from = 0, int to = x_idx) {
    if (from != to) {
        int mid = (from + to) / 2;

        if (target <= mid) {
            update(target, cur * 2, from, mid);
        } else {
            update(target, cur * 2 + 1, mid + 1, to);
        }
    }
    seg_tree[cur]++;
}

long long query(int l, int r, int cur = 1, int from = 0, int to = x_idx) {
    if (r < from || to < l) {
        return 0;
    } else if (l <= from && to <= r) {
        return seg_tree[cur];
    } else {
        int mid = (from + to) / 2;

        return query(l, r, cur * 2, from, mid) +
               query(l, r, cur * 2 + 1, mid + 1, to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xy[i].second, &xy[i].first);

        xy[i].first = -xy[i].first;
    }

    sort(xy, xy + n, [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });

    int prev = xy[0].second;
    for (int i = 0; i < n; i++) {
        if (prev == xy[i].second) {
            xy[i].second = x_idx;
        } else {
            prev = xy[i].second;
            xy[i].second = ++x_idx;
        }
    }

    sort(xy, xy + n);

    int from = 0;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && xy[i - 1].first != xy[i].first) {
            for (int j = from; j < i; j++) {
                update(xy[j].second);
            }
            from = i;
        }

        ret += (query(0, xy[i].second - 1) * query(xy[i].second + 1, x_idx));
        ret %= MOD;
    }

    printf("%lld", ret);

    return 0;
}
