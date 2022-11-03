#include <bits/stdc++.h>

using namespace std;

const int MAXK = 1e5;
const long long MOD = 1e9 + 7;
int n, k;
long long dp[10][MAXK + 1];
vector<int> dividor[MAXK + 1];

void set_dividor() {
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (!(i % j)) {
                dividor[i].push_back(j);

                if (j != i / j) {
                    dividor[i].push_back(i / j);
                }
            }
        }
    }
}

void set_dp() {
    for (int i = 1; i <= k; i++) {
        dp[n - 1][i] = 1;
    }

    long long sum = k, next_sum = 0;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = (sum + dp[i + 1][j]) % MOD;

            for (auto d : dividor[j]) {
                dp[i][j] =
                    (dp[i][j] - dp[i + 1][d] + MOD) % MOD;
            }
            next_sum = (next_sum + dp[i][j]) % MOD;
        }

        sum = next_sum;
        next_sum = 0;
    }

    printf("%lld", sum);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    set_dividor();
    set_dp();

    return 0;
}