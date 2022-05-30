#include <bits/stdc++.h>

using namespace std;

long long n, k, c;
int a[10];

long long get_num(long long t, int cnt) {
    if (cnt == c) {
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            ret += (t / a[i]);
        }

        return ret;

    } else {
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 1) {
                a[i]--;
                ret = max(ret, get_num(t, cnt + 1));
                a[i]++;
            }
        }

        ret = max(ret, get_num(t, cnt + 1));

        return ret;
    }
}

bool is_possible(long long t) {
    long long ret = get_num(t, 0);

    return ret >= k;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld", &n, &k, &c);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long left = 1, right = 1e12;
    long long target = right;
    while (left <= right) {
        long long mid = (left + right) / 2;

        if (is_possible(mid)) {
            target = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", target);

    return 0;
}
