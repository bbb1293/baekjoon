#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4;
int n;
int a[MAXN + 1];
bool used[MAXN + 1];

long long get_gcd(long long a, long long b) {
    if (b < a) {
        return get_gcd(b, a);
    }

    while (a != 0) {
        b %= a;
        swap(a, b);
    }

    return b;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    long long ret = 1;

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;

            int cnt = 1, cur = i;
            while (!used[a[cur]]) {
                cur = a[cur];
                used[cur] = true;
                cnt++;
            }

            ret /= get_gcd(ret, cnt);
            ret *= cnt;
        }
    }

    printf("%lld", ret);

    return 0;
}
