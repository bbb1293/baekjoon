#include <bits/stdc++.h>

using namespace std;

const long long INF = 2147483647;
const int MAXN = 2e4;
int n;
long long a[MAXN], b[MAXN], c[MAXN];

bool odd(long long cur) {
    int ret = 0;

    for (int i = 0; i < n; i++) {
        long long cur_c = min(cur, c[i]) - a[i];

        if (cur_c >= 0) {
            if ((cur_c / b[i] + 1) & 1) {
                ret++;
            }

            ret %= 2;
        }
    }

    return ret & 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a[i], &c[i], &b[i]);
    }

    long long left = 1, right = INF;
    long long target = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (odd(mid)) {
            target = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (target == -1) {
        printf("NOTHING");
    } else {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (target <= c[i] && (target - a[i]) >= 0 &&
                !((target - a[i]) % b[i])) {
                cnt++;
            }
        }

        printf("%lld %d", target, cnt);
    }

    return 0;
}
