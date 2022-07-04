#include <bits/stdc++.h>

using namespace std;

struct PS {
    int p, s;

    bool operator<(PS &a) { return (p + s) < (a.p + a.s); }
};

const int MAXN = 1e3, MAXM = 1e5 + 1e3;
int n;
PS ps[MAXN];
bool possible[MAXM + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for (int test_case = 1; test_case <= t; test_case++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &ps[i].p, &ps[i].s);
        }
        sort(ps, ps + n);

        memset(possible, 0, sizeof(possible));
        possible[0] = true;

        int cur_limit = 0, limit = ps[n - 1].p + ps[n - 1].s;
        for (int i = 0; i < n; i++) {
            cur_limit = min(cur_limit + ps[i].s, limit);
            for (int j = cur_limit; j >= ps[i].s; j--) {
                if (j - ps[i].s <= ps[i].p && possible[j - ps[i].s]) {
                    possible[j] = true;
                }
            }
        }

        for (int j = cur_limit; j >= 0; j--) {
            if (possible[j]) {
                printf("Case #%d: %d\n", test_case, j);
                break;
            }
        }
    }

    return 0;
}
