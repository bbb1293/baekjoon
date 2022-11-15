#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n;
int state[125][125], dist[125][125];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
bool used[125][125];

int main() {
    // freopen("input.txt", "r", stdin);

    int t = 1;
    while (true) {
        scanf("%d", &n);

        if (n == 0) {
            break;
        }

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                scanf("%d", &state[y][x]);
            }
        }

        memset(used, 0, sizeof(used));
        memset(dist, -1, sizeof(dist));
        dist[0][0] = state[0][0];

        priority_queue<pair<int, pair<int, int> > > pq;
        pq.push({-state[0][0], {0, 0}});

        while (!pq.empty()) {
            int cur_dist = -pq.top().first;
            auto [y, x] = pq.top().second;
            pq.pop();

            if (used[y][x]) {
                continue;
            }
            used[y][x] = true;

            for (int dir = 0; dir < 4; dir++) {
                int next_y = y + dir_y[dir];
                int next_x = x + dir_x[dir];

                if (next_y < 0 || next_x < 0 ||
                    next_y == n || next_x == n ||
                    used[next_y][next_x]) {
                    continue;
                }

                if (dist[next_y][next_x] == -1 ||
                    cur_dist + state[next_y][next_x] <
                        dist[next_y][next_x]) {
                    dist[next_y][next_x] =
                        cur_dist + state[next_y][next_x];
                    pq.push({-dist[next_y][next_x],
                             {next_y, next_x}});
                }
            }
        }

        printf("Problem %d: %d\n", t, dist[n - 1][n - 1]);
        t++;
    }

    return 0;
}