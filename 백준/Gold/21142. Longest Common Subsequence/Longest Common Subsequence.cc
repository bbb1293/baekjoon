#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, k;
int dp[26], pos[MAXN][26];
char first[27], tmp[27];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);

        for (int j = 0; j < k; j++) {
            pos[i][tmp[j] - 'A'] = j;

            if (i == 0) {
                first[j] = tmp[j];
            }
        }
    }

    int ret = 1;
    for (int i = 0; i < k; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            bool possible = true;

            for (int l = 1; l < n; l++) {
                if (pos[l][first[j] - 'A'] >
                    pos[l][first[i] - 'A']) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ret = max(ret, dp[i]);
    }

    printf("%d", ret);

    return 0;
}