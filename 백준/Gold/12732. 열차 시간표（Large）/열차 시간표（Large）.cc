#include <bits/stdc++.h>

using namespace std;

struct State {
    int from, to, idx;

    const bool operator<(const State& a) const {
        return from < a.from;
    }
};

int turn_t, na, nb;
int ret[2];
char from[6], to[6];
State ab[200];
bool used[200];

int convert_min(char cur_t[6]) {
    int h = (cur_t[0] - '0') * 10 + cur_t[1] - '0';
    int m = (cur_t[3] - '0') * 10 + cur_t[4] - '0';

    return h * 60 + m;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for (int test_case = 0; test_case < t; test_case++) {
        memset(used, 0, sizeof(used));

        scanf("%d", &turn_t);
        scanf("%d %d", &na, &nb);

        for (int i = 0; i < na; i++) {
            scanf(" %s %s ", from, to);
            ab[i] = {convert_min(from), convert_min(to), 0};
        }

        for (int i = 0; i < nb; i++) {
            scanf(" %s %s ", from, to);
            ab[i + na] = {convert_min(from),
                          convert_min(to), 1};
        }

        int n = na + nb;

        sort(ab, ab + n);

        ret[0] = ret[1] = 0;

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                ret[ab[i].idx]++;

                int j = i, idx = -1, cur = 0;
                while (j < n) {
                    if (!used[j] && ab[j].idx != idx &&
                        cur <= ab[j].from) {
                        used[j] = true;
                        cur = ab[j].to + turn_t;
                        idx = ab[j].idx;
                    }
                    j++;
                }
            }
        }

        printf("Case #%d: %d %d\n", test_case + 1, ret[0],
               ret[1]);
    }

    return 0;
}