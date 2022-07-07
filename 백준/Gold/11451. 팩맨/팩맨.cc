#include <bits/stdc++.h>

using namespace std;

struct State {
    string s;
    int x1, y1, x2, y2;
};

int n, m;
char grid[50][51];
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};
char dir_c[] = "ESWN";
bool visited[50][50][50][50];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        int start_x1 = -1, start_y1, start_x2, start_y2;
        for (int y = 0; y < n; y++) {
            cin >> grid[y];
            for (int x = 0; x < m; x++) {
                if (grid[y][x] == 'P') {
                    if (start_x1 == -1) {
                        start_x1 = x;
                        start_y1 = y;
                    } else {
                        start_x2 = x;
                        start_y2 = y;
                    }
                }
            }
        }

        memset(visited, 0, sizeof(visited));

        queue<State> q;
        q.push({"", start_x1, start_y1, start_x2, start_y2});
        visited[start_x1][start_y1][start_x2][start_y2] = true;

        string ret = "IMPOSSIBLE";

        while (!q.empty()) {
            auto [s, x1, y1, x2, y2] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                auto [next_x1, next_y1] = make_pair((x1 + dir_x[dir] + m) % m,
                                                    (y1 + dir_y[dir] + n) % n);
                auto [next_x2, next_y2] = make_pair((x2 + dir_x[dir] + m) % m,
                                                    (y2 + dir_y[dir] + n) % n);

                if (grid[next_y1][next_x1] == 'X') {
                    next_y1 = y1;
                    next_x1 = x1;
                } else if (grid[next_y1][next_x1] == 'G') {
                    continue;
                }

                if (grid[next_y2][next_x2] == 'X') {
                    next_y2 = y2;
                    next_x2 = x2;
                } else if (grid[next_y2][next_x2] == 'G') {
                    continue;
                }

                if (visited[next_x1][next_y1][next_x2][next_y2]) {
                    continue;
                }

                string next_s = s + dir_c[dir];

                if (next_x1 == next_x2 && next_y1 == next_y2) {
                    ret = next_s;
                    break;
                }

                visited[next_x1][next_y1][next_x2][next_y2] = true;
                q.push({next_s, next_x1, next_y1, next_x2, next_y2});
            }

            if(ret[0] != 'I') {
                break;
            }
        }

        if (ret[0]!='I') {
            cout << ret.length() << ' ';
        }
        cout << ret << '\n';
    }

    return 0;
}
