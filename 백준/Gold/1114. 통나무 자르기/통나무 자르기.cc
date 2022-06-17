#include <bits/stdc++.h>

using namespace std;

int l, k, c;
int pos[10001];

bool possible(int max_l) {
    int cnt = c, prev = 0;
    for (int i = 1; i <= k; i++) {
        if (pos[i] - prev > max_l) {
            if (cnt == 0) {
                return false;
            }

            cnt--;
            prev = pos[i - 1];
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &l, &k, &c);

    for (int i = 0; i < k; i++) {
        scanf("%d", &pos[i]);
    }
    pos[k] = l;

    sort(pos, pos + (k + 1));

    int left = pos[0];
    for (int i = 1; i <= k; i++) {
        left = max(left, pos[i] - pos[i - 1]);
    }

    int right = l, target = right;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (possible(mid)) {
            target = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    int cnt = c;
    right = l;
    for (int i = k - 1; i >= 0; i--) {
        if (right - pos[i] > target) {
            cnt--;
            right = pos[i + 1];
        }
    }

    if (cnt) {
        printf("%lld %lld\n", target, pos[0]);
    } else {
        printf("%lld %lld\n", target, right);
    }

    return 0;
}
