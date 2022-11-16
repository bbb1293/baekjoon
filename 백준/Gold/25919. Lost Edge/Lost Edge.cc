#include <bits/stdc++.h>

using namespace std;

struct Info {
    int level, y, x;

    const bool operator<(const Info &a) const {
        return level > a.level;
    }
};

const int INF = 1e5;
int n, m;
int l, e, k;
int a[100][100];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
bool visited[100][100];
priority_queue<Info> q;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &l, &e, &k);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &a[y][x]);

            if (a[y][x] == -3) {
                q.push({0, y, x});
            } else if (a[y][x] == -2) {
                a[y][x] = INF;
            }
        }
    }

    visited[q.top().y][q.top().x] = true;

    while (!q.empty()) {
        auto [level, y, x] = q.top();
        q.pop();

        if (level == INF) {
            if (l >= k) {
                printf("O");
            } else {
                printf("X");
            }
            return 0;
        }

        if (level < l) {
            e += level;

            while (e >= l) {
                e -= l;
                l++;
            }

            for (int dir = 0; dir < 4; dir++) {
                int next_y = y + dir_y[dir];
                int next_x = x + dir_x[dir];

                if (next_y < 0 || next_x < 0 ||
                    next_y == n || next_x == m ||
                    visited[next_y][next_x] ||
                    a[next_y][next_x] == -1) {
                    continue;
                }

                visited[next_y][next_x] = true;
                q.push({a[next_y][next_x], next_y, next_x});
            }
        }
    }

    printf("X");

    return 0;
}