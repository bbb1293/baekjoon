#include <bits/stdc++.h>

using namespace std;

struct State {
    int u, v, c, kind;

    const bool operator<(const State &a) const { return c > a.c; }
};

const int MAXN = 1e5;
int n, m;
int p[MAXN + 1];
bool done[MAXN + 1];
priority_queue<State> pq;

void init() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int get_p(int cur) {
    while (cur != p[cur]) {
        p[cur] = p[p[cur]];
        cur = p[cur];
    }

    return cur;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    init();

    while (m--) {
        int c, a;
        scanf("%d %d", &c, &a);
        pq.push({c, -1, a, 0});
    }

    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);
        pq.push({i, (i % n) + 1, c, 1});
    }

    long long ret = 0;
    while (!pq.empty()) {
        auto [u, v, c, kind] = pq.top();
        pq.pop();

        if (kind == 0) {
            int u_p = get_p(u);

            if (!done[u_p]) {
                done[u_p] = true;
                ret += c;
            }
        } else {
            int u_p = get_p(u);
            int v_p = get_p(v);

            if (u_p == v_p) {
                continue;
            }

            if (done[u_p]) {
                if (!done[v_p]) {
                    p[v_p] = u_p;
                    ret += c;
                }
            } else {
                p[u_p] = v_p;
                ret += c;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}