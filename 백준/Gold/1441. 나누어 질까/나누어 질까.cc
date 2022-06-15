#include <bits/stdc++.h>

using namespace std;

int n, l, r;
long long num[18];

long long get_gcd(long long a, long long b) {
    if (b < a) {
        return get_gcd(b, a);
    }

    if (a == 0) {
        return b;
    }

    return get_gcd(b % a, a);
}

long long count(int cnt, int cur, long long cur_num) {
    if (cnt == 0) {
        return (r / cur_num) - ((l - 1) / cur_num);
    }

    if (cur == n) {
        return 0;
    }

    long long ret = 0;
    for (int i = cur; i < n; i++) {
        long long gcd = get_gcd(cur_num, num[i]);
        long long next_num = cur_num / gcd * num[i];

        if (next_num <= r) {
            ret += count(cnt - 1, i + 1, next_num);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            ret += count(i, 0, 1);
        } else {
            ret -= count(i, 0, 1);
        }
    }

    printf("%lld", ret);

    return 0;
}
