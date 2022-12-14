#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n;
pair<int, int> pd[MAXN];
int dp[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pd[i].first, &pd[i].second);
    }

    sort(pd, pd + n,
         [](pair<int, int> &a, pair<int, int> &b) {
             return a.second < b.second;
         });

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = pd[i].second; j > 0; j--) {
            dp[j] = max(dp[j], dp[j - 1] + pd[i].first);
            ret = max(ret, dp[j]);
        }
    }

    printf("%d", ret);

    return 0;
}