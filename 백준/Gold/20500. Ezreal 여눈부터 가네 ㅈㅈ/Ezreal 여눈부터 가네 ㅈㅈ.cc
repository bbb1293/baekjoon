#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n;
long long cnt[2][3];

int main() {
    // freopen("input.txt", "r", stdin);

    cnt[1][0] = 0;
    cnt[1][1] = 0;
    cnt[1][2] = 1;

    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        int prev_idx = ((i & 1) + 1) % 2;

        cnt[i & 1][0] = (cnt[prev_idx][2] + cnt[prev_idx][1]) % MOD;
        cnt[i & 1][1] = (cnt[prev_idx][0] + cnt[prev_idx][2]) % MOD;
        cnt[i & 1][2] = (cnt[prev_idx][0] + cnt[prev_idx][1]) % MOD;
    }

    printf("%d", cnt[n & 1][0]);

    return 0;
}
