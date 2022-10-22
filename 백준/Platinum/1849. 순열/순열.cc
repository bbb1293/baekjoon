#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int seg[4 * MAXN], ret[MAXN];

void update(int cur, int left, int right, int target) {
    if (left != right) {
        int mid = (left + right) / 2;

        if (target <= mid) {
            update(cur * 2, left, mid, target);
        } else {
            update(cur * 2 + 1, mid + 1, right, target);
        }
    }
    seg[cur]++;
}

int find_kth(int cur, int left, int right, int k) {
    if (left == right) {
        return left;
    }

    int mid = (left + right) / 2;

    if ((mid - left + 1) - seg[cur * 2] <= k) {
        return find_kth(
            cur * 2 + 1, mid + 1, right,
            k - ((mid - left + 1) - seg[cur * 2]));
    }
    return find_kth(cur * 2, left, mid, k);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);

        int idx = find_kth(1, 0, n - 1, p);
        ret[idx] = i;

        update(1, 0, n - 1, idx);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ret[i] + 1);
    }

    return 0;
}