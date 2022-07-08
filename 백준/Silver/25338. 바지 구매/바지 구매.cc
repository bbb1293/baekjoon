#include <bits/stdc++.h>

using namespace std;

int n;
long long a, b, c, d;

long long f(int x) {
    long long ret = x - b;
    ret *= ret;
    ret *= a;

    return max(ret + c, d);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    scanf("%d", &n);

    int cnt = 0;
    while (n--) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (f(v) == u) {
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}
