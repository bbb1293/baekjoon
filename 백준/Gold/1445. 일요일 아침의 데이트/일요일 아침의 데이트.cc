#include <bits/stdc++.h>

using namespace std;

int n, m;
int dir_y[] = {1, 0, -1, 0}, dir_x[] = {0, 1, 0, -1};
pair<int, int> start_pos;
bool visited[50][50];
char state[50][51];

struct State {
    int trash, adj_trash, y, x;

    const bool operator<(const State &a) const {
        if (trash != a.trash) {
            return trash > a.trash;
        }

        if (adj_trash != a.adj_trash) {
            return adj_trash > a.adj_trash;
        }

        return true;
    }
};

bool is_adj_trash(int y, int x) {
    for (int dir = 0; dir < 4; dir++) {
        int new_y = y + dir_y[dir];
        int new_x = x + dir_x[dir];

        if (new_y < 0 || new_x < 0 || new_y == n ||
            new_x == m) {
            continue;
        }

        if (state[new_y][new_x] == 'g') {
            return true;
        }
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);
        for (int x = 0; x < m; x++) {
            if (state[y][x] == 'S') {
                start_pos = {y, x};
            }
        }
    }

    priority_queue<State> pq;
    pq.push({0, 0, start_pos.first, start_pos.second});

    while (!pq.empty()) {
        auto [trash, adj_trash, y, x] = pq.top();
        pq.pop();

        if (visited[y][x]) {
            continue;
        }
        visited[y][x] = true;

        for (int dir = 0; dir < 4; dir++) {
            int new_y = y + dir_y[dir];
            int new_x = x + dir_x[dir];

            if (new_y < 0 || new_x < 0 || new_y == n ||
                new_x == m) {
                continue;
            }

            if (state[new_y][new_x] == 'F') {
                printf("%d %d", trash, adj_trash);
                return 0;
            }

            int trash_add = 0, adj_trash_add = 0;
            if (state[new_y][new_x] == 'g') {
                trash_add++;
            } else if (is_adj_trash(new_y, new_x)) {
                adj_trash_add++;
            }

            pq.push({trash + trash_add,
                     adj_trash + adj_trash_add, new_y,
                     new_x});
        }
    }

    return 0;
}