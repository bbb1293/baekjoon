#include <bits/stdc++.h>

using namespace std;

struct state {
    int prev, cur;
};

int n, m;
int count_tree() {
    bool is_visited[n + 1] = {
        0,
    };
    vector<vector<int> > edges(n + 1, vector<int>());

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int cnt = 0;
    queue<state> q;
    for (int i = 1; i <= n; i++) {
        if (edges[i].size() == 0) {
            cnt += 1;
            continue;
        }

        if (!is_visited[i]) {
            q.push({0, i});
            is_visited[i] = true;

            bool is_tree = true;
            while (!q.empty()) {
                int prev = q.front().prev;
                int cur = q.front().cur;
                q.pop();

                for (auto next : edges[cur]) {
                    if (next == prev) {
                        continue;
                    }

                    if (is_visited[next]) {
                        is_tree = false;
                        continue;
                    }

                    is_visited[next] = true;
                    q.push({cur, next});
                }
            }

            cnt += is_tree;
        }
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);

    int tc = 1;
    while (true) {
        scanf("%d %d", &n, &m);

        if (!n) {
            break;
        }

        int cnt_tree = count_tree();

        printf("Case %d: ", tc);
        if (cnt_tree == 0) {
            printf("No trees.\n");
        } else if (cnt_tree == 1) {
            printf("There is one tree.\n");
        } else {
            printf("A forest of %d trees.\n", cnt_tree);
        }
        tc++;
    }

    return 0;
}