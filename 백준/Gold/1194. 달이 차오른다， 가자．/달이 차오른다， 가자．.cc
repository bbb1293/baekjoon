#include <bits/stdc++.h>

using namespace std;

int n, m;
char state[50][51];
int y_dir[] = {0, 1, 0, -1}, x_dir[] = {1, 0, -1, 0};
bool visited[50][50][(1 << 6)];
pair<int, int> start;
map<char, int> key = {{'a', 1}, {'b', 2},  {'c', 4},
                      {'d', 8}, {'e', 16}, {'f', 32}};
map<char, int> door = {{'A', 1}, {'B', 2},  {'C', 4},
                       {'D', 8}, {'E', 16}, {'F', 32}};

struct State {
    int y, x, cnt, k;
};

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);

        for (int x = 0; x < m; x++) {
            if (state[y][x] == '0') {
                start = {y, x};
            }
        }
    }

    queue<State> q;
    q.push({start.first, start.second, 0, 0});
    visited[start.first][start.second][0] = true;

    while (!q.empty()) {
        auto [y, x, cnt, k] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [next_y, next_x] = make_pair(y + y_dir[dir], x + x_dir[dir]);
            int next_k = k;

            if (next_y < 0 || next_x < 0 || next_y == n || next_x == m ||
                state[next_y][next_x] == '#') {
                continue;
            }

            if (state[next_y][next_x] == '1') {
                printf("%d", cnt + 1);
                return 0;
            }

            if (key.count(state[next_y][next_x])) {
                next_k |= key[state[next_y][next_x]];
            } else if (door.count(state[next_y][next_x])) {
                if (!(next_k & door[state[next_y][next_x]])) {
                    continue;
                }
            }

            if (visited[next_y][next_x][next_k]) {
                continue;
            }
            visited[next_y][next_x][next_k] = true;

            q.push({next_y, next_x, cnt + 1, next_k});
        }
    }

    printf("-1");

    return 0;
}
