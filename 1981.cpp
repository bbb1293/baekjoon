#include <bits/stdc++.h>

using namespace std;

int n;
int state[100][100];
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};
bool is_visited[100][100];

bool is_valid(int x, int y) {
    return (0 <= x) && (0 <= y) && (x < n) && (y < n);
}

bool in_between(int target, int left, int right) {
    return (left <= target) && (target <= right);
}

bool is_possible(int diff) {
    for (int min_val = 0; min_val <= 200 - diff; min_val++) {
        memset(is_visited, 0, sizeof(is_visited));

        int max_val = min_val + diff;

        if (!in_between(state[0][0], min_val, max_val) ||
            !in_between(state[n - 1][n - 1], min_val, max_val)) {
            continue;
        }

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (!in_between(state[y][x], min_val, max_val)) {
                    is_visited[y][x] = true;
                }
            }
        }

        queue<pair<int, int> > q;
        q.push({0, 0});
        is_visited[0][0] = true;

        while (!q.empty()) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int new_x = cur_x + dir_x[dir];
                int new_y = cur_y + dir_y[dir];

                if ((new_x == (n - 1)) && (new_y == (n - 1))) {
                    return true;
                }

                if (is_valid(new_x, new_y) && !is_visited[new_y][new_x]) {
                    is_visited[new_y][new_x] = true;
                    q.push({new_x, new_y});
                }
            }
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &state[y][x]);
        }
    }

    int left = 0, right = 200, ret = 200;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ret);

    return 0;
}