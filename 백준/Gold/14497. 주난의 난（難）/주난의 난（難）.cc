#include <bits/stdc++.h>

using namespace std;

int n, m;
int start_x, start_y, end_x, end_y;
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
char state[300][301];
bool visited[300][300];
queue<pair<int, int> > q[2];

void bfs(int idx) {
    int next_idx = (idx ^ 1);

    while (!q[idx].empty()) {
        auto [y, x] = q[idx].front();
        q[idx].pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [next_y, next_x] =
                make_pair(y + dir_y[dir], x + dir_x[dir]);

            if (next_y < 0 || next_x < 0 || next_y == n ||
                next_x == m || visited[next_y][next_x]) {
                continue;
            }
            visited[next_y][next_x] = true;

            if (state[next_y][next_x] == '1') {
                q[next_idx].push({next_y, next_x});
                continue;
            }
            q[idx].push({next_y, next_x});
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &start_y, &start_x, &end_y,
          &end_x);
    start_x--;
    start_y--;
    end_x--;
    end_y--;

    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);
    }

    q[1].push({start_y, start_x});

    int cnt = 0;
    while (!visited[end_y][end_x]) {
        cnt++;

        bfs(cnt & 1);
    }

    printf("%d", cnt);

    return 0;
}