#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int m, t, n;
int cur_t;
queue<pair<int, int> > q[2];
int ret[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &m, &t, &n);

    for (int i = 0; i < n; i++) {
        int tmp;
        char op[6];

        scanf("%d %s", &tmp, op);

        if (op[0] == 'l') {
            q[0].push({tmp, i});
        } else {
            q[1].push({tmp, i});
        }
    }

    int turn = 0;
    while (!q[0].empty() || !q[1].empty()) {
        if (q[turn].empty()) {
            cur_t = max(cur_t + t,
                        q[turn ^ 1].front().first + t);
            turn ^= 1;
        } else {
            if (q[turn].front().first > cur_t &&
                !q[turn ^ 1].empty() &&
                q[turn].front().first >
                    q[turn ^ 1].front().first) {
                cur_t = max(cur_t + t,
                            q[turn ^ 1].front().first + t);
                turn ^= 1;
                continue;
            }

            cur_t = max(cur_t, q[turn].front().first);

            int cnt = 0;
            while (cnt < m && !q[turn].empty() &&
                   q[turn].front().first <= cur_t) {
                cnt++;
                ret[q[turn].front().second] = cur_t + t;
                q[turn].pop();
            }

            turn ^= 1;
            cur_t += t;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ret[i]);
    }

    return 0;
}