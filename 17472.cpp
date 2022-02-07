#include <bits/stdc++.h>

using namespace std;

struct xy {
    int x, y;
};

struct edge {
    int c, a, b;
};

bool operator<(edge a, edge b) { return a.c > b.c; }

int n, m;
int island_num = 0;
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};
int state[10][10];
int parent[7];
bool is_visited[10][10];

void init_parent() {
    for (int i = 1; i <= island_num; i++) {
        parent[i] = i;
    }
}

void set_parent(int root, int root_parent) { parent[root] = root_parent; }

int get_parent(int a) {
    if (a == parent[a]) {
        return a;
    }
    return parent[a] = get_parent(parent[a]);
}

bool is_valid(int x, int y) {
    return (0 <= x) && (0 <= y) && (x < m) && (y < n);
}

void set_set(int x, int y) {
    island_num++;

    queue<xy> q;
    q.push({x, y});
    is_visited[y][x] = true;
    state[y][x] = island_num;

    while (!q.empty()) {
        xy cur_xy = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int new_x = cur_xy.x + dir_x[dir];
            int new_y = cur_xy.y + dir_y[dir];

            if (is_valid(new_x, new_y) && (!is_visited[new_y][new_x]) &&
                (state[new_y][new_x])) {
                state[new_y][new_x] = island_num;
                is_visited[new_y][new_x] = true;
                q.push({new_x, new_y});
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (state[y][x] && !is_visited[y][x]) {
                set_set(x, y);
            }
        }
    }

    priority_queue<edge> pq;

    for (int y = 0; y < n; y++) {
        int prev = 0, dist = 0;
        for (int x = 0; x < m; x++) {
            if (state[y][x]) {
                if (!prev) {
                    prev = state[y][x];
                    dist = 0;
                } else if (prev != state[y][x]) {
                    if (dist > 1) {
                        pq.push({dist, prev, state[y][x]});
                    }
                    prev = state[y][x];
                    dist = 0;
                } else {
                    dist = 0;
                }
            } else {
                dist++;
            }
        }
    }

    for (int x = 0; x < m; x++) {
        int prev = 0, dist = 0;
        for (int y = 0; y < n; y++) {
            if (state[y][x]) {
                if (!prev) {
                    prev = state[y][x];
                    dist = 0;
                } else if (prev != state[y][x]) {
                    if (dist > 1) {
                        pq.push({dist, prev, state[y][x]});
                    }
                    prev = state[y][x];
                    dist = 0;
                } else {
                    dist = 0;
                }
            } else {
                dist++;
            }
        }
    }

    int cnt = 0, ret = 0;
    init_parent();
    while ((cnt != (island_num - 1)) && (!pq.empty())) {
        edge e = pq.top();
        pq.pop();

        int a_parent = get_parent(e.a);
        int b_parent = get_parent(e.b);

        if (a_parent != b_parent) {
            set_parent(a_parent, b_parent);
            cnt++;
            ret += e.c;
        }
    }

    if (cnt != island_num - 1) {
        printf("-1");
    } else {
        printf("%d", ret);
    }

    return 0;
}