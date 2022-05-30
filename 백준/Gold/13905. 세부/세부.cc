#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
int s, e;
vector<pair<int, int> > edges[MAXN + 1];
bool visited[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    scanf("%d %d", &s, &e);

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    priority_queue<pair<int, int> > pq;
    pq.push({1e6, s});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;

        if (cur == e) {
            printf("%d", cost);
            return 0;
        }

        for (auto [v, c] : edges[cur]) {
            if (!visited[v]) {
                pq.push({min(c, cost), v});
            }
        }
    }

    printf("0");

    return 0;
}
