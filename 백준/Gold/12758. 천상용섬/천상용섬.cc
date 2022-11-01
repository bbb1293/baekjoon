#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n;
vector<int> dividor[2];
long long dp[2][1000];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);

            dividor[i & 1].clear();
            for (int j = 1; j * j <= num; j++) {
                if (!(num % j)) {
                    dividor[i & 1].push_back(j);

                    if (j != num / j) {
                        dividor[i & 1].push_back(num / j);
                    }
                }
            }
            sort(dividor[i & 1].begin(),
                 dividor[i & 1].end());

            if (i == 0) {
                for (int j = 0; j < dividor[i & 1].size();
                     j++) {
                    dp[i & 1][j] = 1;

                    if (j != 0) {
                        dp[i & 1][j] += dp[i & 1][j - 1];
                    }
                }
            } else {
                int prev_idx = (i & 1) ^ 1;
                for (int j = 0; j < dividor[i & 1].size();
                     j++) {
                    int left = 0,
                        right =
                            dividor[prev_idx].size() - 1;
                    int target;

                    while (left <= right) {
                        int mid = (left + right) / 2;

                        if (dividor[prev_idx][mid] <=
                            dividor[i & 1][j]) {
                            target = mid;
                            left = mid + 1;
                        } else {
                            right = mid - 1;
                        }
                    }

                    dp[i & 1][j] = dp[prev_idx][target];

                    if (j != 0) {
                        dp[i & 1][j] += dp[i & 1][j - 1];
                        dp[i & 1][j] %= MOD;
                    }
                }
            }
        }

        printf("%lld\n",
               dp[(n - 1) & 1]
                 [dividor[(n - 1) & 1].size() - 1]);
    }

    return 0;
}
