#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, l;
int s, e;
vector<pair<int, int> > edges[MAXN + 1];
bool visited[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &l);

    while (l--) {
        int u, v;
        scanf("%d", &u);

        while (true) {
            scanf("%d", &v);

            if (v == -1) {
                break;
            }

            edges[u].push_back({v, l});
            edges[v].push_back({u, l});

            u = v;
        }
    }

    scanf("%d %d", &s, &e);

    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push({0, {s, -1}});

    while (!pq.empty()) {
        int cnt = pq.top().first;
        auto [cur, label] = pq.top().second;
        pq.pop();

        if (visited[cur]) {
            continue;
        }

        visited[cur] = true;
        cnt = -cnt;

        if (cur == e) {
            printf("%d", cnt);
            return 0;
        }

        for (auto [v, l] : edges[cur]) {
            if (visited[v]) {
                continue;
            }

            if (label == -1 || label == l) {
                pq.push({-cnt, {v, l}});
            } else {
                pq.push({-(cnt + 1), {v, l}});
            }
        }
    }

    printf("-1");

    return 0;
}
