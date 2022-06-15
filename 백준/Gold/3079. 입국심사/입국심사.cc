#include <bits/stdc++.h>

using namespace std;

int n, m;
int t[100000];

bool possible(long long n_t) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (n_t / t[i]);

        if (cnt >= m) {
            return true;
        }
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }

    long long left = 1, right = 1e18;
    long long ret = right;
    while (left <= right) {
        long long mid = ((left / 2) + (right / 2));

        if ((left & 1) && (right & 1)) {
            mid++;
        }

        if (possible(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", ret);

    return 0;
}
