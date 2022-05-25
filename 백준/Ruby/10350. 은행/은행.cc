#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n;
long long k[2 * MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    long long sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &k[i]);
        k[n + i] = k[i];
        sum += k[i];
    }

    long long ret = 0;
    for (int i = 0; i < n; i++) {
        long long cur = 0;
        for (int j = i; j < i + n; j++) {
            cur += k[j];

            if (cur < 0) {
                ret += ((-cur -1) / sum);
                ret++;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}
