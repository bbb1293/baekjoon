#include <bits/stdc++.h>

using namespace std;

struct State {
    int y, x, s;

    const bool operator<(const State &a) const { return s > a.s; }
};

int n, m, k;
int s[1000][1000];
int y_dir[] = {1, 0, -1, 0}, x_dir[] = {0, 1, 0, -1};
bool in[1000][1000];
priority_queue<State> pq;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &s[y][x]);

            if (y == 0 || x == 0 || x == m - 1) {
                pq.push({y, x, s[y][x]});
                in[y][x] = true;
            }
        }
    }

    int cnt = 0, ret = 0;
    while (cnt < k) {
        auto [y, x, cur_s] = pq.top();
        pq.pop();

        cnt++;
        ret = max(ret, cur_s);

        for (int dir = 0; dir < 4; dir++) {
            auto [next_y, next_x] = make_pair(y + y_dir[dir], x + x_dir[dir]);

            if (next_y < 0 || next_x < 0 || next_y == n || next_x == m ||
                in[next_y][next_x]) {
                continue;
            }

            pq.push({next_y, next_x, s[next_y][next_x]});
            in[next_y][next_x] = true;
        }
    }

    printf("%d", ret);
    return 0;
}
