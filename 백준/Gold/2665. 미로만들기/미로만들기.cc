#include <bits/stdc++.h>

using namespace std;

int n;
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
char state[50][51];
bool visited[50][50];
deque<pair<int, pair<int, int> > > dq;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);
    }

    dq.push_front({0, {0, 0}});
    visited[0][0] = true;

    while (!dq.empty()) {
        int cur_dist = dq.front().first;
        auto [y, x] = dq.front().second;
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++) {
            int next_y = y + dir_y[dir];
            int next_x = x + dir_x[dir];

            if (next_y < 0 || next_x < 0 || next_y == n ||
                next_x == n || visited[next_y][next_x]) {
                continue;
            }

            if (next_y == n - 1 && next_x == n - 1) {
                printf("%d", cur_dist);
                return 0;
            }

            visited[next_y][next_x] = true;

            if (state[next_y][next_x] == '0') {
                dq.push_back(
                    {cur_dist + 1, {next_y, next_x}});
            } else {
                dq.push_front({cur_dist, {next_y, next_x}});
            }
        }
    }

    return 0;
}