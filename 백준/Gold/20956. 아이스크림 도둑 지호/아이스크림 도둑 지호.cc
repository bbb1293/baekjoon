#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> a[100000];
deque<pair<int, int> > dq;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].first = -a[i].first;
        a[i].second = i + 1;
    }

    sort(a, a + n);

    bool flg = false;

    dq.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i - 1].first != a[i].first) {
            while (!dq.empty() && m) {
                int ammount;
                if (flg) {
                    printf("%d\n", dq.back().second);
                    ammount = (-dq.back().first) % 7;
                    dq.pop_back();

                } else {
                    printf("%d\n", dq.front().second);
                    ammount = (-dq.front().first) % 7;
                    dq.pop_front();
                }

                if (!ammount) {
                    flg ^= 1;
                }

                m--;
            }
        }
        dq.push_back(a[i]);
    }

    while (m--) {
        int ammount;
        if (flg) {
            printf("%d\n", dq.back().second);
            ammount = (-dq.back().first) % 7;
            dq.pop_back();

        } else {
            printf("%d\n", dq.front().second);
            ammount = (-dq.front().first) % 7;
            dq.pop_front();
        }

        if (!ammount) {
            flg ^= 1;
        }
    }

    return 0;
}
