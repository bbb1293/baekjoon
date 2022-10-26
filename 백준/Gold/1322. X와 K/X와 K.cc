#include <bits/stdc++.h>

using namespace std;

long long x, k;
bool exist[64];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld", &x, &k);
    k++;

    int cnt = 0;
    for (int i = 0; i < 32; i++) {
        if (x & (1ll << i)) {
            exist[i] = true;
            cnt++;
        }
    }

    long long ret = 0;
    for (int i = 63; i >= 0; i--) {
        if (exist[i]) {
            cnt--;
            continue;
        }

        int cur_i = i - cnt;
        if (k > (1ll << cur_i)) {
            ret += (1ll << i);
            k -= (1ll << cur_i);
        }
    }

    printf("%lld", ret);

    return 0;
}