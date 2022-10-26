#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
long long m;
long long f[MAXN + 1], s[MAXN + 1], seg[4 * MAXN];

void init_seg(int cur, int left, int right) {
    if (left == right) {
        seg[cur] = s[left];
    } else {
        int mid = (left + right) / 2;

        init_seg(cur * 2, left, mid);
        init_seg(cur * 2 + 1, mid + 1, right);

        seg[cur] = max(seg[cur * 2], seg[cur * 2 + 1]);
    }
}

long long query(int cur, int left, int right, int from,
                int to) {
    if (from <= left && right <= to) {
        return seg[cur];
    } else if (right < from || to < left) {
        return 0;
    }

    int mid = (left + right) / 2;

    return max(
        query(cur * 2, left, mid, from, to),
        query(cur * 2 + 1, mid + 1, right, from, to));
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &f[i], &s[i]);
        f[i] += f[i - 1];
    }

    init_seg(1, 1, n);

    long long ret = seg[1];
    for (int i = 1; i <= n; i++) {
        int left = 0, right = i - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (f[i] - f[mid] >= m) {
                long long target =
                    query(1, 1, n, mid + 1, i);
                ret = min(ret, target);

                left = mid + 1;

            } else {
                right = mid - 1;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}