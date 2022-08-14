#include <bits/stdc++.h>

using namespace std;

struct State {
    int t, c;

    const bool operator<(const State &a) const {
        if (t != a.t) {
            return a.t < t;
        }

        return c > a.c;
    }
};

int n;
priority_queue<State> pq;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    while (n--) {
        int idx, s, e;
        scanf("%d %d %d", &idx, &s, &e);

        pq.push({s, 1});
        pq.push({e, -1});
    }

    int ret = 1, cnt = 0;
    while (!pq.empty()) {
        auto [t, c] = pq.top();
        pq.pop();

        if (c == 1) {
            cnt++;
            ret = max(ret, cnt);
        } else {
            cnt--;
        }
    }

    printf("%d", ret);

    return 0;
}
