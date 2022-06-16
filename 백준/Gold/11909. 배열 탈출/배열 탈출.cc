#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2222;
int n;
int a[MAXN][MAXN];
int dir_x[] = {1, 0}, dir_y[] = {0, 1};
bool visited[MAXN][MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &a[y][x]);
        }
    }

    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        int cnt = pq.top().first;
        pair<int, int> cur = pq.top().second;

        pq.pop();

        if (visited[cur.first][cur.second]) {
            continue;
        }
        visited[cur.first][cur.second] = true;

        cnt = -cnt;
        if (cur.first == n - 1 && cur.second == n - 1) {
            printf("%d", cnt);
            return 0;
        }

        for (int dir = 0; dir < 2; dir++) {
            auto [new_y, new_x] =
                make_pair(cur.first + dir_y[dir], cur.second + dir_x[dir]);

            if (new_y == n || new_x == n || visited[new_y][new_x]) {
                continue;
            }

            if (a[cur.first][cur.second] > a[new_y][new_x]) {
                pq.push({-cnt, {new_y, new_x}});
            } else {
                pq.push(
                    {-(cnt + (a[new_y][new_x] - a[cur.first][cur.second] + 1)),
                     {new_y, new_x}});
            }
        }
    }

    return 0;
}
