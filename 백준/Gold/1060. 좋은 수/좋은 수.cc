#include <bits/stdc++.h>

using namespace std;

struct State {
    long long cur, left, right;

    const bool operator<(const State &a) const {
        long long score = (cur - left + 1) * (right - cur + 1);
        long long a_score = (a.cur - a.left + 1) * (a.right - a.cur + 1);

        if (score == a_score) {
            return cur > a.cur;
        }

        return score > a_score;
    }
};

int l, n;
int s[50];
set<int> used;
vector<int> ret;
priority_queue<State> pq;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &l);

    for (int i = 0; i < l; i++) {
        scanf("%d", &s[i]);
    }
    sort(s, s + l);

    pq.push({s[0], s[0], s[0]});
    used.insert(s[0]);
    if (s[0] != 1) {
        pq.push({1, 1, s[0] - 1});
        used.insert(1);

        if (s[0] != 2) {
            pq.push({s[0] - 1, 1, s[0] - 1});
            used.insert(s[0] - 1);
        }
    }

    for (int i = 1; i < l; i++) {
        pq.push({s[i], s[i], s[i]});
        used.insert(s[i]);

        if (s[i - 1] + 1 != s[i]) {
            pq.push({s[i - 1] + 1, s[i - 1] + 1, s[i] - 1});
            used.insert(s[i - 1] + 1);

            if (s[i - 1] + 1 != s[i] - 1) {
                pq.push({s[i] - 1, s[i - 1] + 1, s[i] - 1});
                used.insert(s[i] - 1);
            }
        }
    }

    scanf("%d", &n);

    while (!pq.empty() && ret.size() < n) {
        auto [cur, left, right] = pq.top();
        pq.pop();

        ret.push_back(cur);

        if (left <= cur - 1 && used.count(cur - 1) == 0) {
            used.insert(cur - 1);
            pq.push({cur - 1, left, right});
        }

        if (cur + 1 <= right && used.count(cur + 1) == 0) {
            used.insert(cur + 1);
            pq.push({cur + 1, left, right});
        }
    }

    int rest = n - ret.size();
    for (int i = 0; i < rest; i++) {
        ret.push_back(s[l - 1] + i + 1);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ret[i]);
    }

    return 0;
}
