#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m, k;
priority_queue<pair<long long, int> > all_pq;
priority_queue<long long> pq[MAXN + 1];
vector<pair<int, int> > edges[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        edges[a].push_back({b, c});
    }

    pq[1].push(0);
    all_pq.push({0, 1});

    while (!all_pq.empty()) {
        auto [cost, cur] = all_pq.top();
        all_pq.pop();

        for (auto [v, c] : edges[cur]) {
            if (pq[v].size() == k) {
                if (pq[v].top() > c - cost) {
                    pq[v].pop();
                    pq[v].push(c - cost);
                    all_pq.push({cost - c, v});
                }
            } else {
                pq[v].push(c - cost);
                all_pq.push({cost - c, v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (pq[i].size() != k) {
            printf("-1\n");
        } else {
            printf("%lld\n", pq[i].top());
        }
    }

    return 0;
}
