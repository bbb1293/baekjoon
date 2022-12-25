#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int h[MAXN];

long long get_max(int left, int right) {
    if (left == right) {
        return h[left];
    }

    int mid = (left + right) / 2;
    long long ret =
        max(get_max(left, mid), get_max(mid + 1, right));

    int l = mid, r = mid;
    long long cur_h = h[mid], cand = h[mid];

    while (true) {
        if (l == left && r == right) {
            break;
        }

        if (l == left ||
            (r != right && h[l - 1] < h[r + 1])) {
            r++;
            cur_h = min(cur_h, (long long)h[r]);
            cand = max(cand, (r - l + 1) * cur_h);
        } else {
            l--;
            cur_h = min(cur_h, (long long)h[l]);
            cand = max(cand, (r - l + 1) * cur_h);
        }
    }

    return max(ret, cand);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    printf("%lld", get_max(0, n - 1));

    return 0;
}