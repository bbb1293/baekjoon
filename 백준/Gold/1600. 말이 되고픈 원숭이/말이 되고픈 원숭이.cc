#include <bits/stdc++.h>

using namespace std;

struct State {
    int y, x, rest, cnt;
};

int k, w, h;
int state[200][200];
bool visited[200][200][31];
int dir_y[] = {0, 1, 0, -1}, dir_x[] = {1, 0, -1, 0};
int diag_y[] = {-2, -1, 1, 2, 2, 1, -1, -2},
    diag_x[] = {1, 2, 2, 1, -1, -2, -2, -1};

int solve() {
    queue<State> q;
    q.push({0, 0, k, 0});

    while (!q.empty()) {
        auto [y, x, rest, cnt] = q.front();
        q.pop();

        if (y == h - 1 && x == w - 1) {
            return cnt;
        }

        for (int dir = 0; dir < 4; dir++) {
            int new_y = y + dir_y[dir];
            int new_x = x + dir_x[dir];

            if (new_y < 0 || new_x < 0 || new_y >= h ||
                new_x >= w || state[new_y][new_x] == 1 ||
                visited[new_y][new_x][rest]) {
                continue;
            }

            q.push({new_y, new_x, rest, cnt + 1});
            visited[new_y][new_x][rest] = true;
        }

        if (rest) {
            for (int dir = 0; dir < 8; dir++) {
                int new_y = y + diag_y[dir];
                int new_x = x + diag_x[dir];

                if (new_y < 0 || new_x < 0 || new_y >= h ||
                    new_x >= w ||
                    state[new_y][new_x] == 1 ||
                    visited[new_y][new_x][rest - 1]) {
                    continue;
                }

                q.push({new_y, new_x, rest - 1, cnt + 1});
                visited[new_y][new_x][rest - 1] = true;
            }
        }
    }

    return -1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &k);
    scanf("%d %d", &w, &h);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    printf("%d", solve());

    return 0;
}