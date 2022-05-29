#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
long long p, a;
bool non_prime[MAXN];
vector<long long> prime;

void init_prime() {
    non_prime[0] = non_prime[1] = true;

    for (int i = 2; i < MAXN; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                non_prime[j] = true;
            }
            prime.push_back(i);
        }
    }
}

bool is_prime(long long p) {
    if (p < MAXN) {
        return !non_prime[(int)p];
    }

    for (auto pp : prime) {
        if (pp * pp > p) {
            break;
        }

        if ((p % pp) == 0) {
            return false;
        }
    }

    return true;
}

long long get_power(long long a, long long k) {
    if (k == 1) {
        return a;
    }

    long long tmp = get_power(a, k / 2);

    if (k & 1) {
        return (((tmp * a) % p) * tmp) % p;
    } else {
        return ((tmp * tmp) % p);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    init_prime();

    while (true) {
        scanf("%lld %lld", &p, &a);

        if (p == 0) {
            break;
        }

        if (!is_prime(p) && (get_power(a, p) == a)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}
