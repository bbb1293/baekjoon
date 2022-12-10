#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
const long long MOD = 1e9 + 7;
int n;
char s[MAXN + 1];

long long get_power(int a, int k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return a;
    }

    long long tmp = get_power(a, k / 2);

    if (k & 1) {
        return (((tmp * tmp) % MOD) * a) % MOD;
    }

    return ((tmp * tmp) % MOD);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%s", &s);

    long long ret = 0;
    long long o = 0, c = 0, k = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'K') {
            k++;
        } else if (s[i] == 'C') {
            c += k;
            c %= MOD;
        } else if (s[i] == 'O') {
            o += c;
            o %= MOD;
        } else if (s[i] == 'R') {
            ret += (get_power(2, i) * o);
            ret %= MOD;
        }
    }

    printf("%lld", ret);

    return 0;
}