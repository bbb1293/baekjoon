#include <bits/stdc++.h>

using namespace std;

int n, m;
char c_who[] = {'A', 'B'};
char c_op[2][6] = {"BLOCK", "CHAIN"};
set<int> s;

struct State {
    int who, op, num, next;

    State() { next = -1; }

    State(int _who, int _op, int _num, int _next) {
        who = _who;
        op = _op;
        num = _num;
        next = _next;
    }
};

vector<State> ret;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= 2 * n; i++) {
        s.insert(i);
    }

    bool possible = false, never = false;
    int num;
    char who, operation[10];

    for (int i = 0; i < m; i++) {
        scanf(" %c %s %d", &who, &operation, &num);

        if (!ret.empty()) {
            ret.back().next = i;
        }

        if (s.count(num) == 0) {
            never = true;
        }

        ret.emplace_back(State(who - 'A', 0, num, -1));
        s.erase(num);

        if (num == 1) {
            possible = true;
        }
    }

    if (never || !possible || ret[0].who == 1) {
        printf("NO");
        return 0;
    }

    bool check = false;

    int cur = 0;
    while (ret[cur].next != -1) {
        int next_idx = ret[cur].next;

        if (ret[cur].who == ret[next_idx].who) {
            if (ret[cur].num == 1) {
                check = true;
            } else {
                auto it = s.upper_bound(ret[cur].num);

                if (it == s.end()) {
                    possible = false;
                    break;
                }

                int next_num = *it;
                int next_who = (ret[cur].who + 1) % 2;
                s.erase(it);

                ret[cur].next = ret.size();
                ret.emplace_back(State(next_who, 1, next_num, next_idx));
            }
        }

        cur = next_idx;
    }

    if (ret[cur].who == ret[0].who) {
        if (ret[cur].num == 1) {
            check = true;
        } else {
            auto it = s.upper_bound(ret[cur].num);

            if (it == s.end()) {
                possible = false;
            } else {
                int next_num = *it;
                s.erase(it);

                ret[cur].next = ret.size();
                ret.emplace_back(State(1, 1, next_num, -1));
            }
        }
    }

    if (check && s.empty()) {
        possible = false;
    }

    if (!possible) {
        printf("NO");
        return 0;
    }

    printf("YES\n");
    cur = 0;
    while (cur != -1) {
        printf("%c %s %d\n", c_who[ret[cur].who], c_op[ret[cur].op],
               ret[cur].num);

        int next_who = (ret[cur].who + 1) % 2;
        if (ret[cur].num == 1) {
            for (auto num : s) {
                printf("%c %s %d\n", c_who[next_who], c_op[1], num);
                next_who = (next_who + 1) % 2;
            }
        }

        cur = ret[cur].next;
    }

    return 0;
}