#include <bits/stdc++.h>

using namespace std;

int n, m, p;
int dps[26], move_cnt[26], hp;
int dir_x[] = {1, 0, -1, 0}, dir_y[] = {0, 1, 0, -1};
char state[1000][1001];
bool visited[1000][1000];

void set_player(int y, int x) {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, pair<int, int> > > q;
    q.push({0, {y, x}});

    int player = state[y][x] - 'a';
    visited[y][x] = true;

    while (!q.empty()) {
        int cnt = q.front().first;
        auto [cur_y, cur_x] = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            auto [next_y, next_x] =
                make_pair(cur_y + dir_y[dir], cur_x + dir_x[dir]);

            if (next_y < 0 || next_x < 0 || next_y == n || next_x == m ||
                visited[next_y][next_x] || state[next_y][next_x] == 'X') {
                continue;
            }

            if (state[next_y][next_x] == 'B') {
                move_cnt[player] = cnt + 1;
                return;
            }

            q.push({cnt + 1, {next_y, next_x}});
            visited[next_y][next_x] = true;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &p);

    for (int y = 0; y < n; y++) {
        scanf("%s", state[y]);
    }

    for (int i = 0; i < p; i++) {
        char player;
        scanf(" %c", &player);
        scanf("%d", &dps[player - 'a']);
    }

    scanf("%d", &hp);

    memset(move_cnt, -1, sizeof(move_cnt));
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if ('a' <= state[y][x] && state[y][x] <= 'z') {
                set_player(y, x);
            }
        }
    }

    int ret = 0;
    while (hp > 0) {
        for (int i = 0; i < 26; i++) {
            move_cnt[i]--;

            if (move_cnt[i] < 0) {
                if (move_cnt[i] == -1) {
                    ret++;
                }
                hp -= dps[i];
            }
        }
    }

    printf("%d", ret);

    return 0;
}
