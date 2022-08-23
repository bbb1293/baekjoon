#include <bits/stdc++.h>

using namespace std;

struct State {
    int prev, cur;
};

const int MAXN = 5e5;
int n;
char s[MAXN + 1], ret[MAXN + 1];
vector<int> edges[MAXN];

void solve() {
    queue<State> q;
    ret[0] = s[0];

    for (auto v : edges[0]) {
        q.push({0, v});
    }

    int idx = 1;
    while (!q.empty()) {
        int q_size = q.size();

        while (q_size--) {
            auto [prev, cur] = q.front();
            q.pop();

            if (ret[idx - 1] != s[prev] || ret[idx] > s[cur]) {
                continue;
            }

            ret[idx] = s[cur];
            for (auto v : edges[cur]) {
                if (v != prev) {
                    q.push({cur, v});
                }
            }
        }
        idx++;
    }

    printf("%s", ret);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf(" %s", s);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    solve();

    return 0;
}
