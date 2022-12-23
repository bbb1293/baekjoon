#include <bits/stdc++.h>

using namespace std;

int n;
map<long long, long long> m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    long long ret = 0;
    while (n--) {
        long long x, t, c;
        scanf("%lld %lld %lld", &x, &t, &c);

        m[x - t] += c;
        ret = max(ret, m[x - t]);
    }

    printf("%lld", ret);

    return 0;
}