#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e3;
int n, m, k;
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
int diag_y[] = {1, 1, -1, -1}, diag_x[] = {1, -1, -1, 1};
bool blocked[MAXN + 1][MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    scanf("%d", &k);

    while (k--) {
        int y, x, d;
        scanf("%d %d %d", &y, &x, &d);

        blocked[y][x] = true;

        y -= d;
        for (int dir = 0; dir < 4; dir++) {
            int tmp = d;
            while (tmp--) {
                y += diag_y[dir];
                x += diag_x[dir];

                if (y > 0 && x > 0 && y <= n && x <= m) {
                    blocked[y][x] = true;
                }
            }
        }
    }

    queue<pair<int, int> > q;
    q.push({1, 1});

    int cnt = 1;
    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            auto [y, x] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int next_y = y + dir_y[dir];
                int next_x = x + dir_x[dir];

                if (next_y == n && next_x == m) {
                    printf("YES\n%d", cnt);
                    return 0;
                }

                if (next_y == 0 || next_x == 0 ||
                    next_y > n || next_x > m ||
                    blocked[next_y][next_x]) {
                    continue;
                }

                blocked[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
        cnt++;
    }

    printf("NO");

    return 0;
}
