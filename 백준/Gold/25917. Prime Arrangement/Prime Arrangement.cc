#include <bits/stdc++.h>

using namespace std;

const long long MOD = 998244353;
int r, c;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &r, &c);

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            int tmp;
            scanf("%d", &tmp);
        }
    }

    for (int i = 0; i < r; i++) {
        int tmp;
        scanf("%d", &tmp);
    }

    long long ret = 1;
    for (int i = r + 1; i <= r * c; i++) {
        ret *= i;
        ret %= MOD;
    }

    printf("%lld", ret);

    return 0;
}