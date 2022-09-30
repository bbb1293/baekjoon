#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    long long max_num = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        scanf("%lld", &a);

        sum += a;
        max_num = max(max_num, a);
    }

    if ((sum + 1) / 2 < max_num) {
        printf("%lld", (sum - max_num) * 2 + 1);
    } else {
        printf("%lld", sum);
    }

    return 0;
}