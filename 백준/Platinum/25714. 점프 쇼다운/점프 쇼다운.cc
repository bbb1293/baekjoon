#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n;
long long comb[300][300], p2[300];

void init() {
    comb[0][0] = 1;
    for (int i = 1; i < 300; i++) {
        comb[i][0] = comb[i][i] = 1;

        for (int j = 1; j < i; j++) {
            comb[i][j] =
                (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    p2[0] = p2[1] = 1;
    for (int i = 2; i < 300; i++) {
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    init();

    scanf("%d", &n);

    long long ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int a = (j - i - 1);
                int b = (k - j - 1);
                int c = (i + (n - 1) - k);

                long long tmp = (p2[a] * p2[b]) % MOD;
                tmp *= p2[c];
                tmp %= MOD;

                tmp *= comb[a + b + c][a];
                tmp %= MOD;

                tmp *= comb[b + c][b];
                tmp %= MOD;

                ret += tmp;
                ret %= MOD;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}