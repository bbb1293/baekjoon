#include <bits/stdc++.h>

using namespace std;

struct State {
    int x, y, dir, times;
};

struct compare {
    bool operator()(State &a, State &b) { return a.times > b.times; }
};

int w, h;
int start_dest[2][2];
char square[100][100];
bool is_visited[100][100][4];
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};

bool is_valid(int x, int y, int dir) {
    return (0 <= x) && (0 <= y) && (x < w) && (y < h) &&
           (square[y][x] != '*') && (!is_visited[y][x][dir]);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d", &w, &h);

    int idx = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            scanf(" %c", &square[y][x]);
            if (square[y][x] == 'C') {
                start_dest[idx][0] = x;
                start_dest[idx++][1] = y;
            }
        }
    }

    priority_queue<State, vector<State>, compare> pq;
    for (int dir = 0; dir < 4; dir++) {
        int new_x = start_dest[0][0] + dir_x[dir];
        int new_y = start_dest[0][1] + dir_y[dir];

        if (is_valid(new_x, new_y, dir)) {
            pq.push({new_x, new_y, dir, 0});
        }
        is_visited[start_dest[0][1]][start_dest[0][0]][dir] = true;
    }

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        if ((cur.x == start_dest[1][0]) && (cur.y == start_dest[1][1])) {
            printf("%d\n", cur.times);
            return 0;
        }

        if (is_visited[cur.y][cur.x][cur.dir]) {
            continue;
        }

        is_visited[cur.y][cur.x][cur.dir] = true;

        for (int i = -1; i <= 1; i++) {
            int new_dir = (cur.dir + i + 4) % 4;
            int new_x = cur.x + dir_x[new_dir];
            int new_y = cur.y + dir_y[new_dir];

            if (is_valid(new_x, new_y, new_dir)) {
                pq.push({new_x, new_y, new_dir, cur.times + abs(i)});
            }
        }
    }

    return 0;
}