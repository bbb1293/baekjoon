#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[100][100];
int x_dir[] = {0, 1, 0, -1}, y_dir[] = {1, 0, -1, 0};
int visited[100][100];

void set_visited(pair<int, int> start, int level, int color) {
    queue<pair<int, int> > q;
    q.push(start);

    visited[start.first][start.second] = color;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [next_y, next_x] = make_pair(y + y_dir[dir], x + x_dir[dir]);

            if (next_y < 0 || next_x < 0 || next_y == n || next_x == m ||
                visited[next_y][next_x] == color ||
                grid[next_y][next_x] > level) {
                continue;
            }

            visited[next_y][next_x] = color;
            q.push({next_y, next_x});
        }
    }
}

bool possible(int level) {
    memset(visited, 0, sizeof(visited));

    set_visited({0, 0}, level, 1);
    set_visited({n - 1, m - 1}, level, 2);

    if (visited[0][0] == 2) {
        return true;
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (visited[y][x] == 1) {
                for (int dir = 0; dir < 4; dir++) {
                    auto [next_y, next_x] =
                        make_pair(y + 2 * y_dir[dir], x + 2 * x_dir[dir]);

                    if (next_y < 0 || next_x < 0 || next_y >= n ||
                        next_x >= m) {
                        continue;
                    }

                    if (visited[next_y][next_x] == 2) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &grid[y][x]);
        }
    }

    int left = max(grid[0][0], grid[n - 1][m - 1]), right = 1e9;
    int target = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (possible(mid)) {
            target = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", target);

    return 0;
}
