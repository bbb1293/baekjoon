#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> line[50];
int dp[102][102];

int get_dp(int from, int to) {
    int &ret = dp[from][to];

    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (auto [l, r] : line) {
        if (l < from || to < r) {
            continue;
        }
        ret = max(ret, get_dp(from, l - 1) + get_dp(l + 1, r - 1) +
                           get_dp(r + 1, to) + 1);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    memset(dp, -1, sizeof(dp));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &line[i].first, &line[i].second);

        if (line[i].second < line[i].first) {
            swap(line[i].first, line[i].second);
        }
    }

    printf("%d", get_dp(1, 100));

    return 0;
}
