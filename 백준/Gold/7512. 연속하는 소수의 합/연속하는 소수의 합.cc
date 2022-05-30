#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7;
int m, n[10];
vector<int> primes;
bool non_prime[MAXN];
int last_idx[10], sum[10];

bool is_valid() {
    int ret = sum[0];

    for (int i = 1; i < m; i++) {
        if (ret != sum[i]) {
            return false;
        }
    }

    return true;
}

void init() {
    for (int i = 0; i < m; i++) {
        sum[i] = 0;

        for (int j = 0; j < n[i]; j++) {
            sum[i] += primes[j];
        }
        last_idx[i] = n[i] - 1;

        while (non_prime[sum[i]]) {
            last_idx[i]++;
            sum[i] = sum[i] - primes[last_idx[i] - n[i]] + primes[last_idx[i]];
        }
    }
}

void set_next() {
    int max_sum = 0;
    for (int i = 0; i < m; i++) {
        max_sum = max(max_sum, sum[i]);
    }

    for (int i = 0; i < m; i++) {
        while (sum[i] < max_sum || non_prime[sum[i]]) {
            last_idx[i]++;
            sum[i] = sum[i] - primes[last_idx[i] - n[i]] + primes[last_idx[i]];
        }
    }
}

void set_prime() {
    primes.push_back(2);
    for (int i = 4; i < MAXN; i += 2) {
        non_prime[i] = true;
    }

    for (int i = 3; i < MAXN; i += 2) {
        if (!non_prime[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                non_prime[j] = true;
            }
            primes.push_back(i);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &m);

        for (int j = 0; j < m; j++) {
            scanf("%d", &n[j]);
        }

        init();

        while (!is_valid()) {
            set_next();
        }

        printf("Scenario %d:\n%d\n\n", i, sum[0]);
    }

    return 0;
}
