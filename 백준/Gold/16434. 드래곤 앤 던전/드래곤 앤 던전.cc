#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123456;
int n;
long long atk;
long long t[MAXN], a[MAXN], h[MAXN];

bool is_possible(long long max_h) {
    long long cur_h = max_h;
    long long cur_atk = atk;

    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            long long cnt = (h[i] + cur_atk - 1) / cur_atk;
            cur_h -= ((cnt - 1) * a[i]);

            if (cur_h <= 0) {
                return false;
            }

        } else {
            cur_atk += a[i];

            if (cur_h >= max_h - h[i]) {
                cur_h = max_h;
            } else {
                cur_h += h[i];
            }
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %lld", &n, &atk);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &t[i], &a[i], &h[i]);
    }

    long long left = 1, right = 9223372036854775800;
    long long ret = right;

    while (left <= right) {
        long long mid = left / 2 + right / 2;
        if ((left & 1) && (right & 1)) {
            mid++;
        }

        if (is_possible(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", ret);

    return 0;
}
