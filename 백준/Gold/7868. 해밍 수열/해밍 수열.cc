#include <bits/stdc++.h>

using namespace std;

const long long BOUND = 1e18;
long long p[3], k;

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 3; i++) {
        scanf("%lld", &p[i]);
    }
    scanf("%lld", &k);
    k++;

    priority_queue<long long> pq;
    pq.push(-1);

    long long prev = -1;
    while (!pq.empty()) {
        long long cur = -pq.top();
        pq.pop();

        if (cur == prev) {
            continue;
        }

        prev = cur;
        k--;

        if (k == 0) {
            printf("%lld", cur);
            return 0;
        }

        for (int i = 0; i < 3; i++) {
            if (cur <= BOUND / p[i]) {
                pq.push(-cur * p[i]);
            }
        }
    }

    return 0;
}