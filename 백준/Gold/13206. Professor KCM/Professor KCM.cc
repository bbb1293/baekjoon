#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n;
int cnt[1001], dividor[1001];

void set_primes() {
    dividor[2] = 2;
    for (int i = 4; i < 1001; i += 2) {
        dividor[i] = 2;
    }

    for (int i = 3; i < 1001; i += 2) {
        if (!dividor[i]) {
            dividor[i] = i;
            for (int j = i + i; j < 1001; j += i) {
                if (!dividor[j]) {
                    dividor[j] = i;
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    set_primes();

    while (t--) {
        scanf("%d", &n);
        while (n--) {
            int tmp;
            scanf("%d", &tmp);

            int cur = 1, cur_cnt = 0;
            while (tmp != 1) {
                if (dividor[tmp] != cur) {
                    cnt[cur] = max(cnt[cur], cur_cnt);
                    cur = dividor[tmp];
                    cur_cnt = 0;
                }
                cur_cnt++;
                tmp /= dividor[tmp];
            }

            cnt[cur] = max(cnt[cur], cur_cnt);
        }

        long long ret = 1;
        for (int i = 2; i < 1001; i++) {
            while (cnt[i]) {
                ret *= i;
                ret %= MOD;
                cnt[i]--;
            }
        }

        printf("%lld\n", ret);
    }

    return 0;
}
