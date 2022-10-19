#include <bits/stdc++.h>

using namespace std;

int c, d, v;
pair<int, int> cat[500], dog[500];
int p[500];
bool visited[500];
vector<int> edges[500];

bool kuhn(int cur) {
    if (visited[cur]) {
        return false;
    }
    visited[cur] = true;

    for (auto v : edges[cur]) {
        if (p[v] == -1 || kuhn(p[v])) {
            p[v] = cur;
            return true;
        }
    }

    return false;
}

int match_bipartite() {
    memset(p, -1, sizeof(p));

    int ret = 0;
    for (int i = 0; i < c; i++) {
        memset(visited, 0, sizeof(visited));

        if (kuhn(i)) {
            ret++;
        }
    }

    return v - ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &c, &d, &v);
        c = 0;
        d = 0;

        for (int i = 0; i < v; i++) {
            char c1, c2;
            int a1, a2;

            scanf(" %c%d %c%d", &c1, &a1, &c2, &a2);

            if (c1 == 'C') {
                cat[c++] = {a1, a2};
            } else {
                dog[d++] = {a1, a2};
            }
        }

        for (int i = 0; i < c; i++) {
            edges[i].clear();

            for (int j = 0; j < d; j++) {
                if (cat[i].first == dog[j].second ||
                    cat[i].second == dog[j].first) {
                    edges[i].push_back(j);
                }
            }
        }

        printf("%d\n", match_bipartite());
    }

    return 0;
}