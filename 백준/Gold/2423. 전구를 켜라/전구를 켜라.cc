#include <bits/stdc++.h>

using namespace std;

int n, m;
int dir_x[] = {1, 1, -1, -1}, dir_y[] = {-1, 1, 1, -1};
bool connected[300000][4], visited[300000];

pair<int, int> convert(int num) {
    return make_pair(num / (m + 1), num % (m + 1));
}

int convert(pair<int, int> p) { return p.first * (m + 1) + p.second; }

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    char tmp[501];
    for (int y = 0; y < n; y++) {
        scanf("%s", tmp);
        for (int x = 0; x < m; x++) {
            if (tmp[x] == '/') {
                connected[convert({y + 1, x})][0] = true;
                connected[convert({y, x + 1})][2] = true;
            } else {
                connected[convert({y, x})][1] = true;
                connected[convert({y + 1, x + 1})][3] = true;
            }
        }
    }

    priority_queue<pair<int, int> > pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [cnt, cur] = pq.top();
        pq.pop();

        if (visited[cur]) {
            continue;
        }

        visited[cur] = true;

        cnt = -cnt;

        if (cur == (m + 1) * n + m) {
            printf("%d", cnt);
            return 0;
        }

        pair<int, int> cur_p = convert(cur);

        for (int dir = 0; dir < 4; dir++) {
            auto [new_y, new_x] =
                make_pair(cur_p.first + dir_y[dir], cur_p.second + dir_x[dir]);
            int new_num = convert({new_y, new_x});

            if (new_y < 0 || new_x < 0 || new_y > n || new_x > m ||
                visited[new_num]) {
                continue;
            }

            if (connected[cur][dir]) {
                pq.push({-cnt, new_num});
            } else {
                pq.push({-(cnt + 1), new_num});
            }
        }
    }

    printf("NO SOLUTION");

    return 0;
}
