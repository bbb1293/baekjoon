#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3, INF = 987654321;
int n, p;
int num[MAXN + 1][MAXN + 1], dp[MAXN + 1][MAXN + 1];
vector<pair<int, int> > pos;

void set_dp(int y_start, int x_start, int y_end, int x_end) {
    for (int x = x_start + 1; x <= x_end; x++) {
        dp[y_start][x] = dp[y_start][x - 1] + num[y_start][x];
    }

    for (int y = y_start + 1; y <= y_end; y++) {
        dp[y][x_start] = dp[y - 1][x_start] + num[y][x_start];
    }

    for (int y = y_start + 1; y <= y_end; y++) {
        for (int x = x_start + 1; x <= x_end; x++) {
            dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]) + num[y][x];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            scanf("%d", &num[y][x]);
        }
    }

    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        int y, x;
        scanf("%d %d", &y, &x);
        pos.push_back({y, x});
    }

    sort(pos.begin(), pos.end());

    bool possible = true;
    for (int i = 1; i < p; i++) {
        if (pos[i - 1].second > pos[i].second) {
            possible = false;
            break;
        }
    }

    if (possible) {
        dp[1][1] = num[1][1];
        set_dp(1, 1, pos[0].first, pos[0].second);

        pos.push_back({n, n});
        for (int i = 1; i <= p; i++) {
            set_dp(pos[i - 1].first, pos[i - 1].second, pos[i].first,
                   pos[i].second);
        }

        printf("%d", dp[n][n]);
    } else {
        printf("-1");
    }

    return 0;
}
