#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b;
bool obstacle[501][501], visited[501][501];
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};

struct State {
    int cnt, y, x;
};

int main() {
    // freopen("input.txt", "r", stdin);

    int k;
    scanf("%d %d %d %d %d", &n, &m, &a, &b, &k);

    while (k--) {
        int y, x;
        scanf("%d %d", &y, &x);
        obstacle[y][x] = true;
    }

    for (int y = 1; y + a <= n + 1; y++) {
        for (int x = 1; x + b <= m + 1; x++) {
            bool cur = false;
            for (int yy = 0; yy < a && !cur; yy++) {
                for (int xx = 0; xx < b; xx++) {
                    if (obstacle[y + yy][x + xx]) {
                        cur = true;
                        break;
                    }
                }
            }
            visited[y][x] = cur;
        }
    }

    pair<int, int> start, end;
    scanf("%d %d", &start.first, &start.second);
    scanf("%d %d", &end.first, &end.second);

    queue<State> q;
    q.push({0, start.first, start.second});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [cnt, y, x] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [new_y, new_x] = make_pair(y + dir_y[dir], x + dir_x[dir]);

            if (new_y < 1 || new_x < 1 || new_y + a > n + 1 ||
                new_x + b > m + 1 || visited[new_y][new_x]) {
                continue;
            }

            if (make_pair(new_y, new_x) == end) {
                printf("%d", cnt + 1);
                return 0;
            }

            visited[new_y][new_x] = true;
            q.push({cnt + 1, new_y, new_x});
        }
    }

    printf("-1");

    return 0;
}
