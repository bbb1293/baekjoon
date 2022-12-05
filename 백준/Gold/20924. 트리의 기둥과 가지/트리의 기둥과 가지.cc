#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, r;
vector<pair<int, int> > edges[MAXN + 1];
int ret1, ret2;

int get_longest(int p, int cur) {
    int ret = 0;
    for (auto [u, c] : edges[cur]) {
        if (u != p) {
            ret = max(ret, c + get_longest(cur, u));
        }
    }

    return ret;
}

void find_pillar(int p, int cur) {
    int cnt = edges[cur].size();
    if (cur != r) {
        cnt--;
    }

    if (cnt == 1) {
        for (auto [u, c] : edges[cur]) {
            if (u != p) {
                ret1 += c;
                find_pillar(cur, u);
            }
        }
    } else if (cnt > 1) {
        ret2 = get_longest(p, cur);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &r);

    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);

        edges[u].push_back({v, c});
        edges[v].push_back({u, c});
    }

    find_pillar(-1, r);

    printf("%d %d", ret1, ret2);

    return 0;
}