#include <bits/stdc++.h>

using namespace std;

int n, k;
map<int, int> m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    m[0] = 1;

    int sum = 0;
    long long ret = 0;
    while (n--) {
        int tmp;
        scanf("%d", &tmp);

        sum += tmp;

        if (m.count(sum - k)) {
            ret += m[sum - k];
        }

        m[sum]++;
    }

    printf("%lld", ret);

    return 0;
}