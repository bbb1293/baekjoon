#include <bits/stdc++.h>

using namespace std;

int n, m;
int t[10000];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    sort(t, t + n);

    priority_queue<int> pq;
    while (m--) {
        pq.push(0);
    }

    for (int i = n - 1; i >= 0; i--) {
        int cur = t[i];

        int cur_t = -pq.top();
        pq.pop();

        pq.push(-(cur_t + cur));
    }

    int ret = 0;
    while (!pq.empty()) {
        ret = max(ret, -pq.top());
        pq.pop();
    }

    printf("%d", ret);

    return 0;
}
