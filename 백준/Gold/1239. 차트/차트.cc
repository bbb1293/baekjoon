#include <bits/stdc++.h>

using namespace std;

int n;
int num[8];
bool used[8];

int max_cnt(vector<int> &order) {
    if (order.size() == n) {
        int ret = 0, l = 0, r = 100, r_idx = 0;
        for (int i = 0; i < n; i++) {
            l += num[order[i]];

            if (l > 50) {
                break;
            } else {
                while (r_idx < n && l + r > 50) {
                    r -= num[order[r_idx++]];
                }

                if (l + r == 50) {
                    ret++;
                }
            }
        }
        return ret;
    }

    int ret = 0;

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            order.push_back(i);

            ret = max(ret, max_cnt(order));

            order.pop_back();
            used[i] = false;
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    vector<int> order;
    printf("%d", max_cnt(order));

    return 0;
}
