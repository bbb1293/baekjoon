#include <bits/stdc++.h>

using namespace std;

const int MAXN = 75000;
int n;
int x_idx;
int seg_tree[MAXN * 4], num[MAXN];
pair<int, int> xys[MAXN];

void init(int cur = 1, int from = 0, int to = x_idx) {
    if (from == to) {
        seg_tree[cur] = num[from];
    } else {
        int mid = (from + to) / 2;
        init(cur * 2, from, mid);
        init(cur * 2 + 1, mid + 1, to);

        seg_tree[cur] = seg_tree[cur * 2] + seg_tree[cur * 2 + 1];
    }
}

void update(int target, int cur = 1, int from = 0, int to = x_idx) {
    if (from == to) {
        seg_tree[cur] -= 1;
    } else {
        int mid = (from + to) / 2;
        if (target <= mid) {
            update(target, cur * 2, from, mid);
        } else {
            update(target, cur * 2 + 1, mid + 1, to);
        }
        seg_tree[cur] -= 1;
    }
}

int get_num(int left, int cur = 1, int from = 0, int to = x_idx) {
    if (left <= from) {
        return seg_tree[cur];
    } else {
        int mid = (from + to) / 2;

        if (left <= mid) {
            return get_num(left, cur * 2, from, mid) + seg_tree[cur * 2 + 1];
        }

        return get_num(left, cur * 2 + 1, mid + 1, to);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--) {
        memset(num, 0, sizeof(num));
        x_idx = 0;

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> xys[i].second >> xys[i].first;
            xys[i].first = -xys[i].first;
        }

        sort(xys, xys + n, [](pair<int, int> &a, pair<int, int> &b) {
            return make_pair(a.second, a.first) < make_pair(b.second, b.first);
        });

        xys[0].second = 0;
        for (int i = 1; i < n; i++) {
            if (xys[i - 1].second == xys[i].second) {
                xys[i].second = x_idx;
            } else {
                xys[i].second = ++x_idx;
            }
        }

        sort(xys, xys + n);

        for (int i = 0; i < n; i++) {
            auto cur = xys[i];
            num[cur.second]++;
        }
        init();

        long long ret = 0;
        for (int i = 0; i < n; i++) {
            auto cur = xys[i];
            update(cur.second);
            ret += get_num(cur.second);
        }

        cout << ret << '\n';
    }

    return 0;
}
