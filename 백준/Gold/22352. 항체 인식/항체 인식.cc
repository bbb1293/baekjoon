#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[30][30], b[30][30];
int dir_y[] = {1, 0, -1, 0}, dir_x[] = {0, 1, 0, -1};
bool visited[30][30];

int get_type(int y, int x) {
    queue<pair<int, int> > q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [next_y, next_x] = make_pair(y + dir_y[dir], x + dir_x[dir]);

            if (next_y < 0 || next_x < 0 || next_y == n || next_x == m ||
                visited[next_y][next_x] || a[next_y][next_x] != a[y][x]) {
                continue;
            }

            if (b[y][x] != b[next_y][next_x]) {
                return -1;
            }

            q.push({next_y, next_x});
            visited[next_y][next_x] = true;
        }
    }

    if (b[y][x] == a[y][x]) {
        return 0;
    }
    return 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &a[y][x]);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &b[y][x]);
        }
    }

    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (!visited[y][x]) {
                int type = get_type(y, x);

                if (type == -1) {
                    printf("NO");
                    return 0;
                }

                cnt += type;
            }
        }
    }

    if (cnt < 2) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
