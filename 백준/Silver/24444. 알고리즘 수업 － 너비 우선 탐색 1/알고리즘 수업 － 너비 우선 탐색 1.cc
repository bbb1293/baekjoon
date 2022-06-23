#include <bits/stdc++.h>

using namespace std;

int cnt = 1;
int n, m, r;
int order[100001];
vector<int> edges[100001];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;

    while (m--) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        sort(edges[i].begin(), edges[i].end());
    }

    queue<int> q;
    q.push(r);
    order[r] = cnt++;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto v : edges[cur]) {
            if (!order[v]) {
                q.push(v);
                order[v] = cnt++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << order[i] << '\n';
    }

    return 0;
}
