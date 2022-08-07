#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[50][50], visited[50][50];
int x_dir[] = {1, 0, -1, 0}, y_dir[] = {0, 1, 0, -1};
vector<pair<int, int> > bac;

int put_bac(int state) {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int> > q;

    for (int i = 0; i < bac.size(); i++) {
        if (state & (1 << i)) {
            q.push({bac[i].first, bac[i].second});
            visited[bac[i].first][bac[i].second] = true;
        }
    }

    int cnt = -1;
    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            auto [y, x] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                auto [next_y, next_x] =
                    make_pair(y + y_dir[dir], x + x_dir[dir]);

                if (next_y < 0 || next_x < 0 || next_y == n || next_x == n ||
                    visited[next_y][next_x] || grid[next_y][next_x] == 1) {
                    continue;
                }

                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
        cnt++;
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (!visited[y][x] && grid[y][x] != 1) {
                return 987654321;
            }
        }
    }

    return cnt;
}

int solve(int state, int cur, int cnt) {
    if (cnt == m) {
        return put_bac(state);
    }

    int ret = 987654321;
    for (int i = cur; i < bac.size(); i++) {
        if (!(state & (1 << i))) {
            ret = min(ret, solve(state | (1 << i), i + 1, cnt + 1));
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &grid[y][x]);

            if (grid[y][x] == 2) {
                bac.push_back({y, x});
            }
        }
    }

    int ret = solve(0, 0, 0);
    if (ret == 987654321) {
        ret = -1;
    }

    printf("%d", ret);

    return 0;
}
