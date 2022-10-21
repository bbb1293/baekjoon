#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n, q;
long long fenwick[MAXN + 1];

void update(int target, int num) {
    for (; target <= n; target = (target | (target + 1))) {
        fenwick[target] += num;
    }
}

long long get_sum(int to) {
    long long sum = 0;
    for (; to >= 0; to = (to & (to + 1)) - 1) {
        sum += fenwick[to];
    }

    return sum;
}

long long get_query_sum(int from, int to) {
    return get_sum(to) - get_sum(from - 1);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &q);

    while (q--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);

        if (op == 1) {
            update(x, y);
        } else {
            printf("%lld\n", get_query_sum(x, y));
        }
    }

    return 0;
}