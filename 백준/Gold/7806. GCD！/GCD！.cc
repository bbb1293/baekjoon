#include <bits/stdc++.h>

using namespace std;

int n, k;
int non_prime[100000];
vector<int> prime;

void set_prime() {
    prime.push_back(2);
    for (int i = 3; i < 100000; i += 2) {
        if (!non_prime[i]) {
            prime.push_back(i);

            for (int j = i + i; j < 100000; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int get_power(int a, int k) {
    if (k == 0) {
        return 1;
    } else if (k == 1) {
        return a;
    }

    int tmp = get_power(a, k / 2);
    tmp *= tmp;

    if (k & 1) {
        return tmp * a;
    }
    return tmp;
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    while (scanf("%d %d", &n, &k) > 0) {
        if (k <= n) {
            printf("%d\n", k);
        } else {
            int ret = 1;
            for (auto p : prime) {
                int cnt = 0;
                while (!(k % p)) {
                    k /= p;
                    cnt++;
                }

                for (int i = p; i <= n && cnt; i *= p) {
                    int cur = min(n / i, cnt);

                    ret *= get_power(p, cur);
                    cnt -= cur;
                }
            }

            if (k <= n) {
                ret *= k;
            }

            printf("%d\n", ret);
        }
    }

    return 0;
}