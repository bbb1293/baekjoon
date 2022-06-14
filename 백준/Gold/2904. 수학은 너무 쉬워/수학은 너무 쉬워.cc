#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100, MAXM = 1e6;
int n;
int num[MAXN], cnt[MAXN];
bool non_prime[MAXM + 1];
vector<int> primes;

void set_prime() {
    primes.push_back(2);

    for (int i = 3; i <= MAXM; i += 2) {
        if (!non_prime[i]) {
            primes.push_back(i);

            for (int j = i + i; j <= MAXM; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int ret1 = 1, ret2 = 0;

    for (auto p : primes) {
        int sum_cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt[i] = 0;

            while (!(num[i] % p)) {
                num[i] /= p;
                cnt[i]++;
                sum_cnt++;
            }
        }

        sum_cnt /= n;

        for (int i = 0; i < n; i++) {
            if (cnt[i] < sum_cnt) {
                ret2 += (sum_cnt - cnt[i]);
            }
        }

        while (sum_cnt--) {
            ret1 *= p;
        }
    }

    printf("%d %d\n", ret1, ret2);

    return 0;
}
