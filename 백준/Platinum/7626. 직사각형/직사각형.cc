#include <bits/stdc++.h>

using namespace std;

struct Line {
    int y_1, y_2, x, num;
};

const int MAXM = 4e5;
int n, x_idx = 0;
Line lines[MAXM];
vector<int> ys;
int cnt[MAXM * 4];
long long seg_tree[MAXM * 4];

void update(int left, int right, int num, int cur = 1, int from = 0,
            int to = ys.size() - 1) {
    if (right < from || to < left) {
        return;
    } else if (left <= from && to <= right) {
        cnt[cur] += num;
    } else {
        int mid = (from + to) / 2;
        update(left, right, num, cur * 2, from, mid);
        update(left, right, num, cur * 2 + 1, mid + 1, to);
    }

    if (cnt[cur]) {
        seg_tree[cur] = ys[to + 1] - ys[from];
    } else {
        if (from == to) {
            seg_tree[cur] = 0;
        } else {
            seg_tree[cur] = seg_tree[cur * 2] + seg_tree[cur * 2 + 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &x2, &y1, &y2);

        lines[i * 2] = {y1, y2, x1, 1};
        lines[i * 2 + 1] = {y1, y2, x2, -1};
        ys.push_back(y1);
        ys.push_back(y2);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    sort(lines, lines + 2 * n, [](Line &a, Line &b) { return a.x < b.x; });

    long long ret = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i != 0 && lines[i - 1].x != lines[i].x) {
            ret += (seg_tree[1] * (lines[i].x - lines[i - 1].x));
        }

        int l = (lower_bound(ys.begin(), ys.end(), lines[i].y_1) - ys.begin());
        int r = (lower_bound(ys.begin(), ys.end(), lines[i].y_2) - ys.begin());

        update(l, r - 1, lines[i].num);
    }

    printf("%lld", ret);

    return 0;
}
