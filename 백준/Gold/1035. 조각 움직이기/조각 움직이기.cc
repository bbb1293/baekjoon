#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int x_dir[] = {1, 0, -1, 0}, y_dir[] = {0, 1, 0, -1};
int pos_size;
char state[6];
vector<pair<int, int> > pos;

bool connected(vector<pair<int, int> > &tmp) {
    bool visited[5] = {
        0,
    };
    visited[0] = true;

    queue<pair<int, int> > q;
    q.push(tmp[0]);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            pair<int, int> next = {cur.first + y_dir[dir],
                                   cur.second + x_dir[dir]};

            for (int i = 1; i < pos_size; i++) {
                if (!visited[i] && (tmp[i] == next)) {
                    visited[i] = true;
                    q.push(next);
                }
            }
        }
    }

    for (int i = 1; i < pos_size; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int get_cnt(vector<pair<int, int> > &tmp) {
    int cnt = 0;
    for (int i = 0; i < pos_size; i++) {
        cnt += (abs(tmp[i].first - pos[i].first) +
                abs(tmp[i].second - pos[i].second));
    }

    return cnt;
}

int min_cnt(vector<pair<int, int> > &tmp) {
    if (tmp.size() == pos_size) {
        for (int i = 0; i < pos_size; i++) {
            for (int j = i + 1; j < pos_size; j++) {
                if (tmp[i] == tmp[j]) {
                    return INF;
                }
            }
        }

        if (connected(tmp)) {
            return get_cnt(tmp);
        }

        return INF;
    } else {
        int ret = INF;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                tmp.push_back({y, x});

                ret = min(ret, min_cnt(tmp));

                tmp.pop_back();
            }
        }
        return ret;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    for (int y = 0; y < 5; y++) {
        scanf("%s", state);

        for (int x = 0; x < 5; x++) {
            if (state[x] == '*') {
                pos.push_back({y, x});
            }
        }
    }

    pos_size = pos.size();

    vector<pair<int, int> > tmp;
    int ret = min_cnt(tmp);
    printf("%d", ret);

    return 0;
}
