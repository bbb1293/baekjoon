#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5, MAXM = 1e4;
string s, tmp[500];
int n;
int pi[500][MAXM], dp[MAXN + 1], len[500], js[500];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int s_len = s.length();

    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> tmp[k];

        len[k] = tmp[k].length();

        for (int i = 1, j = 0; i < len[k]; i++) {
            while (j && tmp[k][i] != tmp[k][j]) {
                j = pi[k][j - 1];
            }

            if (tmp[k][i] == tmp[k][j]) {
                j++;
            }

            pi[k][i] = j;
        }
    }

    for (int k = 0; k < s_len; k++) {
        dp[k + 1] = dp[k];

        for (int i = 0; i < n; i++) {
            int j = js[i];

            while (j && tmp[i][j] != s[k]) {
                j = pi[i][j - 1];
            }

            if (tmp[i][j] == s[k]) {
                j++;
            }

            if (j == len[i]) {
                dp[k + 1] = max(dp[k + 1], dp[k + 1 - len[i]] + len[i]);
                j = pi[i][j - 1];
            }

            js[i] = j;
        }
    }

    printf("%d", dp[s_len]);

    return 0;
}
