#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5;
int n;
long long a[MAXN], b[MAXN];

long long get_gcd(long long a, long long b) {
    if (b < a) {
        swap(a, b);
    }

    while (a != 0) {
        long long c = a;
        a = b % a;
        b = c;
    }

    return b;
}

bool possible(long long k) {
    long long from = 1, to = 3037000499;

    while (from <= to) {
        long long mid = (from + to) / 2;
        long long mid_2 = mid * mid;

        if (k == mid_2) {
            return true;
        } else if (k < mid_2) {
            to = mid - 1;
        } else {
            from = mid + 1;
        }
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }

    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        }

        long long gcd = get_gcd(a[i], b[i]);

        a[i] /= gcd;
        b[i] /= gcd;

        if (!possible(a[i]) || !possible(b[i])) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");

    return 0;
}