#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[10];
string dp[51];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    scanf("%d", &m);

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i - p[j] < 0) {
                continue;
            }

            string tmp(dp[i - p[j]]);
            tmp.push_back(j + '0');
            sort(tmp.begin(), tmp.end(), [](char a, char b) { return a > b; });

            if (tmp[0] == '0') {
                continue;
            }

            if (dp[i].length() < tmp.length()) {
                dp[i] = tmp;

            } else if (dp[i].length() == tmp.length()) {
                dp[i] = max(dp[i], tmp);
            }
        }
    }

    if (dp[m].empty()) {
        dp[m] = "0";
    }

    cout << dp[m];

    return 0;
}
