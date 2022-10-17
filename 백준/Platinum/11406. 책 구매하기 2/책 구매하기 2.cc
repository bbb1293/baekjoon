#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, m;
int s, t;
map<pair<int, int>, int> cap;
int p[250];
vector<int> edges[250];

int bfs() {
    memset(p, -1, sizeof(p));

    p[s] = -2;
    queue<pair<int, int> > q;
    q.push({s, INF});

    while (!q.empty()) {
        auto [cur, f] = q.front();
        q.pop();

        for (auto v : edges[cur]) {
            if (p[v] == -1 && cap[{cur, v}] != 0) {
                p[v] = cur;
                int next_f = min(f, cap[{cur, v}]);

                if (v == t) {
                    return next_f;
                }

                q.push({v, next_f});
            }
        }
    }

    return 0;
}

int get_maxflow() {
    int flow = 0, new_flow;

    while (new_flow = bfs()) {
        flow += new_flow;

        int cur = t;
        while (cur != s) {
            cap[{p[cur], cur}] -= new_flow;
            cap[{cur, p[cur]}] += new_flow;
            cur = p[cur];
        }
    }

    return flow;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    s = 0, t = n + m + 1;

    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);

        edges[0].push_back(i);
        edges[i].push_back(0);

        cap[{0, i}] = a;
        cap[{i, 0}] = 0;
    }

    for (int j = 1; j <= m; j++) {
        int b;
        scanf("%d", &b);

        edges[n + j].push_back(n + m + 1);
        edges[n + m + 1].push_back(n + j);

        cap[{n + j, n + m + 1}] = b;
        cap[{n + m + 1, n + j}] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int a;
            scanf("%d", &a);

            edges[n + i].push_back(j);
            edges[j].push_back(n + i);

            cap[{j, n + i}] = a;
            cap[{n + i, j}] = 0;
        }
    }

    printf("%d", get_maxflow());

    return 0;
}